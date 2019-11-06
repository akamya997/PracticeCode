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
const int INF=0x3f3f3f3f;
const int maxn = 5e3 + 7;
struct Edge
{
    int from, to, cap, flow;
};
struct Dinic
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];

    void AddEdge(int from, int to, int cap, int c = 0)
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
    int DFS(int u, int dist)
    {
        if (u == t || dist == 0)
            return dist;
        int flow = 0, f;
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
    int Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        int flow = 0;
        while (BFS())
        {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
}F;
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
int arr[maxn];
vector<int> ans;
int n;
int S,T;
set<int> st;
void bfs()
{
	queue<int> q;
	q.push(S);
	st.insert(S);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(auto id:F.G[u])
		{
			auto e=F.edges[id];
			if(e.cap==e.flow) continue;
			if(st.find(e.to)==st.end())
			{
				st.insert(e.to);
				q.push(e.to);
			}
		}
	}

}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d",&arr[i]);
	S=n+1,T=S+1;
	for(int i=1;i<=n;i++)
	{
		if(__builtin_parity(arr[i]))
		{
			F.AddEdge(S,i,1);
			continue;
		}
		else F.AddEdge(i,T,1);
		for(int j=1;j<=n;j++)
		{
			if(__builtin_popcount(arr[i]^arr[j])==1)
				F.AddEdge(j,i,INF);
		}
	}
	F.Maxflow(S,T);
	bfs();
	set<int> notans;
	for(auto u:st)
	{
		for(auto id:F.G[u])
		{
			auto e=F.edges[id];
			if(st.find(e.to)==st.end())
			{
				if(e.to==T)
					notans.insert(e.from);
				else notans.insert(e.to);
			}
		}
	}
	printf("%d\n",n-(int)notans.size());
	for(int i=1;i<=n;i++)
		if(notans.find(i)==notans.end())
			printf("%d ",arr[i]);
	puts("");
}
