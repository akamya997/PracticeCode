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
int dp[maxn];
int len;
void dfs(int u,int fa=-1)
{
    dp[u]=1;
    for(auto v:G[u])if(v!=fa)
    {
        dfs(v,u);
        dp[u]=max(dp[u],dp[v]+1);
    }
}
void dfs2(int u,int fa=-1)
{
    multiset<int> son;
    for(auto v:G[u])
        son.insert(dp[v]);
    if(son.size()>2)
    {
        //dbg(u,son);
        auto it=son.rbegin();
        vi all;
        for(int i=0;i<3;i++)
        {
            all.push_back(*it);
            it++;
        }
        if(all[0]!=all[2])
            len=max(len,all[0]+all[2]+1);
        else len=max(len,all[0]+all[2]);
    }
    for(auto v:G[u])if(v!=fa)
    {
        son.erase(son.find(dp[v]));
        int tmp=dp[u];
        if(son.empty()) dp[u]=1;
        else dp[u]=(*son.rbegin())+1;
        int tmpv=dp[v];
        dp[v]=max(dp[v],dp[u]+1);
        dfs2(v,u);
        dp[u]=tmp;
        dp[v]=tmpv;
        son.insert(dp[v]);
    }
}
int main()
{
    int n;
    cin>>n;
    len=2;
    string ans;
    for(int i=0;i<n;i++) ans+='1';
    bool ac=1;
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    dfs2(1);
    for(int i=2;i<len-1;i++) ans[i]='0';
    cout<<ans<<'\n';
}