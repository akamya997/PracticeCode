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
vi G[maxn];
vi lp;
int ce=0,cc;
const int mod=1e9+7;
bool vis[maxn],ins[maxn];
ll quick(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
ll inv(ll a){return quick(a,mod-2);}
int st[maxn];
int p;
int sz[maxn];
vi cG;
int fd=0;
void dfs(int u,int fa=-1)
{
    vis[u]=1;
    ins[u]=1;
    st[p++]=u;
    cc++;
    for(auto v:G[u])
    {
        if(v!=fa)
        {
            if(ins[v])
            {
                ce++;
                fd++;
                if(fd>=2) return ;
                for(int i=p-1;st[i]!=v;i--)
                    lp.push_back(st[i]);
                lp.push_back(v);
            }
            if(!vis[v]) ce++,dfs(v,u);
        }
    }
    ins[u]=0;
    p--;
}
int n;
bool vv[maxn];
vi used;
ll cursz;
vi nG[maxn];
void dfs2(int u,int fa)
{
    vv[u]=1;
    used.push_back(u);
    for(auto v:G[u])
    {
        if(v==fa) continue;
        if(!vv[v])
            dfs2(v,u);
        if(v<fa) {
            nG[u].push_back(v);
        }
    }
}
bool v3[maxn];
void dfs3(int u)
{
    if(v3[u]) return;
    v3[u]=1;
    sz[u]=1;
    for(auto v:nG[u])
    {
        dfs3(v);
        sz[u]+=sz[v];
    }
    cursz=cursz*sz[u]%mod;
    //dbg(u,sz[u]);
}
int main()
{
    cin>>n;
    for(int i=0,x,y;i<2*n;i++)
    {
        cin>>x>>y;
        G[x].push_back(y+n);
        G[y+n].push_back(x);
    }
    for(int i=1;i<=2*n;i++) sort(G[i].begin(),G[i].end());
    ll ans=1;
    for(int i=1;i<=2*n;i++)
    {
        if(!vis[i])
        {
            ce=cc=0;
            p=0;
            fd=0;
            lp.clear();
            dfs(i);
            //dbg(lp);
            if(ce!=cc||fd>=2)
            {
                ans=0;
                break;
            }
            cursz=1;
            dfs2(lp[1],lp[0]);
            for(auto v:used) 
            {
                dfs3(v);
                vv[v]=0;
            }
            //dbg(cursz);
            ll tmp=inv(cursz);
            for(auto v:used) nG[v].clear(),v3[v]=0;
            used.clear();
            dfs2(lp[0],lp[1]);
            cursz=1;
            for(auto v:used)
            {
                dfs3(v);
                vv[v]=0;
            }
            used.clear();
            cursz=(inv(cursz)+tmp)%mod;
            ans=(ans*cursz)%mod;
        }
    }
    for(int i=1;i<=2*n;i++) ans=ans*i%mod;
    print(ans);
}