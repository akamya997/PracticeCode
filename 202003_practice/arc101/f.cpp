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
const int maxn=2e5+7;
const int mod=1e9+7;
ll tree[maxn];
void add(int x,ll val)
{
    while(x<maxn)
    {
        tree[x]=(tree[x]+val)%mod;
        x+=x&-x;
    }
}
ll query(int x)
{
    ll ret=0;
    while(x)
    {
        ret=(ret+tree[x])%mod;
        x-=x&-x;
    }
    return ret;
}

pi all[maxn*2];
int L[maxn],R[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>all[i].first;
        all[i].second=0;
    }
    for(int i=0;i<m;i++)
    {
        cin>>all[i+n].first;
        all[i+n].second=1;
    }
    sort(all,all+n+m);
    {
        int cur=0;
        for(int i=0;i<m+n;i++)
        {
            if(all[i].second) cur=all[i].first;
            else{
                if(cur) L[i]=all[i].first-cur;
            }
        }
    }
    {
        int cur=0;
        for(int i=m+n-1;i>=0;i--)
        {
            if(all[i].second) cur=all[i].first;
            else{
                if(cur) R[i]=cur-all[i].first;
            }
        }
    }
    vc<pi> pt;
    vi pos;
    for(int i=0;i<n+m;i++)
    {
        if(L[i]&&R[i]) {
            pt.emplace_back(L[i],R[i]);
            //dbg(i,L[i],R[i]);
            pos.push_back(R[i]);
        }
    }
    mkuni(pt);
    sort(pt.begin(),pt.end(),[&](pi a,pi b){if(a.first==b.first)return a.second>b.second;return a.first<b.first;});
    pos.push_back(0);
    mkuni(pos);
    auto getid=[&](int x)
    {
        return lower_bound(pos.begin(),pos.end(),x)-pos.begin()+1;
    };
    add(getid(0),1);
    for(auto u:pt)
    {
        ll cur=query(getid(u.second)-1);
        add(getid(u.second),cur);
    }
    print(query(maxn-1));
}