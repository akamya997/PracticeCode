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
struct D{
    ll cnt;
    int lz;
    D(int _cnt=0,int _lz=0):cnt(_cnt),lz(_lz){}
    inline void upd(int val)
    {
        if(cnt>=1)
            cnt=max(1LL,cnt-val);
    }
};
deque<D> dp[maxn];
void Merge(deque<D> &a,deque<D> &b)
{
    if(a.size()<b.size()) a.swap(b);
    int cura=0,curb=0;
    for(int i=0;i<b.size();i++)
    {
        cura+=a[i].lz;
        curb+=b[i].lz;
        a[i].lz=0;
        b[i].lz=0;
        a[i].upd(cura);
        b[i].upd(curb);
        a[i].cnt+=b[i].cnt;
    }
    if(b.size()<a.size()) a[b.size()].lz+=cura;
}
void dfs(int u,int fa=-1)
{
    int mx=0;
    for(auto v:G[u])if(v!=fa)
    {
        dfs(v,u);
        mx=max(mx,(int)min(dp[u].size(),dp[v].size()));
        Merge(dp[u],dp[v]);
    }
    dp[u].push_front(D{c[u],0});
    mx++;
    int cur=1;
    for(int i=0;i<mx;i++)
    {
        cur+=dp[u][i].lz;
        dp[u][i].lz=0;
        dp[u][i].upd(cur);
    }
    if(mx!=dp[u].size()) dp[u][mx].lz+=cur;
    //for(int i=0;i<dp[u].size();i++)
    //    dbg(u,i,dp[u][i].cnt,dp[u][i].lz);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=2,u,v;i<=n;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(s);
    ll ans=0;
    int cur=0;
    for(int i=0;i<dp[s].size();i++)
    {
        cur+=dp[s][i].lz;
        dp[s][i].upd(cur);
        //dbg(i,dp[s][i].cnt);
        ans+=dp[s][i].cnt;
    }
    print(ans);
}