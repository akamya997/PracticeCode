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
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
ll f(ll b,ll n)
{
	if(b==1) return 0;
	ll ret=0;
	while(n)
	{
		ret+=n%b;
		n/=b;
	}
	return ret;
}
int main()
{
	ll n,s;
	cin>>n>>s;
	ll ans=-1;
	if(n==s) ans=n+1;
	else{
		ll var=sqrt(n);
		for(int i=2;i<=var;i++)
		{
			if(f(i,n)==s)
			{
				ans=i;break;
			}
		}
		if(ans==-1&&n>s)
		{
			for(int p=var;p>0;p--)
			{
				if((n-s)%p==0)
				{
					if(f((n-s)/p+1,n)==s)
					{
						ans=(n-s)/p+1;
						break;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}
