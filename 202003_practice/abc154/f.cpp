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
const int maxn=2e6+7;
const int mod=1e9+7;
ll fac[maxn];
ll invfac[maxn];
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
inline ll C(int n,int m)
{
    if(m>n) return 0;
    return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int main()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
    invfac[maxn-1]=quick(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--) invfac[i]=invfac[i+1]*(i+1)%mod;
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    ll cur=C(r1+c1,r1);
    ll ans=cur;
    int l=r1,r=r1;
    for(int i=r1+c1+1;i<=c2+r2;i++)
    {
        int nr=r,nl=l;
        if(r<r2) nr++;
        if(i>r1+c2) nl++;
        cur=(cur*2)%mod;
        if(nr>r&&nl==l)
            cur=(cur+C(i-1,l-1)+C(i-1,nr))%mod;
        else if(nl==l&&nr==r)
            cur=(cur+C(i-1,l-1)-C(i-1,r)+mod)%mod;
        else if(nr>r&&nl>l){
            cur=(cur+C(i-1,nr)-C(i-1,l)+mod)%mod;
        }
        else if(nr==r&&nl>l)
            cur=(cur-(C(i-1,l)+C(i-1,r))%mod+mod)%mod;
        else assert(false);
        ans=(ans+cur)%mod;
        l=nl,r=nr;
        //dbg(i,cur);
    }
    print(ans);

}