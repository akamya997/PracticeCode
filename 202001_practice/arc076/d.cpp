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
    int u,v,d;
    bool operator<(const Edge& a)const{
        return d<a.d;
    }
};
struct P{
    int x,y,id;
    bool operator<(const P&a)const{
        if(x==a.x) return y<a.y;
        return x<a.x;
    }
};
const int maxn=1e5+7;
int fa[maxn];
int Find(int x)
{
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    fa[y]=x;
}
int main()
{
    for(int i=0;i<maxn;i++) fa[i]=i;
    int n;
    cin>>n;
    vc<P> p(n);
    for(int i=0;i<n;i++) 
    {
        cin>>p[i].x>>p[i].y;
        p[i].id=i;
    }
    sort(p.begin(),p.end());
    vc<Edge> all;
    for(int i=0;i<n;i++)
    {
        if(i)
            all.push_back(Edge{p[i].id,p[i-1].id,p[i].x-p[i-1].x});
    }
    for(int i=0;i<n;i++) swap(p[i].x,p[i].y);
    sort(p.begin(),p.end());
    for(int i=0;i<n;i++)
    {
        if(i)
            all.push_back(Edge{p[i].id,p[i-1].id,p[i].x-p[i-1].x});
    }
    sort(all.begin(),all.end());
    ll ans=0;
    for(auto u:all)
    {
        if(Find(u.u)!=Find(u.v))
        {
            Union(u.u,u.v);
            ans+=u.d;
        }
    }
    cout<<ans<<'\n';
}