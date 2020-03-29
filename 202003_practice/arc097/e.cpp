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
const int maxn=2005;
int dp[maxn][maxn];
int tree[2*maxn];
void add(int x,int val)
{
    while(x<maxn)
    {
        tree[x]+=val;
        x+=x&-x;
    }
}
int query(int x)
{
    int ret=0;
    while(x)
    {
        ret+=tree[x];
        x-=x&-x;
    }
    return ret;
}
int main()
{
    int n;
    cin>>n;
    vi posa(n+1,-1),posb(n+1,-1);
    vi a(2*n);
    for(int i=0;i<2*n;i++)
    {
        string col;
        cin>>col;
        cin>>a[i];
        if(col=="B")
        {
            posa[a[i]]=i+1;
            add(i+1,1);
        }
        else {
            posb[a[i]]=i+1;
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            add(posb[j],1);
        for(int j=0;j<=n;j++)
        {
            if(!i&&!j) continue;
            if(i)
            {
                if(j) add(posb[j],-1);
                dp[i][j]=min(dp[i][j],dp[i-1][j]+query(posa[i]-1));
                if(j) add(posb[j],1);
            }
            if(j)
            {
                if(i) add(posa[i],-1);
                dp[i][j]=min(dp[i][j],dp[i][j-1]+query(posb[j]-1));
                if(i) add(posa[i],1);
            }
            if(j) add(posb[j],-1);
            //dbg(i,j,dp[i][j]);
        }
        if(i)
            add(posa[i],-1);
    }
    print(dp[n][n]);
}