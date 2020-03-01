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
typedef pair<int,ll> pi;
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
typedef tuple<int,int,int> tp;
ll inv(ll a){return quick(a,mod-2);}
struct D{
    int sz;
    ll zero,one,two;
};
vi G[maxn];
deque<D> dp[maxn];
inline void Merge(deque<D> &a,deque<D>& b)
{
    if(a.size()<b.size()) a.swap(b);
    for(int i=0;i<b.size();i++)
    {
        a[i].two=((a[i].one+a[i].two)%mod*(b[i].one+b[i].two)%mod)+a[i].two*b[i].zero%mod+a[i].zero*b[i].two%mod;
        a[i].two%=mod;
        a[i].one=(a[i].zero*b[i].one%mod+b[i].zero*a[i].one%mod)%mod;
        a[i].zero=a[i].zero*b[i].zero%mod;
        a[i].sz+=b[i].sz;
    }
}
void dfs(int u)
{
    int mx=0;
    for(auto v:G[u])
    {
        dfs(v);
        mx=max(mx,min((int)dp[u].size(),(int)dp[v].size()));
        Merge(dp[u],dp[v]);
    }
    for(auto &v:dp[u])
    {
        if(!mx) break;
        mx--;
        v.zero=(v.zero+v.two)%mod;
        v.two=0;
    }
    dp[u].push_front(D{1,1,1,0});
    //for(auto v:G[u])
      //  dp[u]=(dp[u]+tot*inv((quick(2,sz[v])-dp[v]+mod)%mod)%mod*dp[v]%mod)%mod;
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
    dfs(0);
    ll ans=0;
    for(auto u:dp[0])
    {
        //dbg(u.zero,u.one,u.sz);
        ans=(ans+u.one*quick(2,n+1-u.sz)%mod)%mod;
    }
    print(ans);
}