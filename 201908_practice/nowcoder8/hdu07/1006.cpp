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
const ll INF=0x3f3f3f3f3f3f3f3f;
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
vector<int> G[maxn];
int a[maxn],b[maxn];
int val[maxn];
ll dp[maxn][2];
void dfs(int u,int fa=-1)
{
	dp[u][0]=-INF;dp[u][1]=INF;
	for(auto v:G[u])if(v!=fa)
	{
		dfs(v,u);
		dp[u][0]=max(dp[v][1],dp[u][0]);
		dp[u][1]=min(dp[v][0],dp[u][1]);
	}
	if(dp[u][0]!=-INF) dp[u][0]+=val[u];
	else dp[u][0]=val[u];
	if(dp[u][1]!=INF) dp[u][1]+=val[u];
	else dp[u][1]=val[u];
}
ll ans=-INF;
void dfs2(int u,int fa=-1)
{
	multiset<ll> mx,mi;
	ans=max(ans,dp[u][1]);
	for(auto &v:G[u]) mx.insert(dp[v][0]),mi.insert(dp[v][1]);
	for(auto &v:G[u])if(v!=fa)
	{
		ll rmvmx=dp[v][0],rmvmi=dp[v][1];
		ll rmumx=dp[u][0],rmumi=dp[u][1];
		mx.erase(mx.find(dp[v][0]));
		mi.erase(mi.find(dp[v][1]));
		if(!mx.size())
		{
			dp[u][0]=val[u];
			dp[u][1]=val[u];
		}
		else{
			auto it=mi.end();--it;
			dp[u][0]=(*it)+val[u];dp[u][1]=(*mx.begin())+val[u];
		}
		if(G[v].size()==1) dp[v][0]=dp[u][1]+val[v];
		else dp[v][0]=max(dp[v][0]-val[v],dp[u][1])+val[v];
		if(G[v].size()==1) dp[v][1]=dp[u][0]+val[v];
		else dp[v][1]=min(dp[v][1]-val[v],dp[u][0])+val[v];
		mx.insert(rmvmx);
		mi.insert(rmvmi);
		dfs2(v,u);
		dp[v][0]=rmvmx;dp[v][1]=rmvmi;
		dp[u][0]=rmumx,dp[u][1]=rmumi;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<=n;i++) G[i].clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
			val[i]=a[i]-b[i];
		for(int i=1,u,v;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		ans=-INF;
		dfs(1);
		dfs2(1);
		printf("%lld\n",ans);
	}
}
