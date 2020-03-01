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
struct Edge{
    int to,id;
};
const int maxn=1005;
const int maxm=2e5+7;
vc<Edge> G[maxn];
pi edge[maxm];
bool vis[maxn];
bool can[maxn][maxn];
int go[maxn][maxn][2];
void dfs(int u,int st,int tp,int fi=-1)
{
    if(vis[u]) return ;
    can[st][u]=1;
    vis[u]=1;
    go[st][u][tp]=fi;
    for(auto e:G[u])if(!vis[e.to])
    {
        int v=e.to;
        dfs(v,st,tp,fi==-1?e.id:fi);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0,u,v;i<m;i++)
    {
        cin>>u>>v;
        edge[i]={u,v};
        G[u].push_back(Edge{v,i});
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        dfs(i,i,0);
        memset(vis,0,sizeof(vis));
        reverse(G[i].begin(),G[i].end());
        dfs(i,i,1);
    }
    for(int i=0,u,v;i<m;i++)
    {
        u=edge[i].first,v=edge[i].second;
        //dbg(u,v,can[v][u]);
        if(can[v][u]^(go[u][v][0]!=i||go[u][v][1]!=i)) cout<<"diff\n";
        else cout<<"same\n";
    }

}