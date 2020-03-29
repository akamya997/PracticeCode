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
const int maxn=5e3+7;
const int mod=1e9+7;
vi G[maxn];
int maxson[maxn],sz[maxn];
int rt,mx=0x3f3f3f3f;
int n;
void getrt(int u,int fa=-1)
{
    sz[u]=1;
    for(auto v:G[u])if(v!=fa)
    {
        getrt(v,u);
        sz[u]+=sz[v];
        maxson[u]=max(maxson[u],sz[v]);
    }
    maxson[u]=max(maxson[u],n-sz[u]);
    if(maxson[u]<mx)
    {
        mx=maxson[u];
        rt=u;
    }
}
void dfs(int u,int fa=-1)
{
    sz[u]=1;
    for(auto v:G[u])if(v!=fa)
    {
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
ll dp[maxn][maxn];
ll C[maxn][maxn];
ll fac[maxn];
void init()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
    for(int i=0;i<maxn;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
}
int main()
{
    init();
    cin>>n;
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    getrt(1);
    int cnt=1;
    for(auto v:G[rt])
    {
        if(maxson[v]==mx) cnt++;
    }
    if(cnt==2)
    {
        ll ans=1;
        assert(n%2==0);
        for(int i=1;i<=n/2;i++) ans=ans*i%mod;
        print(ans*ans%mod);
    }
    else if(cnt==1){
        int cc=0;
        //dbg(rt);
        vi T;
        for(auto v:G[rt])
        {
            dfs(v,rt);
            cc++;
            T.push_back(sz[v]);
        }
        dp[0][0]=1;
        for(int i=1;i<=cc;i++)
        {
            for(int k=0;k<=n;k++)
            {
                if(!dp[i-1][k]) continue;
                for(int j=0;j<=T[i-1];j++)
                    dp[i][j+k]=(dp[i][j+k]+dp[i-1][k]*C[T[i-1]][j]%mod*C[T[i-1]][j]%mod*fac[j]%mod)%mod;
            }
        }
        ll ans=0;
        for(int i=0;i<=n-1;i++)
        {
            ll cur=dp[cc][i]*fac[n-i]%mod;
            //dbg(dp[cc][i]);
            if(i&1) ans=(ans-cur+mod)%mod;
            else ans=(ans+cur)%mod;
        }
        print(ans);
    }
    else assert(false);
}