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
    int n,a,b;
    cin>>n>>a>>b;
    deque<int> ans;
    for(int i=1;i<=a;i++) ans.push_back(i);
    if(b-1+a>n||1LL*a*b<n)
        print(-1);
    else{
        vi sz(b-1,1);
        int tot=b-1+a;
        for(int i=0;i<b-1;i++)
        {
            while(sz[i]<a&&tot<n)
            {
                tot++;
                sz[i]++;
            }
        }
        assert(tot==n);
        int p=a+1;
        for(int i=0;i<b-1;i++)
        {
            vi tmp;
            for(int j=0;j<sz[i];j++)
            {
                tmp.push_back(p);
                p++;
            }
            while(!tmp.empty())
            {
                ans.push_front(tmp.back());
                tmp.pop_back();
            }
        }
        vi op;
        while(!ans.empty())
        {
            op.push_back(ans.front());
            ans.pop_front();
        }
        print(op);
    }
}