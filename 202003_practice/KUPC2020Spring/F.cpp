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
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
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
const int maxn=1e5+7;
vi G[maxn];
int a[maxn],b[maxn];
int sum[maxn];
ll ans=0;
void dfs(int u,int fa=-1)
{
    sum[u]=b[u]-a[u];
    for(auto v:G[u])if(v!=fa)
    {
        dfs(v,u);
        sum[u]+=sum[v];
    }
}
ll k[maxn];
void dfs2(int u,int fa=-1,ll cur=0)
{
    k[u]=cur;
    ans=min(ans,k[u]);
    for(auto v:G[u])if(v!=fa)
        dfs2(v,u,cur-sum[v]);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=0;i<n;i++) cin>>a[i+1];
    for(int i=0;i<n;i++) cin>>b[i+1];
    dfs(1);
    dfs2(1);
    //dbg(ans);
    ll op=0;
    for(int i=1;i<=n;i++)
    {
        //dbg(k[i]);
        op+=k[i];
    }
    op+=-n*ans;
    print(op);
}