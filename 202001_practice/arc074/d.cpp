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
    vi a(n*3+1);
    for(int i=1;i<=3*n;i++) cin>>a[i];
    ll mx=0,mi=0;
    priority_queue<int,vector<int>,greater<int>> ql;
    multiset<pi> qr,re;
    for(int i=1;i<=n;i++) ql.push(a[i]),mx+=a[i];
    for(int i=n+1;i<=3*n;i++)
    {
        qr.insert(make_pair(a[i],i));
        mi+=a[i];
    }
    while(qr.size()>n)
    {
        mi-=(*qr.rbegin()).first;
        re.insert(*qr.rbegin());
        qr.erase(qr.find(*qr.rbegin()));
    }
    ll ans=-0x3f3f3f3f3f3f3f3f;
    for(int i=n+1;i<=2*n+1;i++)
    {
        ans=max(ans,mx-mi);
        if(i==2*n+1) break;
        ql.push(a[i]);
        mx+=a[i];
        mx-=ql.top();
        ql.pop();
        if(re.count(make_pair(a[i],i)))
            re.erase(make_pair(a[i],i));
        if(qr.count(make_pair(a[i],i)))
        {
            mi-=a[i];
            qr.erase(make_pair(a[i],i));
            qr.insert(*re.begin());
            mi+=(*re.begin()).first;
            re.erase(re.begin());
        }
    }
    cout<<ans<<'\n';

}