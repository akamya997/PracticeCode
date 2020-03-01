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
const int maxn=5005;
const int INF=0x3f3f3f3f;
vi G[maxn];
int x[maxn];
int dp[maxn];
bool ok=1;
void dfs(int u,int fa=-1)
{
    vi f(maxn,INF);
    f[0]=0;
    for(auto v:G[u])
    {
        dfs(v,u);
        vi g(maxn,INF),h(maxn,INF);
        for(int i=x[v];i<maxn;i++) g[i]=min(g[i],f[i-x[v]]+dp[v]);
        for(int i=dp[v];i<maxn;i++) h[i]=min(h[i],f[i-dp[v]]+x[v]);
        for(int i=0;i<maxn;i++) f[i]=min(g[i],h[i]);
    }
    dp[u]=f[0];
    for(int i=1;i<=x[u];i++) dp[u]=min(dp[u],f[i]);
    if(dp[u]==INF) ok=0;
    //dbg(u,dp[u]);
    //dbg(f);
}
int main()
{
    int n;
    cin>>n;
    for(int i=2,p;i<=n;i++)
    {
        cin>>p;
        G[p].push_back(i);
    }
    for(int i=1;i<=n;i++) cin>>x[i];
    dfs(1);
    if(!ok) cout<<"IMPOSSIBLE\n";
    else cout<<"POSSIBLE\n";
}