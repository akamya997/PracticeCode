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
int pp[105];
bool vis[105];
pi p[105],p2[105];
int n;
bool dfs(int u)
{
    if(vis[u]) return false;
    vis[u]=1;
    for(int i=1;i<=n;i++)
    {
        if(p[u].first<p2[i].first&&p[u].second<p2[i].second)
        {
            if(!pp[i]||dfs(pp[i]))
            {
                pp[i]=u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    for(int i=1;i<=n;i++) cin>>p2[i].first>>p2[i].second;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ans++;
    }
    print(ans);
}