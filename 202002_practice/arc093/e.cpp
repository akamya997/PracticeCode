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
const int mod=1e9+7;
ll quick(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
const int maxn=1005;
vc<tuple<int,int,int>> edge;
int fa[maxn];
int n,m;
void init()
{
    for(int i=0;i<=n;i++) fa[i]=i;
}
int Find(int x)
{
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    fa[y]=x;
}
ll kruskal(tuple<int,int,int> e)
{
    int u,v,w;
    init();
    tie(u,v,w)=e;
    ll ret=w;
    Union(u,v);
    for(auto ed:edge)
    {
        tie(u,v,w)=ed;
        if(Find(u)!=Find(v))
        {
            Union(u,v);
            ret+=w;
        }
    }
    return ret;
}
int main()
{
    cin>>n>>m;
    ll x;
    cin>>x;
    for(int i=0,u,v,w;i<m;i++)
    {
        cin>>u>>v>>w;
        edge.emplace_back(u,v,w);
    }
    sort(edge.begin(),edge.end(),[&](tuple<int,int,int> a,tuple<int,int,int> b){int u,v,w,u2,v2,w2;tie(u,v,w)=a;tie(u2,v2,w2)=b;return w<w2;});
    ll tar=kruskal(tuple<int,int,int> {0,0,0});
    //dbg(tar);
    if(tar==x)
    {
        int a=0;
        for(auto u:edge)
            if(kruskal(u)==x) a++;
        print((quick(2,a)-2)*quick(2,m-a)%mod);
    }
    else if(tar<x)
    {
        int a=0,b=0;
        for(auto u:edge)
        {
            ll cur=kruskal(u);
            if(cur==x) b++;
            else if(cur>x) a++;
        }
        //dbg(a,b);
        print(2*(quick(2,b)-1)*quick(2,a)%mod);
    }
    else print(0);

}