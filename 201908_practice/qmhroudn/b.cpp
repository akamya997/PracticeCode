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
const int maxn=2005;
int dp[maxn][1<<10];
map<PII,int> ban;
int main()
{
	int n,e,k;
	scanf("%d%d%d",&n,&e,&k);
	for(int i=0,u,v;i<k;i++)
	{
		scanf("%d%d",&u,&v);
		ban[make_pair(u,v)]=1;
	}
	int tar=e*2+1;
	int st=0;
	for(int i=0;i<=e;i++)
		st|=(1<<i);
	dp[0][st]=1;
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		for(int S=0;S<(1<<tar);S++)
		{
			if(dp[i][S]==-1) continue;
			for(int j=-e;j<=e;j++)
			{
				if(i+1+j>n) break;
				if(i+1+j<=0) continue;
				int v=i+1+j;
				if(ban.count(make_pair(i+1,v))) continue;
				int nxt=S>>1;
				int delta=v-(i+1-e);
				if(nxt>>delta&1) continue;
				dp[i+1][nxt|(1<<delta)]=(dp[i+1][nxt|(1<<delta)]+dp[i][S])%mod;
			}
		}
	}
	for(int S=0;S<(1<<tar);S++)
		ans=(ans+dp[n][S])%mod;
	printf("%lld\n",ans);

}
