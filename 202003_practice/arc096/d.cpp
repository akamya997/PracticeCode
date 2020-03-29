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
    int n;
    ll c;
    cin>>n>>c;
    vc<ll> x(n),v(n);
    for(int i=0;i<n;i++) cin>>x[i]>>v[i];
    ll ans=0;
    {
        vc<ll> pre(n);
        multiset<ll> st,st2;
        st.insert(0);
        st2.insert(0);
        pre[0]=v[0];
        st.insert(pre[0]-2*x[0]);
        st2.insert(pre[0]-x[0]);
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+v[i];
            st.insert(pre[i]-2*x[i]);
            st2.insert(pre[i]-x[i]);
            ans=max(ans,pre[i]-x[i]);
        }
        ll cur=0;
        for(int i=n-1;i>=0;i--)
        {
            cur+=v[i];
            st.erase(st.find(pre[i]-2*x[i]));
            st2.erase(st2.find(pre[i]-x[i]));
            ans=max({cur-(c-x[i])+*st.rbegin(),ans,cur-2*(c-x[i])+*st2.rbegin()});
        }
    }
    print(ans);
}