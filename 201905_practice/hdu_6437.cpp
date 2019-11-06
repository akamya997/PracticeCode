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
const int maxn=550;
struct Video{
	int S,T,w,op;
}v[maxn];
const int INF=0x3f3f3f3f;
struct Edge{
	int from,to,cap,flow,cost;
};
struct MCMF{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[maxn];
	int inq[maxn];
	int d[maxn];
	int p[maxn];
	int a[maxn];
	void init(int n)
	{
		this->n=n;
		for(int i=0;i<n;i++) G[i].clear();
		edges.clear();
	}
	void addedge(int from,int to,int cap,int cost)
	{
		edges.push_back(Edge {from,to,cap,0,cost});
		edges.push_back(Edge {to,from,0,0,-cost});
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);

	}
	bool spfa(int s,int t,int &flow,int &cost)
	{
		for(int i=0;i<n;i++) d[i]=INF;
		memset(inq,0,sizeof(inq));
		d[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
		queue<int> q;
		q.push(s);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			inq[u]=0;
			for(int i=0;i<G[u].size();i++)
			{
				Edge &e=edges[G[u][i]];
				if(e.cap>e.flow&&d[e.to]>d[u]+e.cost)
				{
					d[e.to]=d[u]+e.cost;
					p[e.to]=G[u][i];
					a[e.to]=min(a[u],e.cap-e.flow);
					if(!inq[e.to])
					{
						q.push(e.to);
						inq[e.to]=1;
					}
				}
			}
		}
		if(d[t]==INF) return false;
		flow+=a[t];
		cost+=d[t]*a[t];
		int u=t;
		while(u!=s)
		{
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
			u=edges[p[u]].from;
		}
		return true;
	}
	int Mincost(int s,int t)
	{
		int flow=0,cost=0;
		while(spfa(s,t,flow,cost));
		return cost;
	}
}F;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,K,W;
		cin>>n>>m>>K>>W;
		for(int i=1;i<=m;i++)
			cin>>v[i].S>>v[i].T>>v[i].w>>v[i].op;
		int s=0,ss=2*m+1,t=2*m+2;
		F.init(t+1);
		F.addedge(s,ss,K,0);
		for(int i=1;i<=m;i++)
		{
			F.addedge(ss,i,1,-v[i].w);
			F.addedge(i+m,t,1,0);
			F.addedge(i,i+m,1,0);
			for(int j=1;j<=m;j++)
			{
				if(i==j) continue;
				if(v[i].T<=v[j].S)
				{
					F.addedge(i+m,j,1,-v[j].w+(v[i].op==v[j].op?W:0));
				}
			}
		}
		cout<<-F.Mincost(s,t)<<endl;
	}
}
