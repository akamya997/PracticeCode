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
const int maxn=705;
int G[maxn][maxn];
vi g[maxn];
int col[maxn];
bool ok=1;
int n,m;
pi dfs(int u,int c)
{
    col[u]=c;
    pi ret={0,0};
    if(c) ret.second++;
    else ret.first++;
    for(auto i:g[u])
    {
        if(col[i]!=-1&&col[i]==c)
        {
            ok=0;
            return ret;
        }
        else if(col[i]==-1)
        {
            auto cur=dfs(i,c^1);
            ret.first+=cur.first;
            ret.second+=cur.second;
        }
    }
    return ret;
}
int main()
{
    cin>>n>>m;
    for(int i=0,u,v;i<m;i++)
    {
        cin>>u>>v;
        G[u][v]=G[v][u]=1;
    }
    int cc=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++) 
        {
            if(!G[i][j])
            {
                g[i].push_back(j);
                g[j].push_back(i);
                cc++;
            }
        }
    int ans;
    memset(col,-1,sizeof(col));
    vc<vi> dp(2,vi(n+1));
    int t=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(col[i]==-1)
        {
            pi cur=dfs(i,0);
            if(!ok) break;
            dp[t^1]=vi(n+1,0);
            for(int j=n;j>=0;j--)
            {
                if(j>=cur.second)
                    dp[t^1][j]|=dp[t][j-cur.second];
                if(j>=cur.first)
                    dp[t^1][j]|=dp[t][j-cur.first];
            }
            t^=1;
        }
    }
    if(!ok) ans=-1;
    else
    {
        int tmp=0;
        for(int i=1;i<=n;i++)
        {
            if(dp[t][i]) tmp=max(tmp,i*(n-i));
        }
        ans=m-(tmp-cc);
    }
    print(ans);
}