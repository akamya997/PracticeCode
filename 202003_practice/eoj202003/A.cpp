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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        int k;
        ll n,m;
        cin>>k>>n>>m;
        ll x,y;
        vc<ll> posx,posy;
        for(int i=0;i<k;i++)
        {
            cin>>x>>y;
            ll xx=x+y,yy=x-y;
            posx.push_back(xx);
            posy.push_back(yy);
        }
        sort(posx.begin(),posx.end());
        sort(posy.begin(),posy.end());
        dbg(posx);
        dbg(posy);
        ll ans=0;
        ans=max({posx[0],n-posy.back(),n+m-posx.back(),posy[0]+m});
        for(int i=1;i<posx.size();i++)
        {
            ll d=(posx[i]-posx[i-1])/2;
            ans=max(ans,d);
        }
        for(int i=1;i<posy.size();i++)
        {
            ll d=(posy[i]-posy[i-1])/2;
            ans=max(ans,d);
        }
        print(ans);
    }
}