#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int mod=998244353;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn = 1e4 + 7;
struct Edge
{
    int from, to;ll cap, flow;
};
struct Dinic
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];

    void AddEdge(int from, int to, ll cap, ll c = 0)
    {
        edges.push_back(Edge{from, to, cap, 0});
        edges.push_back(Edge{to, from, c, 0});
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BFS()
    {
        memset(vis, 0, sizeof(vis));
        queue<int> q;
        q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge &e = edges[G[u][i]];
                if (!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    ll DFS(int u, ll dist)
    {
        if (u == t || dist == 0)
            return dist;
        ll flow = 0, f;
        for (int &i = cur[u]; i < G[u].size(); i++)
        {
            Edge &e = edges[G[u][i]];
            if (d[u] + 1 == d[e.to] && (f = DFS(e.to, min(dist, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                edges[G[u][i] ^ 1].flow -= f;
                flow += f;
                dist -= f;
                if (!dist)
                    break;
            }
        }
        return flow;
    }
    ll Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        ll flow = 0;
        while (BFS())
        {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
};
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
struct ed{
	int u,v,w;
}sv[maxn];
vector<ed> G[maxn];
ll dis[maxn];
struct Heap{
	int u;ll d;
	bool operator<(const Heap a)const{
		return d>a.d;
	}
};
bool vis[maxn];
void dijstra()
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	priority_queue<Heap> q;
	q.push(Heap{1,0});
	while(!q.empty())
	{
		auto u=q.top();q.pop();
		if(vis[u.u]) continue;
		vis[u.u]=1;
		for(auto e:G[u.u])
		{
			int v=e.v;
			if(dis[v]>u.d+e.w)
			{
				dis[v]=u.d+e.w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=0,u,v,w;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			sv[i]={u,v,w};
			G[u].push_back({u,v,w});
		}
		dijstra();
		Dinic F;
		for(int i=0;i<m;i++)
		{
			int u=sv[i].u,v=sv[i].v,w=sv[i].w;
			if(dis[u]+w==dis[v])
				F.AddEdge(u,v,w);
		}
		printf("%lld\n",F.Maxflow(1,n));
	}
}
