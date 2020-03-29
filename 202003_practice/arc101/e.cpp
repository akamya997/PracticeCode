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
const int mod=1e9+7;
const int maxn=5e3+7;
vc<ll> dp[maxn][2];
vi G[maxn];
ll fac[maxn],invfac[maxn];
ll invtwo[maxn];
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
void db()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
    invfac[maxn-1]=quick(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--) invfac[i]=invfac[i+1]*(i+1)%mod;
    invtwo[0]=1;
    invtwo[1]=(mod+1)/2;
    for(int i=2;i<maxn;i++)
        invtwo[i]=invtwo[i-1]*invtwo[1]%mod;
}
inline ll getcnt(int x)
{
    if(x&1) return 0;
    return fac[x]*invtwo[x/2]%mod*invfac[x/2]%mod;
}
vc<ll> Merge(vc<ll> &a,vc<ll> &b)
{
    int sza=a.size(),szb=b.size();
    vc<ll> ret(sza+szb-1);
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            ret[i+j]=(ret[i+j]+a[i]*b[j]%mod)%mod;
        }
    }
    return ret;
}
void dfs(int u,int fa=-1)
{
    dp[u][0].push_back(0);
    dp[u][0].push_back(1);
    dp[u][1].resize(2);
    for(auto v:G[u])if(v!=fa)
    {
        dfs(v,u);
        int sz=dp[u][0].size()+dp[v][1].size()-1;
        vc<vc<ll>> cur(2,vc<ll>(sz));
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<dp[u][0].size();k++)
                {
                    for(int l=0;l<dp[v][0].size();l++)
                        cur[i^j^1][k]=(cur[i^j^1][k]+dp[u][i][k]*dp[v][j][l]%mod*getcnt(l)%mod)%mod;
                }
            }
        }
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                vc<ll> ret=Merge(dp[u][i],dp[v][j]);
                for(int k=0;k<sz;k++)
                    cur[i^j][k]=(cur[i^j][k]+ret[k])%mod;
            }
        }
        dp[u][0]=cur[0];
        dp[u][1]=cur[1];
    }
    //dbg(u);
    //dbg(dp[u][0]);
    //dbg(dp[u][1]);
}
int main()
{
    db();
    int n;
    cin>>n;
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    ll ans=0;
    for(int i=0;i<=n;i++)
    {
        ans=(ans+dp[1][0][i]*getcnt(i)%mod)%mod;
        ans=(ans-dp[1][1][i]*getcnt(i)%mod+mod)%mod;
    }
    print(ans);
}