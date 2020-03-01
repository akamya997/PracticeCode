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
const int maxn=1e5+7;
int cnt[maxn][2];
int main()
{
    int n;
    cin>>n;
    vi a(n/2),b(n/2);
    for(int i=0;i<n;i++)
    {
        if(i&1) cin>>b[i/2];
        else cin>>a[i/2];
    }
    int mxa=0,mxb=0;
    for(int i=0;i<n/2;i++)
    {
        cnt[a[i]][0]++;
        cnt[b[i]][1]++;
        if(cnt[a[i]][0]>cnt[mxa][0]) mxa=a[i];
        if(cnt[b[i]][1]>cnt[mxb][1]) mxb=b[i];
    }
    if(mxa==mxb)
    {
        int mxxa=0,mxxb=0;
        for(int i=0;i<n/2;i++)
        {
            if(a[i]!=mxa)
            {
                if(cnt[a[i]][0]>cnt[mxxa][0]) mxxa=a[i];
            }
            if(b[i]!=mxb)
            {
                if(cnt[b[i]][1]>cnt[mxxb][1]) mxxb=b[i];
            }
        }
        int ans=min(n/2-cnt[mxa][0]+n/2-cnt[mxxb][1],n/2-cnt[mxxa][0]+n/2-cnt[mxb][1]);
        print(ans);
    }
    else{
        print(n/2-cnt[mxa][0]+n/2-cnt[mxb][1]);
    }

}