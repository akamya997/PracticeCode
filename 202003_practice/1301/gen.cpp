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
int p[25][2]={
{5,2},
{3,1},
{3,5},
{4,2},
{1,3},
{5,4},
{4,1},
{1,1},
{1,4},
{1,2},
{4,3},
{5,3},
{3,3},
{1,5},
{5,5},
{2,3},
{2,2},
{3,2},
{3,4},
{2,4},
{4,5},
{2,5},
{5,1},
{4,4},
{2,1}};
int main()
{
    int cc=0;
    for(int i=0;i<25;i++)
    {
        for(int j=i;j<25;j++)
        {
            if(cc==161) break;
            cout<<p[i][0]<<" "<<p[i][1]<<" "<<p[j][0]<<" "<<p[j][1]<<'\n';
            cc++;
        }
    }
}