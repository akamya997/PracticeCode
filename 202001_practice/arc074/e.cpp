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
const int maxn=305;
const int mod=1e9+7;
vc<pi> q[maxn];
int dp[maxn][maxn][maxn];
int n,m;
int dfs(int r,int g,int b)
{
    //dbg(r,g,b);
    if(r==n||g==n||b==n) return 1;
    int &ret=dp[r][g][b];
    if(ret!=-1) return ret;
    ret=0;
    int p=max({r,g,b})+1;
    bool okr=1,okg=1,okb=1;
    for(auto u:q[p])
    {
        int l=u.first,t=u.second;
        okr&=(((g>=l)+(b>=l)+1)==t);
        okb&=(((r>=l)+(g>=l)+1)==t);
        okg&=(((r>=l)+(b>=l)+1)==t);
    }
    if(okr) ret=(ret+dfs(p,g,b))%mod;
    if(okg) ret=(ret+dfs(r,p,b))%mod;
    if(okb) ret=(ret+dfs(r,g,p))%mod;
    //dbg(r,g,b,ret);
    return ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i=0,l,r,x;i<m;i++)
    {
        cin>>l>>r>>x;
        q[r].push_back(make_pair(l,x));
    }
    cout<<dfs(0,0,0)<<'\n';
}