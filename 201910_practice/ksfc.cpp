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
int val[maxn];
vector<int> G[maxn];
ll dp[maxn][3];
void dfs(int u,int fa)
{
	dp[u][0]=0;
	dp[u][1]=val[u];
	if(G[u].size()!=1) dp[u][2]=0;
	for(auto &v:G[u])if(v!=fa)
		dfs(v,u);
	bool ltd=0;
	ll mx=-0x3f3f3f3f3f3f3f3f;
	for(auto &v:G[u])if(v!=fa)
	{
		dp[u][0]+=max(dp[v][0],dp[v][2]);
		dp[u][1]+=max({dp[v][0]+val[v],dp[v][1],dp[v][2]});
		if(dp[v][1]>=dp[v][2]&&dp[v][1]>=dp[v][0]) ltd=1;
		dp[u][2]+=max({dp[v][0],dp[v][1],dp[v][2]});
		mx=max(mx,dp[v][1]-max(dp[v][2],dp[v][0]));
	}
	if(mx!=-0x3f3f3f3f3f3f3f3f)
	{
		if(!ltd)
			dp[u][2]=dp[u][2]+mx+val[u];
		else dp[u][2]+=val[u];
	}
	//dbg(u,dp[u][0],dp[u][1],dp[u][2]);
}
int main()
{
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,-0x3f,sizeof(dp));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<=n;i++) scanf("%d",&val[i]);
		for(int i=1,u,v;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,-1);
		printf("Case #%d: %lld\n",++kas,max({dp[1][0],dp[1][1],dp[1][2]}));
	}
}
