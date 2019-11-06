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
const int maxn=2e5+7;
ll fac[maxn];
void db()
{
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
}
ll C(int n,int m)
{
	return fac[n]*inv(fac[n-m])%mod*inv(fac[m])%mod;
}
int main()
{
	db();
	int h,w,a,b;
	cin>>h>>w>>a>>b;
	ll ans=C(h+w-2,w-1);
	for(int i=1;i<=b;i++)
		ans=(ans-C(h-a+i-2,i-1)*C(w-i+a-1,a-1)%mod+mod)%mod;
	cout<<ans<<endl;
}
