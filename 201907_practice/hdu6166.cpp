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
struct Edge{
	int v,w;
};
vector<Edge> G[maxn];
bool sp[maxn];
vector<int> sss;
const int INF=0x3f3f3f3f;
int dis[maxn];
bool inq[maxn];
struct node{
	int cur,from;
};
int ans;
void spfa()
{
	queue<node> q;
	memset(inq,0,sizeof(inq));
	memset(dis,0x3f,sizeof(dis));
	for(auto &u:sss)
	{
		q.push(node{u,u});
		dis[u]=0;
		inq[u]=1;
	}
	while(!q.empty())
	{
		auto u=q.front();q.pop();
		inq[u.cur]=0;
		for(auto e:G[u.cur])
		{
			int v=e.v;
			int nd=dis[u.cur]+e.w;
			if(sp[v]&&u.v!=u.from) ans=min(ans,nd);
			if(nd<dis[v])
			{
				dis[v]=nd;
				if(!inq[v])
					q.push(node{v,sp[v]?v:u.from});
				inq[v]=1;
			}
		}
	}

}
int main()
{
	int T;
	int kas=0;
	scanf("%d",&T);
	while(T--)
	{
		ans=INF;
		memset(sp,0,sizeof(sp));
		sss.clear();
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++) G[i].clear();
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			G[u].push_back(Edge{v,w});
		}
		int k;
		scanf("%d",&k);
		for(int i=0;i<k;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			sp[tmp]=1;
			sss.push_back(tmp);
		}
		spfa();
		printf("Case #%d: %d\n",++kas,ans);
	}
}
