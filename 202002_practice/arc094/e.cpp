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
struct D{
    int a,b;
    bool operator<(const D& x)const{
        return b>x.b;
    }
};
int main()
{
    vc<D> all;
    int n;
    cin>>n;
    ll ans=0;
    ll cc=0;
    bool sa=1;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a-b<0) cc+=b-a,ans+=b;
        else{
            if(a!=b) sa=0;
            all.push_back({a,b});
        }
    }
    if(!sa)
    {
        vc<D> res;
        for(auto u:all)
        {
            if(u.a==u.b) ans+=u.b;
            else res.push_back(u);
        }
        sort(res.begin(),res.end());
        for(int i=0;i<res.size()-1;i++) ans+=res[i].b;
    }
    print(ans);

}