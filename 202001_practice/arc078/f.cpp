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
int G[20][20];
int dp[1<<15][15];
int cost[15][1<<15];
int cc[1<<15];
int main()
{
    memset(dp,0x3f,sizeof(dp));
    dp[1][0]=0;
    int n,m;
    cin>>n>>m;
    for(int i=0,u,v,w;i<m;i++)
    {
        cin>>u>>v>>w;
        u--,v--;
        G[u][v]=G[v][u]=w;
    }
    for(int i=0;i<n;i++)
    {
        for(int S=0;S<(1<<n);S++)
        {
            for(int j=0;j<n;j++)
            {
                if(S>>j&1)
                    cost[i][S]+=G[i][j];
            }
        }
    }
    for(int S=1;S<(1<<n);S++)
    {
        int SS=((1<<n)-1)^S;
        for(int T=SS;T;T=(T-1)&SS)
            cc[T]=0;
        for(int T=SS;T;T=(T-1)&SS)
            for(int j=0;j<n;j++)
                if(S>>j&1) cc[T]+=cost[j][T];
        for(int i=0;i<n;i++)
        {
            if(S>>i&1)
            {
                for(int j=0;j<n;j++)
                {
                    if(G[i][j])
                        dp[S|(1<<j)][j]=min(dp[S|(1<<j)][j],dp[S][i]+cost[j][S]-G[i][j]);
                }
            }
            for(int T=SS;T;T=(T-1)&SS)
                dp[S|T][i]=min(dp[S|T][i],dp[S][i]+cc[T]-cost[i][T]);
        }
        //for(int j=0;j<n;j++) dbg(S,j,dp[S][j]);
    }
    cout<<dp[(1<<n)-1][n-1]<<'\n';
}