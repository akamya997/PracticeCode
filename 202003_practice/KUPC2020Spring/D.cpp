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
const int mod=998244353;
const int maxn=505;
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
int dp[2][520][maxn];
int suf[maxn];
int main()
{
    int n,x;
    cin>>n>>x;
    dp[0][0][x]=1;
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        memset(dp[cur^1],0,sizeof(dp[cur^1]));
        for(int j=0;j<=519;j++)
        {
            for(int k=x;k>=0;k--)
            {
                suf[k]=(suf[k+1]+dp[cur][j][k])%mod;
                if((j^k)<=519)
                    dp[cur^1][j^k][k]=(dp[cur^1][j^k][k]+suf[k])%mod;
            }
        }
        cur^=1;
    }
    int ans=0;
    for(int i=0;i<=x;i++)
        ans=(ans+dp[cur][x][i])%mod;
    print(ans);
}