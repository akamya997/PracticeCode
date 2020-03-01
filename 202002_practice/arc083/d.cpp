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
const int maxn=305;
int a[maxn][maxn];
struct Edge{
    int u,v,w;
    bool operator<(const Edge &a) const{
        return w<a.w;
    }
};
vc<Edge> G[maxn];
ll dis[maxn];
bool vis[maxn];
struct D{
    ll d,u;
    bool operator<(const D& a)const{
        return d>a.d;
    }
};
ll dij(int s,int t)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    priority_queue<D> q;
    q.push(D{0,s});
    while(!q.empty())
    {
        auto u=q.top();q.pop();
        if(vis[u.u]) continue;
        vis[u.u]=1;
        for(auto &e:G[u.u])
        {
            int v=e.v;
            if(dis[v]>dis[u.u]+e.w)
            {
                dis[v]=dis[u.u]+e.w;
                q.push(D{dis[v],v});
            }
        }
    }
    return dis[t];
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    bool ok=1;
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]>a[i][k]+a[k][j])
                    ok=0;
            }
        }
    }
    if(!ok) print(-1);
    else{
        vc<Edge> all;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                all.push_back(Edge{i,j,a[i][j]});
        }
        sort(all.begin(),all.end());
        ll ans=0;
        for(auto e:all)
        {
            //dbg(e.u,e.v,e.w);
            if(dij(e.u,e.v)>e.w)
            {
                ans+=e.w;
                G[e.u].push_back(e);
                swap(e.u,e.v);
                G[e.u].push_back(e);
            }
        }
        print(ans);
    }
    
}