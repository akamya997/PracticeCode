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
const int maxn=210;
struct Edge
{
    int from, to, cap, flow;double cost;
};
struct MCMF
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];
    double d[maxn]; //最短路数组
    int p[maxn]; //记录路径
    int a[maxn]; //记录流量
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }
    void addedge(int from, int to, int cap, double cost)
    {
        edges.push_back(Edge{from, to, cap, 0, cost});
        edges.push_back(Edge{to, from, 0, 0, -cost});
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool spfa(int s, int t, int &flow, double &cost)
    {
        for (int i = 0; i < n; i++)
            d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = INF;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge &e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
                {
                    d[e.to] = d[u] + e.cost;             //松弛
                    p[e.to] = G[u][i];                   //记录上一个点
                    a[e.to] = min(a[u], e.cap - e.flow); //流量控制
                    if (!inq[e.to])
                    {
                        q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (d[t] == INF)
            return false; //不存在最短路
        flow += a[t];
        cost += d[t] * a[t];
        int u = t;
        while (u != s)
        {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }
    double Mincost(int s, int t)
    {
        int flow = 0;double cost = 0;
        while (spfa(s, t, flow, cost))
            ;
        return cost;
    }
}F;
int a[maxn][maxn];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	int S=2*n,T=S+1;
	F.init(T+1);
	for(int i=0;i<n;i++)
	{
		F.addedge(S,i,1,0);
		F.addedge(i+n,T,1,0);
		for(int j=0;j<n;j++)
			F.addedge(i,n+j,1,-log(a[j][i]));
	}
	F.Mincost(S,T);
	vector<int> ans;
	for(int i=0;i<n;i++)
	{
		for(auto v:F.G[i])
		{
			if(F.edges[v].flow==1)
			{
				ans.push_back(F.edges[v].to+1-n);
			}
		}
	}
	for(auto u:ans) printf("%d ",u);
	puts("");
}
