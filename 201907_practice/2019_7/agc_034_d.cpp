#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 20;
const int INF = 0x3f3f3f3f;
const ll llINF=0x3f3f3f3f3f3f3f3f;
struct Edge
{
    int from, to, cap, flow;
	ll cost;
};
struct MCMF
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];
    ll d[maxn]; //最短路数组
    int p[maxn]; //记录路径
    int a[maxn]; //记录流量
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }
    void addedge(int from, int to, int cap, ll cost)
    {
        edges.push_back(Edge{from, to, cap, 0, cost});
        edges.push_back(Edge{to, from, 0, 0, -cost});
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool spfa(int s, int t, int &flow, ll &cost)
    {
        for (int i = 0; i < n; i++)
            d[i] = llINF;
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
        if (d[t] == llINF)
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
    ll Mincost(int s, int t)
    {
        int flow = 0;ll cost = 0;
        while (spfa(s, t, flow, cost))
            ;
        return cost;
    }
}F;
int main()
{
	int n;
	scanf("%d",&n);
	int S=2*n+1;int T=S+1;
	int sp1=T+1,sp2=T+2,sp3=T+3,sp4=T+4;
	F.init(sp4+1);
	for(int i=0,cnt,x,y;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&cnt);
		F.addedge(S,i,cnt,0);
		F.addedge(i,sp1,INF,x+y);
		F.addedge(i,sp2,INF,x-y);
		F.addedge(i,sp3,INF,-x+y);
		F.addedge(i,sp4,INF,-x-y);
	}
	for(int i=0,cnt,x,y;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&cnt);
		F.addedge(i+n,T,cnt,0);
		F.addedge(sp1,i+n,INF,-x-y);
		F.addedge(sp2,i+n,INF,-x+y);
		F.addedge(sp3,i+n,INF,x-y);
		F.addedge(sp4,i+n,INF,x+y);
	}
	printf("%lld\n",-F.Mincost(S,T));
}
