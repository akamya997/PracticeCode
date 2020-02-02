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
    int n,d,a;
    cin>>n>>d>>a;
    vc<pi> mon(n);
    for(int i=0;i<n;i++)
        cin>>mon[i].first>>mon[i].second;
    sort(mon.begin(),mon.end());
    ll ans=0;
    deque<ll> q;
    q.push_back(mon[0].second);
    int l=0;
    int p=1;
    while(l<n)
    {
        while(p<n&&mon[p].first-mon[l].first<=2*d)
        {
            q.push_back(mon[p].second+ans*a);
            p++;
        }
        ans=max(ans,(q.front()+a-1)/a);
        q.pop_front();
        l++;
    }
    cout<<ans<<'\n';
}