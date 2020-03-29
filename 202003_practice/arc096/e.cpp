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
ll quick(ll a,ll b,const int mod)
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
const int maxn=3005;
ll fac[maxn];
ll C[maxn][maxn],S[maxn][maxn];
void db(const int mod)
{
    fac[0]=0;
    for(int i=0;i<maxn;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    S[0][0]=1;
    for(int i=1;i<maxn;i++)
    {
        S[i][0]=0;
        for(int j=1;j<=i;j++)
            S[i][j]=(S[i-1][j-1]+(ll)j*S[i-1][j]%mod)%mod;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    ll ans=0;
    db(m);
    for(int i=0;i<=n;i++)
    {
        ll cur=0;
        for(int j=0;j<=i;j++)
            cur=(cur+S[i+1][j+1]*quick(2,(n-i)*j,m)%m)%m;
        cur=cur*C[n][i]%m*quick(2,quick(2,n-i,m-1),m)%m;
        if(i&1) ans=(ans-cur+m)%m;
        else ans=(ans+cur)%m;
    }
    print(ans);
}