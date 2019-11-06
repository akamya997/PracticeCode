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
const int maxn=1e5+7;
ll s[maxn],l[maxn],v[maxn];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<=n;i++) scanf("%lld",&l[i]);
		for(int i=0;i<=n;i++) scanf("%lld",&s[i]);
		for(int i=0;i<=n;i++) scanf("%lld",&v[i]);
		double pre=0;ll val=0;
		for(int i=n;i>=0;i--)
		{
			double fs=1.0*s[i]/v[i];
			if(fs>pre)
			{
				val=v[i];
				pre=fs;
			}
			if(i)
				pre+=1.0*l[i]/val;
		}
		printf("%.10f\n",pre);
	}
}
