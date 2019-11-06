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
struct Edge{
	int to;
	ll w;
};
const int maxn=1e5+7;
const int mod=1e9+7;
int sz[maxn];
ll sum[maxn];
vector<Edge> G[maxn];
void dfs1(int u)
{
	sz[u]=1;
	for(auto &e:G[u])
	{
		int v=e.to;
		sum[v]=sum[u]^e.w;
		dfs1(v);
		sz[u]+=sz[v];
	}
}
ll ans;
map<ll,int> cnt;
int n;
void dfs2(int u)
{
	ans=(ans+1LL*sz[u]*cnt[sum[u]])%mod;
	for(auto& e:G[u])
	{
		int v=e.to;
		cnt[sum[u]]=(1LL*cnt[sum[u]]+n-sz[v]+mod)%mod;
		dfs2(v);
		cnt[sum[u]]=(1LL*cnt[sum[u]]-n+sz[v]+mod)%mod;
	}
	cnt[sum[u]]=(1LL*cnt[sum[u]]+sz[u])%mod;
}
int main()
{
	ans=0;
	scanf("%d",&n);
	for(int i=2,fa;i<=n;i++)
	{
		ll w;
		scanf("%d%lld",&fa,&w);
		G[fa].push_back(Edge {i,w});
	}
	dfs1(1);
	dfs2(1);
	printf("%lld\n",ans);
}
