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
    int L;
    cin>>L;
    int cur=0;
    int xx=0;
    vc<tuple<int,int,int>> edge;
    while(cur+(1<<xx)<L)
    {
        cur+=1<<xx;
        xx++;
        edge.emplace_back(xx,xx+1,1<<(xx-1));
        edge.emplace_back(xx,xx+1,0);
    }
    int d=L-1-cur;
    for(int i=0;i<xx;i++)
    {
        if(d>>i&1)
        {
            edge.emplace_back(i+1,xx+1,cur+1);
            cur+=1<<i;
        }
    }
    assert(cur==L-1);
    cout<<xx+1<<" "<<edge.size()<<'\n';
    for(auto u:edge)
    {
        int x,y,z;
        tie(x,y,z)=u;
        cout<<x<<" "<<y<<" "<<z<<'\n';
    }
}