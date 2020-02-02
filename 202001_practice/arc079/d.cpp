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
int main()
{
    ll k;
    cin>>k;
    ll rem=k;
    const ll var=1e16;
    int n=-1;
    for(int i=2;i<=50;i++)
    {
        if(i-k+(k/i)*(i+1)>0&&i-k+(k/i)*(i+1)<var+500)
        {
            n=i;
            break;
        }
    }
    assert(n!=-1);
    //dbg(n);
    vc<ll> ans(n);
    for(int i=0;i<n-1;i++)
    {
        ll tt=(k+n-1)/n;
        rem-=tt;
        ans[i]=n-k+tt*(n+1)-1;
        //dbg(i,rem);
    }
    ans[n-1]=n-k+rem*(n+1)-1;
    print(n);
    print(ans);
    for(int i=0;i<n;i++) assert(ans[i]>=0);
}