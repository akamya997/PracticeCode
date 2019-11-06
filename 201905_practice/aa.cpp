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
const int maxn=1e5+7;
char str[maxn];
struct Edge{
	int to,w;
};
struct E{
	int u,v,w;
}edge[maxn*2];
int n,b;
vector<Edge> G[maxn],tr[maxn];
int scc;
int dfn[maxn],low[maxn],bel[maxn];
int ti;
stack<int> st;
void dfs(int u,int fa)
{
	dfn[u]=low[u]=++ti;
	st.push(u);
	int k=0;
	for(auto &e:G[u])
	{
		int v=e.to;
		if(v==fa&&!k++) continue;
		if(!dfn[v])
		{
			dfs(v,u);
			low[u]=min(low[u],low[v]);
		}
		else if(!bel[u]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		scc++;
		while(1)
		{
			int t=st.top();
			st.pop();
			bel[t]=scc;
			if(u==t) break;
		}
	}
}
void SCC()
{
	memset(dfn,0,sizeof(dfn));
	memset(bel,0,sizeof(bel));
	scc=0;
	ti=0;
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
			dfs(i,-1);
	}
	for(int i=0;i<b;i++)
	{
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		if(bel[u]!=bel[v])
		{
			u=bel[u],v=bel[v];
			tr[u].push_back(Edge {v,w});
			tr[v].push_back(Edge {u,w});
		}
	}
}
ll ans=0;
int cnta[maxn],cnth[maxn];
int solve(int u,int fa=-1)
{
	int cnt=cnta[u]-cnth[u];
	for(auto e:tr[u])
	{
		int v=e.to;
		if(v==fa) continue;
		int son=solve(v,u);
		ans+=abs(son)*e.w;
		cnt+=son;
	}
	return cnt;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		vector<int> hpos,apos;
		scanf("%d%d",&n,&b);
		scanf("%s",str);
		for(int i=0;i<n;i++)
		{
			if(str[i]=='A')
				apos.push_back(i+1);
			else if(str[i]=='H')
				hpos.push_back(i+1);
			G[i+1].clear();
			tr[i+1].clear();
		}
		for(int i=0;i<b;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			edge[i].u=u,edge[i].v=v,edge[i].w=w;
			G[u].push_back(Edge {v,w});
			G[v].push_back(Edge {u,w});
		}
		SCC();
		for(int i=0;i<=n;i++)
			cnta[i]=cnth[i]=0;
		for(auto &u:hpos) cnth[bel[u]]++;
		for(auto &u:apos) cnta[bel[u]]++;
		ans=0;
		solve(1);
		printf("%lld\n",ans);
	}
}
