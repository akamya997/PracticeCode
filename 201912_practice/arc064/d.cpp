#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
const int maxn=1e5+7;
ll kd[maxn];
int main()
{
	int n,k;
	cin>>n>>k;
	vi fac;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			fac.push_back(i);
			if(i*i!=n) fac.push_back(n/i);
		}
	}
	sort(fac.begin(),fac.end());
	ll ans=0;
	for(int i=0;i<fac.size();i++)
	{
		int c=fac[i];
		if(n&1)
			kd[i]=quick(k,c/2+1);
		else{
			if(n/2%c==0)
				kd[i]=quick(k,c);
			else kd[i]=quick(k,c/2);
		}
		for(int j=0;j<i;j++)
			if(fac[i]%fac[j]==0) kd[i]=(kd[i]-kd[j]+mod)%mod;
		ans+=kd[i]*c%mod;
		ans%=mod;
	//	dbg(i,kd[i],c,ans);
	}
	cout<<ans<<endl;
}
