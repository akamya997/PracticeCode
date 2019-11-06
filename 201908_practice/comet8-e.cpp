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
const int maxn=5e6+7;
int tot;
int prime[maxn];
bool vis[maxn];
int phi[maxn];
void db()
{
	phi[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!vis[i])
		{
			prime[tot++]=i;
			phi[i]=i-1;
		}
		for(int j=0;j<tot;j++)
		{
			if(i*prime[j]>=maxn) break;
			if(i%prime[j]==0)
			{
				vis[i*prime[j]]=1;
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			vis[i*prime[j]]=1;
			phi[i*prime[j]]=phi[i]*phi[prime[j]];
		}
	}
}
int main()
{
	db();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ll n;
		scanf("%lld",&n);
		ll ans=0;
		for(int d=1;d<=sqrt(n);d++)
			ans+=1LL*phi[d]*(n/(1LL*d*d));
		printf("%lld\n",ans);
	}
}
