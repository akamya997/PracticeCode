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
int r,c,n;
struct P{
    int x,y;
};
struct L{
    P a,b;
};
bool onEdge(P a)
{
    return a.x==0||a.x==r||a.y==0||a.y==c;
}
int main()
{
    cin>>r>>c>>n;
    vc<L> all(n);
    vc<P> D,U,L,R;
    for(int i=0;i<n;i++)
    {
        cin>>all[i].a.x>>all[i].a.y>>all[i].b.x>>all[i].b.y;
        if(onEdge(all[i].a)&&onEdge(all[i].b))
        {
            if(all[i].a.x==0)
                U.push_back(P{all[i].a.y,i});
            else if(all[i].a.x==r)
                D.push_back(P{all[i].a.y,i});
            else if(all[i].a.y==0)
                L.push_back(P{all[i].a.x,i});
            else if(all[i].a.y==c)
                R.push_back(P{all[i].a.x,i});
            if(all[i].b.x==0)
                U.push_back(P{all[i].b.y,i});
            else if(all[i].b.x==r)
                D.push_back(P{all[i].b.y,i});
            else if(all[i].b.y==0)
                L.push_back(P{all[i].b.x,i});
            else if(all[i].b.y==c)
                R.push_back(P{all[i].b.x,i});
        }
    }
    sort(D.begin(),D.end(),[&](P i,P j){return i.x>j.x;});
    sort(L.begin(),L.end(),[&](P i,P j){return i.x>j.x;});
    sort(R.begin(),R.end(),[&](P i,P j){return i.x<j.x;});
    sort(U.begin(),U.end(),[&](P i,P j){return i.x<j.x;});
    stack<int> cc;
    for(auto u:D) 
    {
        if(!cc.empty()&&cc.top()==u.y) cc.pop();
        else cc.push(u.y);
    }
    for(auto u:L) 
    {
        if(!cc.empty()&&cc.top()==u.y) cc.pop();
        else cc.push(u.y);
    }
    for(auto u:U) 
    {
        if(!cc.empty()&&cc.top()==u.y) cc.pop();
        else cc.push(u.y);
    }
    for(auto u:R) 
    {
        if(!cc.empty()&&cc.top()==u.y) cc.pop();
        else cc.push(u.y);
    }
    if(cc.empty()) cout<<"YES\n";
    else cout<<"NO\n";
}