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
const int mod=1e9+7;
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
const int maxn=1e6+7;
ll fac[maxn];
void db()
{
	fac[0]=1;
	for(int i=1;i<maxn;i++)
		fac[i]=fac[i-1]*i%mod;
}
ll C(int n,int m)
{
	return fac[n]*inv(fac[n-m])%mod*inv(fac[m])%mod;
}
int main()
{
	db();
	int n,m,k;
	cin>>n>>m>>k;
	ll ans=0;
	ll cur=1;
	for(int t=0;t<=m+k;t++)
	{
		ans=(ans+cur*C(t+n-1,n-1)%mod*quick(3,m+k-t)%mod)%mod;
		cur=cur*2%mod;
		if(t+1>m)
			cur=(cur-C(t,m)+mod)%mod;
		if(t+1>k) cur=(cur-C(t,t-k)+mod)%mod;
	//	dbg(t,ans,cur);
	}
	cout<<ans<<endl;
}
