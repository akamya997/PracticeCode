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
int ans2=0;
int cur;
bool ok;
int dfs(int u,int fa=-1)
{
    vi sonlen;
    for(auto v:G[u])if(v!=fa)
    {
        int ret=dfs(v,u);
        sonlen.push_back(ret+1);
    }
    if(fa==-1&&G[u].size()%2==0)
    {
        sort(sonlen.begin(),sonlen.end());
        for(int l=0,r=sonlen.size()-1;l<r;l++,r--)
            if(sonlen[l]+sonlen[r]>cur) ok=0;
        return 0;
    }
    if(sonlen.size()%2==0) sonlen.push_back(0);
    sort(sonlen.begin(),sonlen.end());
    int L=0,R=sonlen.size()-1,ret=-1;
    while(L<=R)
    {
        int mid=L+R>>1;
        bool yes=1;
        for(int l=0,r=sonlen.size()-1;l<r;l++,r--)
        {
            if(l==mid) l++;
            if(r==mid) r--;
            if(sonlen[l]+sonlen[r]>cur) yes=0;
        }
        if(yes){
            ret=mid;
            R=mid-1;
        }
        else L=mid+1;
    }
    if(ret==-1){
        ok=0;
        ret=0;    
    }
    return sonlen[ret];
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
    int ans1=0,odd=0;
    for(int i=1;i<=n;i++)
        if(G[i].size()&1) odd++;
    ans1=odd/2;
    int L=1,R=n-1,ans2=-1;
    while(L<=R)
    {
        cur=L+R>>1;
        ok=1;
        int ret=dfs(1);
        //dbg(cur,ok);
        if(ret>cur) ok=0;
        if(ok)
        {
            ans2=cur;
            R=cur-1;
        }
        else L=cur+1;
    }
    cout<<ans1<<" "<<ans2<<'\n';
}