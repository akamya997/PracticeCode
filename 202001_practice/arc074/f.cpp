#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
    print(v[i],i==(int)(v.size())-1?suc:2);
}
const int maxn = 200 + 7;
const int INF = 0x3f3f3f3f;
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
string maze[maxn];
int main()
{
    int h,w;   
    cin>>h>>w;
    for(int i=0;i<h;i++) cin>>maze[i];
    int S=h+w,T=S+1;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(maze[i][j]=='o')
                F.AddEdge(i,j+h,1,1);
            else if(maze[i][j]=='S')
            {
                F.AddEdge(S,i,INF);
                F.AddEdge(S,j+h,INF);
            }
            else if(maze[i][j]=='T')
            {
                F.AddEdge(i,T,INF);
                F.AddEdge(j+h,T,INF);
            }
        }
    }
    int ans=F.Maxflow(S,T);
    if(ans>=INF) cout<<-1<<'\n';
    else cout<<ans<<'\n';

}