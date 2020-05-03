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
const int maxn=2e5+7;
int c[maxn];
vi G[maxn];
deque<ll> dp[maxn];
void Merge(deque<ll> &a,deque<ll> &b)
{
    if(a.size()<b.size()) swap(a,b);
    for(int i=0;i<b.size();i++)
        a[i]+=b[i];
}
void dfs(int u)
{
    for(auto v:G[u])
    {
        dfs(v);
        Merge(dp[u],dp[v]);
    }
    dp[u].push_front(c[u]);
    for(auto &v:dp[u]) v=(v+1)/2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=2,p;i<=n;i++)
    {
        cin>>p;
        G[p].push_back(i);
    }
    dfs(1);
    ll ans=0;
    for(auto u:dp[1]) ans+=u;
    print(ans);
}