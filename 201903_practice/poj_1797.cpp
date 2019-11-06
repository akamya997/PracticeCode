#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
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
const int maxn=1007;
const int INF=0x3f3f3f3f;
struct Edge{
	int to,w;
};
vector<Edge> G[maxn];
int dis[maxn];
bool vis[maxn];
struct dij{
	int dist,num;
	bool operator<(const dij& a)const{
		return dist<a.dist;
	}
};
void dijkstra(int st)
{
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=INF;
	priority_queue<dij> q;
	q.push(dij{INF,st});
	while(!q.empty())
	{
		dij u=q.top();q.pop();
		dbg(u.num);
		if(vis[u.num]) continue;
		vis[u.num]=1;
		for(int i=0;i<G[u.num].size();i++)
		{
			Edge v=G[u.num][i];
			if(dis[v.to]<min(dis[u.num],v.w))
			{
				dis[v.to]=min(dis[u.num],v.w);
				q.push(dij{dis[v.to],v.to});
			}
		}
	}
}
int main()
{
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++) G[i].clear();
		for(int i=0,u,v,w;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			G[u].push_back(Edge{v,w});
			G[v].push_back(Edge{u,w});
		}
		dijkstra(1);
		printf("Scenario #%d:\n%d\n\n",++kas,dis[n]);
	}
}
