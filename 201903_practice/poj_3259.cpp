#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
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
const int maxn=507;
int cnt[maxn];
int dis[maxn];
bool inq[maxn];
struct Edge{
	int to,cost;
};
vector<Edge> G[maxn];
bool spfa(int st,int tot)
{
	memset(inq,0,sizeof(inq));
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	q.push(st);
	inq[st]=1;
	cnt[st]=0;
	dis[st]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=0;i<G[u].size();i++)
		{
			Edge v=G[u][i];
			if(dis[v.to]>dis[u]+v.cost)
			{
				cnt[v.to]=cnt[u]+1;
				if(cnt[v.to]>tot) return true;
				dis[v.to]=dis[u]+v.cost;
				if(!inq[v.to]) q.push(v.to);
				inq[v.to]=1;
			}
		}
	}
	return false;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		memset(cnt,-1,sizeof(cnt));
		int n,m,w;
		cin>>n>>m>>w;
		for(int i=0;i<=n;i++) G[i].clear();
		for(int i=0,s,e,t;i<m;i++)
		{
			cin>>s>>e>>t;
			G[s].push_back(Edge {e,t});
			G[e].push_back(Edge {s,t});
		}
		for(int i=0,s,e,t;i<w;i++)
		{
			cin>>s>>e>>t;
			G[s].push_back(Edge {e,-t});
		}
		bool ok=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt[i]==-1)
			{
				if(spfa(i,n)) ok=1;
			}
			if(ok) break;
		}
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
