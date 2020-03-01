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
vi G[maxn];
int sz[maxn];
int dep[maxn];
pi dfs(int u,int fa=-1)
{
    pi ret={0,u};
    sz[u]=1;
    for(auto v:G[u])if(v!=fa)
    {
        dep[v]=dep[u]+1;
        pi cur=dfs(v,u);
        sz[u]+=sz[v];
        cur.first++;
        ret=max(ret,cur);
    }
    return ret;
}
int a,b;
bool ok=1;
bool onpath[maxn];
void check(int u,int d,int fa=-1)
{
    if(dep[u]+d!=dep[b]&&G[u].size()!=1)
    {
        ok=0;
        return;
    }
    if(dep[u]+d==dep[b]) onpath[u]=1;
    for(auto v:G[u])if(v!=fa)
        check(v,d+1,u);
}
vi ans[2];
void getans(int u,int id,int tp,int fa=-1)
{
    int son=G[u].size();
    son--;
    if(u!=a&&u!=b) son--;
    int curid=id;
    id++;
    //dbg(u,son);
    while(son--)
    {
        ans[tp].push_back(id);
        id++;
    }
    ans[tp].push_back(curid);
    for(auto v:G[u])if(v!=fa&&onpath[v])
        getans(v,id,tp,u);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    auto c=dfs(1);
    a=c.second;
    dep[a]=0;
    b=dfs(a).second;
    check(b,0);
    //dbg(a,b);
    if(!ok) print(-1);
    else{
        getans(a,1,0);
        getans(b,1,1);
        print(min(ans[0],ans[1]));
    }
}