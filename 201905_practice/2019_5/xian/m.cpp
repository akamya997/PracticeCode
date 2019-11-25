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
struct Edge{
	int to,w;
};
typedef long long ll;
const int maxn=1e5+7;
vector<Edge> G[maxn];
int c,d,e;
int n,m;
int vis[maxn];
bool bfs(ll dis,ll cnt)
{
	memset(vis,-1,sizeof(vis));
	queue<int> q;
	q.push(1);
	vis[1]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(vis[u]>cnt) continue;
		for(auto& e:G[u])
		{
			if(e.w>dis) continue;
			int v=e.to;
			if(vis[v]==-1)
			{
				q.push(v);
				vis[v]=vis[u]+1;
			}
		}
	}
	return vis[n]!=-1;
}
bool check(int cur)
{
	ll dis=1LL*cur*d,cnt=1LL*cur*e;
	return bfs(dis,cnt);
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&c,&d,&e);
	for(int i=0,u,v,w;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back(Edge {v,w});
		G[v].push_back(Edge {u,w});
	}
	int l=1,r=1e5+7,ans=-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%lld\n",1LL*ans*c);

}
