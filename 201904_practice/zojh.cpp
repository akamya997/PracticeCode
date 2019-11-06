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
struct Edge{
	int from,to,nxt;
}edge[maxn*2],edgen[maxn*2];
int head[maxn],headn[maxn];
int cnt,cntn;
int n,m,q;
void init()
{
	cnt=0;
	cntn=0;
	memset(head,-1,sizeof(head));
	memset(headn,-1,sizeof(headn));
}
void addedge(int u,int v)
{
	edge[cnt]={u,v,head[u]};
	head[u]=cnt++;
	edge[cnt]={v,u,head[v]};
	head[v]=cnt++;
}
void addedgen(int u,int v)
{
	edgen[cntn]={u,v,headn[u]};
	headn[u]=cntn++;
}
int cur,scc_cnt;
int dfn[maxn],low[maxn],bel[maxn];
stack<int> st;
void dfs(int u,int fa=-1)
{
	int k=0;
	dfn[u]=low[u]=++cur;
	st.push(u);
	for(int i=head[u];i!=-1;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==u) continue;
		if(v==fa&&!k)
		{
			k++;continue;
		}
		if(!dfn[v])
		{
			dfs(v,u);
			low[u]=min(low[u],low[v]);
		}
		else if(!bel[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		scc_cnt++;
		while(1)
		{
			int t=st.top();st.pop();
			bel[t]=scc_cnt;
			if(t==u) break;
		}
	}
}
int far[maxn];
int Find(int x){return x==far[x]?x:far[x]=Find(far[x]);}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	far[y]=x;
}
void SCC()
{
	cur=0,scc_cnt=0;
	while(!st.empty()) st.pop();
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(bel,0,sizeof(bel));
	for(int i=1;i<=n;i++)
		if(!dfn[i]) dfs(i);
	for(int i=0;i<=scc_cnt;i++) far[i]=i;
	for(int u=1;u<=n;u++)
	{
		for(int j=head[u];j!=-1;j=edge[j].nxt)
		{
			int v=edge[j].to;
			if(bel[v]!=bel[u])
			{
				addedgen(bel[u],bel[v]);
				Union(bel[u],bel[v]);
			}
		}
	}
}
int dep[maxn];
int faa[maxn][32];
void dfsdep(int u,int fa=-1)
{
	for(int i=1;i<32;i++) faa[u][i]=faa[faa[u][i-1]][i-1];
	for(int i=headn[u];i!=-1;i=edgen[i].nxt)
	{
		int v=edgen[i].to;
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		faa[v][0]=u;
		dfsdep(v,u);
	}
}
void LCA_init()
{
	for(int i=1;i<=scc_cnt;i++)
	{
		dep[i]=0;
		for(int j=0;j<32;j++) faa[i][j]=0;
	}
	for(int i=1;i<=scc_cnt;i++)
		if(!dep[i]) dfsdep(i);
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]){
        swap(x,y);
    }
	int i;
    for(i=0;(1<<i)<=dep[x];i++);
    i--;
    for(int j=i;j>=0;j--)
	{
        if(dep[x]-(1<<j)>=dep[y])
            x=faa[x][j];
    }
    if(x==y)
        return x;
    for(int j=i;j>=0;j--)
    {
        if(faa[x][j]!=faa[y][j]){
            x=faa[x][j];
            y=faa[y][j];
        }
    }
    return faa[x][0];
}
int dis(int u,int v)
{
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
void solve(int u,int v,int w)
{
	if(!(Find(bel[u])==Find(bel[v])&&Find(bel[v])==Find(bel[w]))) puts("No");
	else{
		if(dis(bel[u],bel[v])+dis(bel[u],bel[w])==dis(bel[v],bel[w]))
			puts("Yes");
		else puts("No");
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		init();
		for(int i=0,u,v;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
		}
		SCC();
		LCA_init();
		while(q--)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			solve(u,v,w);
		}
	}
}
