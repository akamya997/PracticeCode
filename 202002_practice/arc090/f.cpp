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
int f(ll x)
{
    int ret=0;
    while(x)
    {
        ret++;
        x/=10;
    }
    return ret;
}
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
ll getcnt(int l)
{
    return (quick(10,l)-quick(10,l-1)+mod)%mod;
}
int main()
{
    int s;
    cin>>s;
    int l=1;
    int cur=0;
    ll ans=0;
    for(int r=1;;r++)
    {
        cur+=f(r);
        while(cur>s)
        {
            cur-=f(l);
            l++;
        }
        if(l>=10000000) break;
        if(cur==s)
            ans++;
    }
    int len=s/8;
    ans+=len;
    ans%=mod;
    for(int i=1;i*i<=s;i++)
    {
        if(s%i==0)
        {
            if(i<=len)
                ans=(ans+getcnt(s/i)-i+mod)%mod;
            if(i*i!=s)
            {
                if(s/i<=len)
                    ans=(ans+getcnt(i)-s/i+mod)%mod;
            }
        }
    }
    print(ans);
}