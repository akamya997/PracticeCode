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
int pp[15];

string maze[15];
int vis[15];
int h,w;
bool solve()
{
    vvc<pair<char,char>> s(h);
    memset(vis,0,sizeof(vis));
    for(int i=0;i<w;i++)
    {
        if(vis[i]) continue;
        for(int j=0;j<h;j++)
        {
            if(pp[i]==-1)
                s[j].emplace_back(maze[j][i],maze[j][i]);
            else {
                s[j].emplace_back(maze[j][i],maze[j][pp[i]]);
                vis[pp[i]]=1;
            }
        }
    }
    memset(vis,0,sizeof(vis));
    int notok=0;
    for(int i=0;i<h;i++)
    {
        if(vis[i]) continue;
        bool ok=0;
        for(int j=i+1;j<h;j++)
        {
            for(int k=0;k<s[i].size();k++)
            {
                if(s[i][k].first==s[j][k].second&&s[j][k].first==s[i][k].second);
                else break;
                if(k==s[i].size()-1) ok=1;
            }
            if(ok)
            {
                vis[j]=1;
                break;
            }
        }
        if(!ok)
        {
            for(int k=0;k<s[i].size();k++)
                if(s[i][k].first!=s[i][k].second) return false;
            notok++;
        }
    }
    return notok<=(h&1);
}
bool dfs(int u,int p)
{
    if(u==w)
    {
        if(!p) return solve();
        return false;
    }
    if(pp[u]!=-1) return dfs(u+1,p);
    bool ret=0;
    if(p) ret|=dfs(u+1,0);
    for(int i=u+1;i<w;i++)
    {
        if(pp[i]==-1)
        {
            pp[u]=i;
            pp[i]=u;
            ret|=dfs(u+1,p);
            pp[u]=-1;
            pp[i]=-1;
            if(ret) return true;
        }
    }
    return ret;
}
int main()
{
    memset(pp,-1,sizeof(pp));
    cin>>h>>w;
    for(int i=0;i<h;i++) cin>>maze[i];
    if(dfs(0,w&1))
        cout<<"YES\n";
    else cout<<"NO\n";
}