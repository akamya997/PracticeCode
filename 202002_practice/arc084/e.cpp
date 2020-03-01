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
int n,k;
vi ans;
int pos;
void forword()
{
    //dbg(ans);
    if(ans[pos])
    {
        ans[pos]--;
        if(ans[pos])
        {
            for(int j=pos+1;j<n;j++) ans[j]=k;
            pos=n-1;
        }
        else pos--;
    }
}
int main()
{
    cin>>k>>n;
    if(k%2==0)
    {
        ans=vi(n);
        ans[0]=k/2;
        for(int i=1;i<n;i++) ans[i]=k;
    }
    else {
        pos=n-1;
        ans=vi(n,(k+1)/2);
        for(int i=0;i<n/2;i++)
            forword();
        while(!ans.back()) ans.pop_back();
    }
    print(ans);
}
