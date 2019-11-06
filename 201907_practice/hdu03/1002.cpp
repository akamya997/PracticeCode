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
const int maxn=1e5+7;
ll inv(ll a){return quick(a,mod-2);}
int cnt[maxn],ed[maxn];
bool vis[maxn];
vector<int> G[maxn];
int dfs(int u)
{
	if(vis[u]) return;
	vis[u]=1;
	cnt[u]=1;
	ed[u]=u;
	bool same=1;
	for(auto v:G[u])
	{
		dfs(v);
		if(G[u].size()==1)
		{
			cnt[u]+=cnt[v];
			ed[u]=ed[v];
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++) G[i].clear(),vis[i]=0,ed[i]=-1;
		for(int i=0,u,v;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
		}
		for(int i=1;i<=n;i++)
			dfs(i);
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			int ans=0;
			if(ed[u]==ed[v])
				ans=max(cnt[u],cnt[v]);
			else
				ans=cnt[u]+cnt[v];
			printf("%d\n",ans);
		}

	}
}
