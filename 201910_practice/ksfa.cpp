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
const int maxn=105;
int dp[maxn][maxn][maxn];
int a[maxn];
int n,k;
int dfs(int u,int t,int v)
{
	if(t>k) return INF;
	if(u==n) return 0;
	if(dp[u][t][v]!=-1) return dp[u][t][v];
	int ret=INF;
	for(int i=1;i<=n;i++)
		ret=min(ret,dfs(u+1,t+(u!=0&&a[v]!=a[i]),i)+(a[i]!=a[u+1]));
	return dp[u][t][v]=ret;
}
int main()
{
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		a[0]=a[1];
		memset(dp,-1,sizeof(dp));
	/*	for(int i=1;i<=n;i++)
			dp[0][0][i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int v=1;v<=n;v++)
			{
				for(int u=1;u<=n;u++)
				{
					for(int j=(a[u]!=a[v]);j<=min(i,k);j++)
						dp[i][j][v]=min(dp[i][j][v],dp[i-1][j-(a[u]!=a[v])][u]+(a[v]!=a[i]));
				}
			}
		}
		int ans=INF;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=k;j++)
				ans=min(ans,dp[n][j][i]);*/
		int ans=dfs(0,0,0);
		printf("Case #%d: %d\n",++kas,ans);
	}
}
