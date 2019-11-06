#include<queue>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
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
const int maxn=1e3+7;
const int INF=0x3f3f3f3f;
struct Edge{
	int to,w;
};
int n,m,x;
vector<Edge> G[2][maxn];
int dis[2][maxn];
bool vis[maxn];
struct dij{
	int dis,u;
	bool operator<(const dij& a)const{
		return dis>a.dis;
	}
};
void dijkstra(int cur)
{
	priority_queue<dij> q;
	memset(vis,0,sizeof(vis));
	memset(dis[cur],0x3f,sizeof(dis[cur]));
	dis[cur][x]=0;
	q.push(dij{0,x});
	while(!q.empty())
	{
		dij u=q.top();q.pop();
		if(vis[u.u]) continue;
		vis[u.u]=1;
		for(int i=0;i<G[cur][u.u].size();i++)
		{
			Edge v=G[cur][u.u][i];
			if(dis[cur][v.to]>dis[cur][u.u]+v.w)
			{
				dis[cur][v.to]=dis[cur][u.u]+v.w;
				q.push(dij{dis[cur][v.to],v.to});
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&x);
	for(int i=0,u,v,w;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		G[0][u].push_back(Edge{v,w});
		G[1][v].push_back(Edge{u,w});
	}
	dijkstra(0);
	dijkstra(1);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dis[0][i]+dis[1][i]);
	printf("%d\n",ans);
}
