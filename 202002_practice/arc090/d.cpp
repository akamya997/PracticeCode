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
    int to,w;
};
const int maxn=1e5+7;
vc<Edge> G[maxn];
inline void addedge(int u,int v,int w)
{
    G[v].push_back(Edge{u,w});
    G[u].push_back(Edge{v,-w});
}
int cnt[maxn];
int n,m;
int dis[maxn];
bool inq[maxn];
bool vis[maxn];
bool spfa(int st,int cc=0)
{
    if(cc>n) return false;
    vis[st]=1;
    for(auto& e:G[st])
    {
        int v=e.to;
        if(dis[v]>dis[st]+e.w)
        {
            dis[v]=dis[st]+e.w;
            if(!spfa(v,cc+1)) return false;
        }
    }
    return true;
}
bool solve()
{
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dis[i]=0;
            if(!spfa(i))
                return false;
        }
    }
    return true;
    
}
int main()
{
    cin>>n>>m;
    for(int i=0,u,v,w;i<m;i++)
    {
        cin>>u>>v>>w;
        addedge(u,v,w);
    }
    if(solve())
        cout<<"Yes\n";
    else cout<<"No\n";
}