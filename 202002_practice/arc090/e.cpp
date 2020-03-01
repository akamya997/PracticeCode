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
ll dis[2][maxn];
bool vis[maxn];
struct Edge{
    int to,w;
};
vc<Edge> G[maxn];
struct D{
    ll dis;int u;
    bool operator<(const D& a)const{
        return dis>a.dis;
    }
};
void dij(int st,int t)
{
    memset(dis[t],0x3f,sizeof(dis[t]));
    memset(vis,0,sizeof(vis));
    dis[t][st]=0;
    priority_queue<D> q;
    q.push(D{0,st});
    while(!q.empty())
    {
        auto u=q.top();q.pop();
        if(vis[u.u]) continue;
        vis[u.u]=1;
        for(auto& e:G[u.u])
        {
            int v=e.to;
            if(dis[t][v]>dis[t][u.u]+e.w)
            {
                dis[t][v]=dis[t][u.u]+e.w;
                q.push(D{dis[t][v],v});
            }
        }
    }
}
bool onpath[maxn];
vi path;
tuple<int,int,int> edge[maxn*2];
const int mod=1e9+7;
ll dp[2][maxn];
int main()
{
    int n,m;
    int s,t;
    cin>>n>>m>>s>>t;
    for(int i=0,u,v,w;i<m;i++)
    {
        cin>>u>>v>>w;
        G[u].push_back(Edge{v,w});
        G[v].push_back(Edge{u,w});
        edge[i]=tuple<int,int,int>{u,v,w};
    }
    dij(s,0);
    ll len=dis[0][t];
    dij(t,1);
    assert(len==dis[1][s]);
    for(int i=0,u,v,w;i<m;i++)
    {
        tie(u,v,w)=edge[i];
        if(dis[0][u]+w+dis[1][v]==len||dis[0][v]+w+dis[1][u]==len)
            onpath[u]=onpath[v]=1;
    }
    for(int i=1;i<=n;i++) if(onpath[i]) path.push_back(i);
    sort(path.begin(),path.end(),[&](int u,int v){return dis[0][u]<dis[0][v];});
    dp[0][s]=1;
    dp[1][t]=1;
    for(int j=0;j<2;j++)
    {
        for(auto u:path)
        {
            for(auto& e:G[u])
            {
                int v=e.to;
                if(dis[j][v]+e.w+dis[j^1][u]==len)
                    dp[j][u]=(dp[j][u]+dp[j][v])%mod;
            }
        }
        reverse(path.begin(),path.end());
    }
    assert(dp[0][t]==dp[1][s]);
    //dbg(dp[0][t],dp[1][s]);
    ll ans=1LL*dp[0][t]*dp[0][t]%mod;
    for(int i=1;i<=n;i++)
    {
        if(onpath[i]&&dis[0][i]==dis[1][i])
            ans=(ans-1LL*dp[0][i]*dp[1][i]%mod*dp[0][i]%mod*dp[1][i]%mod+mod)%mod;
    }
    for(int i=0,u,v,w;i<m;i++)
    {
        tie(u,v,w)=edge[i];
        if(dis[0][u]>dis[0][v]) swap(u,v);
        if(dis[0][u]+dis[1][v]+w==len)
        {
            if(dis[0][u]<dis[1][v]+w&&dis[1][v]<dis[0][u]+w) ans=(ans-1LL*dp[0][u]*dp[1][v]%mod*dp[0][u]%mod*dp[1][v]%mod+mod)%mod;
        }
    }
    print(ans);
}