#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int INF=0x3f3f3f3f;
inline ll mul(ll u, ll v, ll p) {
    return (u * v - ll((long double) u * v / p) * p + p) % p;
}
inline ll quick(ll a,ll b,ll mod)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=mul(ret,a,mod);
		a=mul(a,a,mod);
		b>>=1;
	}
	return ret;
}
ll inv(ll a,ll mod){return quick(a,mod-2,mod);}
inline PII fac(ll p)
{
	int cnt2=0,cnt3=0;
	while(p%2==0)
	{
		cnt2++;
		p/=2;
	}
	while(p%3==0)
	{
		cnt3++;
		p/=3;
	}
	return make_pair(cnt2,cnt3);
}
inline bool okg(ll p,ll x)
{
	if((p-1)%2==0&&quick(x,(p-1)/2,p)==1) return false;
	if((p-1)%3==0&&quick(x,(p-1)/3,p)==1) return false;
	return true;
}
ll getg(ll p)
{
	for(int i=2;;i++)if(okg(p,i)) 
		return i;
}
ll getans(ll x,ll g,ll p,PII t)
{
	ll ret=0;
	ll ti=1;
	ll tt=p-1;
	for(int i=0;i<t.first;i++)
	{
		tt/=2;
		if(quick(x,tt,p)!=1)
		{
			x=mul(x,g,p);
			ret+=ti;
		}
		g=mul(g,g,p);
		ti*=2;
	}
	for(int i=0;i<t.second;i++)
	{
		tt/=3;
		if(quick(x,tt,p)!=1)
		{
			x=mul(x,g,p);
			ret+=ti;
			if(quick(x,tt,p)!=1)
			{
				x=mul(x,g,p);
				ret+=ti;
			}
		}
		g=mul(g,mul(g,g,p),p);
		ti*=3;
	}
	return (p-1-ret)%(p-1);
}
ll exgcd(ll a, ll b, ll &x, ll &y) //返回gcd(a,b)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= x * (a / b);
    return d;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		ll p,a,b;
		cin>>p>>a>>b;
		ll _a=a,_b=b;
		PII cur=fac(p-1);
		ll g=getg(p);
		a=getans(a,g,p,cur);
		b=getans(b,g,p,cur);
		dbg(a,b);
		ll x,y;
		ll gcd=exgcd(a,p-1,x,y);
		if(b%gcd!=0) cout<<"-1"<<endl;
		else{
			x=mul(x,b/gcd,(p-1)/gcd);
			x=(x+p-1)%((p-1)/gcd);
			cout<<x<<endl;
		}
	}

}
