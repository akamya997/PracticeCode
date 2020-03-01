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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vi b(n);
    for(int i=0;i<n;i++) 
        cin>>b[i];
    int ans=0;
    for(int i=28;i>=0;i--)
    {
        for(int j=0;j<n;j++) b[j]%=1<<(i+1);
        sort(b.begin(),b.end());
        ll cc=0;
        for(int j=0;j<n;j++)
        {
            a[j]%=1<<(i+1);
            cc+=lower_bound(b.begin(),b.end(),2*(1<<i)-a[j])-lower_bound(b.begin(),b.end(),(1<<i)-a[j]);
            cc+=lower_bound(b.begin(),b.end(),4*(1<<i)-a[j])-lower_bound(b.begin(),b.end(),3*(1<<i)-a[j]);
            //dbg(i,j,cc);
        }
        if(cc&1) ans|=1<<i;
    }
    print(ans);
}