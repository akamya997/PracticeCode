#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=3e5+7;
struct Heap{
	int num;
	ll dis;
	bool operator<(const Heap &a) const{
		return dis>a.dis;
	}
};
struct Edge{
	int u,v,w;
}edge[maxn];
vector<Edge> G[maxn];
int n,m,k;
ll dis[maxn];
int S,T;
bool vis[maxn];
const ll INF=1LL<<60;
bool dij(int l,int r)
{
	vector<int> used;
	for(int i=l;i<=r;i++)
	{
		used.push_back(edge[i].u);
		used.push_back(edge[i].v);
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		G[u].push_back(Edge {u,v,w});
		G[v].push_back(Edge {v,u,w});
		dis[u]=INF,dis[v]=INF;
		vis[u]=0,vis[v]=0;
	}
	vis[T]=0,vis[S]=0;
	dis[T]=INF;
	dis[S]=0;
	priority_queue<Heap> q;
	q.push(Heap {S,0});
	while(!q.empty())
	{
		auto u=q.top();q.pop();
		if(vis[u.num]) continue;
		vis[u.num]=1;
		for(auto &e:G[u.num])
		{
			if(dis[e.v]>u.dis+e.w)
			{
				dis[e.v]=u.dis+e.w;
				q.push(Heap {e.v,dis[e.v]});
			}
		}
		if(dis[T]<=k) break;
	}
	for(auto &u:used) 
		G[u].clear();
	return dis[T]<=k;
}
typedef pair<int,int> PII;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d",&S,&T);
	vector<PII> ans;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	int cur=1;
	while(cur<=m)
	{
		int var=sqrt(m-cur);
		int l=cur,r=min(m,cur+var),pos=m+1;
		if(!dij(cur,r)) l=r+1,r=m;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(dij(cur,mid)) r=mid-1,pos=mid;
			else l=mid+1;
		}
		if(pos<=m)
			ans.push_back(make_pair(cur,pos));
		cur=pos+1;
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
}

