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
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
const int maxn=2e5+7;
int lz[maxn<<2];
int mx[maxn<<2];
pi seg[maxn];
vi rr[maxn];
int n,m;
const int INF=0x3f3f3f3f;
void build(int L=0,int R=m+1,int o=1)
{
    if(L==R)
    {
        mx[o]=-m+L-1;
        return;
    }
    int mid=L+R>>1;
    build(Lson);
    build(Rson);
    mx[o]=max(mx[lson],mx[rson]);
}
inline void pushdown(int o)
{
    if(lz[o])
    {
        mx[lson]+=lz[o];
        mx[rson]+=lz[o];
        lz[lson]+=lz[o];
        lz[rson]+=lz[o];
        lz[o]=0;
    }
}
void update(int l,int r,int L=0,int R=m+1,int o=1)
{
    if(l<=L&&r>=R)
    {
        lz[o]++;
        mx[o]++;
        return;
    }
    pushdown(o);
    int mid=L+R>>1;
    if(l<=mid) update(l,r,Lson);
    if(r>mid) update(l,r,Rson);
    mx[o]=max(mx[lson],mx[rson]);
}
int query(int l,int r,int L=0,int R=m+1,int o=1)
{
    if(l<=L&&r>=R)
        return mx[o];
    pushdown(o);
    int mid=L+R>>1;
    int ret=-INF;
    if(l<=mid) ret=max(ret,query(l,r,Lson));
    if(r>mid) ret=max(ret,query(l,r,Rson));
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++) 
    {
        cin>>seg[i].first>>seg[i].second;
        rr[seg[i].first].push_back(seg[i].second);
    }
    build();
    int ans=n-m;
    for(int i=0;i<=m;i++)
    {
        for(auto u:rr[i])
            update(0,u);
        //dbg(i,query(i+1,m+1));
        ans=max(ans,-i+query(i+1,m+1));
    }
    cout<<ans<<'\n';
}