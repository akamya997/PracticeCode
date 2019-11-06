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
const int maxn=2e5+7;
ll sz[maxn],sum[maxn];
bool vis[maxn];
vector<int> G[maxn];
int col[maxn];
ll ans=0;
ll dfs(int u,int fa=-1)
{
	sz[u]=1;
	ll son=0;
	for(auto& v:G[u])
	{
		if(v==fa) continue;
		ll cur=sum[col[u]];
		sz[u]+=dfs(v,u);
		ll add=sum[col[u]]-cur;
		ans+=(sz[v]-add)*(sz[v]-add-1)/2;
		son+=sz[v]-add;
	}
	sum[col[u]]+=son+1;
	return sz[u];
}
int main()
{
	int n;
	int kas=0;
	while(~scanf("%d",&n))
	{
		int cnt=0;
		ans=0;
		for(int i=1;i<=n;i++) vis[i]=0,sum[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&col[i]);
			if(!vis[col[i]]) cnt++;
			vis[col[i]]=1;
			G[i].clear();
		}
		for(int i=1,u,v;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1);
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]) continue;
			ans+=(n-sum[i])*(n-sum[i]-1)/2;
		}
		printf("Case #%d: %lld\n",++kas,1LL*n*(n-1)/2*cnt-ans);
	}
}
