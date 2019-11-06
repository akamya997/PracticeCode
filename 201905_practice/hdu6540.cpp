#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=5005;
const int mod=1e9+7;
int dp[maxn][maxn];

vector<int> G[maxn];

int len[maxn];
bool key[maxn];

int n,m,k;
int pre[maxn][maxn];
void dfs(int u,int fa=-1)
{
	for(auto &v:G[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		len[u]=max(len[u],len[v]+1);
		vector<int> g(n+2,0);
		for(int i=0;i<=len[u]&&i<=k;i++)
			g[i]=1LL*pre[v][min(i,k-i)-1]*dp[u][i]%mod;
		for(int j=0;j<=k;j++)
			g[j+1]=(g[j+1]+dp[v][j])%mod;
		for(int i=1;i<=k;i++)
			dp[u][i]=(dp[u][i]+g[i])%mod;
	}
	if(key[u])
	{
		for(int i=0;i<=k;i++)
			dp[u][i]=dp[u][i]*2%mod;
		dp[u][0]+=1;
		pre[u][0]=dp[u][0];
		for(int i=1;i<=k;i++)
			pre[u][i]=(pre[u][i-1]+dp[u][i])%mod;
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0;i<m;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		key[tmp]=1;
	}
	dfs(1);
	ll ans=0;
	for(int i=0;i<=k;i++)
		ans=(ans+dp[1][i])%mod;
	printf("%lld\n",ans);
}
