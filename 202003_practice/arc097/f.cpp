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
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
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
vi ng[maxn];
vi col;
bool dfs(int u,int fa=-1)
{
    bool ret=col[u];
    for(auto v:G[u])if(v!=fa)
    {
        bool cur=dfs(v,u);
        if(cur)
        {
            ng[u].push_back(v);
            ng[v].push_back(u);
        }
        ret|=cur;
    }
    return ret;
}
int ma=0;
int dfs2(int u,int fa=-1)
{
    vi son(2,0);
    for(auto v:ng[u])if(v!=fa)
        son.push_back(dfs2(v,u));
    sort(son.begin(),son.end());
    reverse(son.begin(),son.end());
    ma=max(ma,col[u]+son[0]+son[1]);
    return col[u]+son[0];
}
int main()
{
    int n;
    cin>>n;
    string s;
    col=vi(n+1);
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin>>s;
    int tot=0;
    int rt=-1;
    for(int i=1;i<=n;i++)
    {
        col[i]=s[i-1]=='W';
        if(s[i-1]=='W')
        {
            tot++;
            rt=i;
        }
    }
    if(tot==0) print(0);
    if(tot==1) print(1);
    if(tot<=1) return 0;
    dfs(rt);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=ng[i].size();
        col[i]^=((int)ng[i].size()&1);
        if(col[i]==1) ans++;
    }
    dfs2(rt);
    //dbg(ans,ma);
    print(ans-2*ma);
}