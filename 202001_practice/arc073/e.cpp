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
    int n;
    cin>>n;
    vc<pi> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
        if(a[i].first>a[i].second) swap(a[i].first,a[i].second);
    }
    int mxl=-1,mil=0x3f3f3f3f,mir=0x3f3f3f3f,mxr=-1;
    for(int i=0;i<n;i++)
    {
        mxl=max(mxl,a[i].first);
        mxr=max(mxr,a[i].second);
        mil=min(mil,a[i].first);
        mir=min(mir,a[i].second);
    }
    ll ans=1LL*(mxr-mir)*(mxl-mil);
    int mx=max(mxl,mxr),mi=min(mil,mir);
    sort(a.begin(),a.end());
    mil=0x3f3f3f3f;
    multiset<int> rd;
    for(int i=0;i<n;i++) rd.insert(a[i].first);
    for(int i=0;i<n;i++)
    {
        mxl=max(mxl,a[i].second);
        rd.erase(rd.find(a[i].first));
        rd.insert(a[i].second);
        mil=*rd.begin();
        ans=min(ans,1LL*(mx-mi)*(mxl-mil));
    }

    cout<<ans<<'\n';

}