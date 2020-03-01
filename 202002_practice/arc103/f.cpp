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
typedef pair<ll,int> pi;
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
ll sum[maxn];
map<ll,int> id;
vi G[maxn];
int sz[maxn];
ll rs=0;
bool ok=1;
void dfs(int u,int d=0)
{
    rs+=d;
    for(auto v:G[u])
    {
        dfs(v,d+1);
    }
}
int main()
{
    int n;
    cin>>n;
    priority_queue<pi> q;
    for(int i=1;i<=n;i++) 
    {
        cin>>sum[i];
        id[sum[i]]=i;
        q.push(make_pair(sum[i],i));
        sz[i]=1;
    }
    vc<pi> ans;
    while(!q.empty())
    {
        auto u=q.top();q.pop();
        if(q.empty())
        {
            dfs(u.second);
            if(rs!=sum[u.second]) ok=0;
            break;
        }
        ll fad=u.first-(n-2*sz[u.second]);
        if(!id.count(fad)||fad>=u.first)
        {
            ok=0;
            break;
        }
        sz[id[fad]]+=sz[u.second];
        ans.emplace_back(u.second,id[fad]);
        G[id[fad]].push_back(u.second);
    }
    if(!ok) print(-1);
    else{
        for(auto u:ans) cout<<u.first<<" "<<u.second<<'\n';
    }
}