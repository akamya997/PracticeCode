#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn=2e4+7;
typedef vector<int> vi;
vi G[maxn],g[maxn],idx[maxn];
int n,m;
int dfn[maxn];
int low[maxn];
int cur,scc;
stack<int> st;
int bel[maxn];
void dfs(int u,int fa)
{
	dfn[u]=low[u]=++cur;
	st.push(u);
	for(auto v:G[u])
	{
		if(v==fa) continue;
		if(!dfn[v])
		{
			dfs(v,u);
			low[u]=min(low[v],low[u]);
		}
		else if(!bel[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		scc++;
		while(1)
		{
			int v=st.top();
			st.pop();
			bel[v]=scc;
			idx[scc].push_back(v);
			if(v==u) break;
		}
	}
}
void SCC()
{
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(bel,0,sizeof(bel));
	cur=0;scc=0;
	while(!st.empty()) st.pop();
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i);
	vi vis(scc+1,0);
	for(int i=1;i<=scc;i++)
	{
		for(auto u:idx[i])
		{
			for(auto v:G[u])
			{
				if(i!=bel[v]&&!vis[bel[v]])
				{
					g[i].push_back(bel[v]);
					vis[bel[v]]=1;
				}
			}
		}
		for(auto u:idx[i])
			for(auto v:G[u])
				vis[bel[v]]=0;
	}
}
int indeg[maxn],outdeg[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(indeg,0,sizeof(indeg));
		memset(outdeg,0,sizeof(outdeg));
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++) 
		{
			G[i].clear();
			g[i].clear();
			idx[i].clear();
		}
		for(int i=0,u,v;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
		}
		SCC();
		int cntin=0,cntout=0;
		for(int i=1;i<=scc;i++)
		{
			for(auto v:g[i])
			{
				indeg[v]++;
				outdeg[i]++;
			}
		}
		for(int i=1;i<=scc;i++)
		{
			cntin+=(indeg[i]==0);
			cntout+=(outdeg[i]==0);
		}
		int ans=max(cntin,cntout);
		if(scc==1) ans=0;
		printf("%d\n",ans);
	}
}
