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
int nxt[maxn][26];
bool vis[maxn];
pi pre[maxn];
string s;
void pr(pi x)
{
    if(x.first)
        pr(pre[x.first]);
    cout<<(char)(x.second+'a');
}
int main()
{
    cin>>s;
    int cur[26];
    memset(cur,-1,sizeof(cur));
    for(int i=0;i<26;i++) cur[i]=maxn-1;
    for(int i=0;i<maxn;i++)
    {
        for(int j=0;j<26;j++) nxt[i][j]=maxn-1;
    }
    for(int i=s.length();i>=0;i--)
    {
        for(int j=0;j<26;j++) nxt[i][j]=cur[j];
        if(i)
            cur[s[i-1]-'a']=i;
    }
    queue<int> q;
    q.push(0);
    vis[0]=1;
    while(!q.empty())
    {
        auto u=q.front();q.pop();
        //dbg(u.id);
        if(u==maxn-1)
        {
            pr(pre[u]);
            cout<<'\n';
            break;
        }
        for(int j=0;j<26;j++)
        {
            int nn=nxt[u][j];
            if(!vis[nn])
            {
                vis[nn]=1;
                pre[nn]=make_pair(u,j);
                q.push(nn);
            }
        }
    }
}