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
const int maxn=2e5+7;
ll base[maxn],cf[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vi a(n),d(n);
    ll ans=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++) 
    {
        d[i]=(a[i]-a[i-1]+m)%m,ans+=d[i];
        if(a[i]>a[i-1])
        {
            cf[a[i-1]+2]++;
            cf[a[i]+1]--;
            base[a[i]+1]-=d[i]-1;
        }
        else{
            base[1]+=d[i]-a[i];
            cf[2]++;
            cf[a[i]+1]--;
            base[a[i]+1]-=d[i]-1;
            cf[a[i-1]+2]++;
        }
    }
    ll mx=0;
    ll cur=0,cc=0;
    for(int i=1;i<=m;i++)
    {
        cc+=cf[i];
        cur+=base[i];
        cur+=cc;
        mx=max(mx,cur);
        dbg(i,cur);
    }
    cout<<ans-mx<<'\n';

}