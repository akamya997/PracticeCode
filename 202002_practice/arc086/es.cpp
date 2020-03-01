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
const int maxn=2e5+7;
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
ll inv(ll a){return quick(a,mod-2);}
vi G[maxn];
int sz[maxn];
ll dp[maxn];
int curd;
void dfs(int u,int dep=0)
{
    sz[u]=0;
    if(dep==curd) 
    {
        sz[u]=1;
        dp[u]=1;
    }
    else{
        ll tot=1;
        for(auto v:G[u])
        {
            dfs(v,dep+1);
            sz[u]+=sz[v];
            tot=tot*(quick(2,sz[v])-dp[v]+mod)%mod;
        }
        dp[u]=0;
        for(auto v:G[u])
        {
            dp[u]=(dp[u]+tot*inv((quick(2,sz[v])-dp[v]+mod)%mod)%mod*dp[v]%mod)%mod;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1,p;i<=n;i++)
    {
        cin>>p;
        G[p].push_back(i);
    }
    ll ans=0;
    for(curd=0;curd<=n;curd++)
    {
        dfs(0);
        dbg(curd,sz[0],dp[0]);
        ans+=1LL*dp[0]*quick(2,n+1-sz[0])%mod;
        ans%=mod;
    }
    print(ans);
}
