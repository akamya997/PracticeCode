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
const int maxn=30;
int maze[maxn][maxn];
ll ans=0;
int n;
void dfs(int u,ll st,ll sum,int cnt)
{
	if(cnt>n||u-1-cnt>n||sum<=ans) return;
	if(u==2*n+1)
	{
		ans=max(ans,sum);
		return;
	}
	ll s1=0,s2=0;
	for(int i=1;i<u;i++)
	{
		if(st&(1<<i)) s1+=maze[u][i];
		else s2+=maze[u][i];
	}
	dfs(u+1,st,sum-s2,cnt);
	dfs(u+1,st|(1<<u),sum-s1,cnt+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
		for(int j=1;j<=2*n;j++)
			scanf("%d",&maze[i][j]);
	ll tot=0;
	for(int i=1;i<=2*n;i++)
	{
		for(int j=1;j<i;j++)
			tot+=maze[i][j];
	}
	dfs(1,0,tot,0);
	printf("%lld\n",ans);
}
