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
int fa[maxn];
vi G[maxn];
bool vis[maxn];
bool lp[maxn];
int a[maxn];
void dfs(int u)
{
    vis[u]=1;
    set<int> all;
    for(auto v:G[u])
    {
        if(vis[v]) continue;
        dfs(v);
        all.insert(a[v]);
    }
    for(int i=0;;i++)
    {
        if(!all.count(i))
        {
            a[u]=i;
            return;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>fa[i];
        G[fa[i]].push_back(i);
    }
    int rt;
    for(rt=1;!vis[rt];rt=fa[rt]) vis[rt]=1;
    memset(vis,0,sizeof(vis));
    int len=0;
    for(;!vis[rt];rt=fa[rt]) vis[rt]=1,lp[rt]=1;
    for(int i=1;i<=n;i++)if(lp[i]) dfs(i),len++;
    memset(vis,0,sizeof(vis));
    bool ok=0;
    for(;!vis[rt];rt=fa[rt])
    {
        vis[rt]=1;
        if(a[fa[rt]]!=a[rt])
        {
            ok=1;
            break;
        }
    }
    //for(int i=1;i<=n;i++) dbg(i,a[i]);
    if(ok||(len%2==0)) cout<<"POSSIBLE\n";
    else cout<<"IMPOSSIBLE\n";
    
}