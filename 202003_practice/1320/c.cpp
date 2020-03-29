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
const int maxv=1e6+7;
struct D{
    int v,cv;
}a[maxn];
struct Event{
    int x,y,v;
    bool operator<(const Event &a)const{
        if(x==a.x)  return y<a.y;
        return x<a.x;
    }
};
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
ll mx[maxv<<2];
ll lz[maxv<<2];
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
void modify(int p,int val,int L=1,int R=maxv-1,int o=1)
{
    if(L==R)
    {
        mx[o]=max(mx[o],1LL*val);
        return;
    }
    int mid=L+R>>1;
    if(p<=mid) modify(p,val,Lson);
    else modify(p,val,Rson);
    mx[o]=max(mx[lson],mx[rson]);
}
void add(int l,int r,int val,int L=1,int R=maxv-1,int o=1)
{
    if(l<=L&&r>=R)
    {
        mx[o]+=val;
        lz[o]+=val;
        return;
    }
    int mid=L+R>>1;
    pushdown(o);
    if(l<=mid) add(l,r,val,Lson);
    if(r>mid) add(l,r,val,Rson);
    mx[o]=max(mx[lson],mx[rson]);
}
ll query(int l,int r,int L=1,int R=maxv-1,int o=1)
{
    if(l<=L&&r>=R)
        return mx[o];
    int mid=L+R>>1;
    pushdown(o);
    ll ret=-0x3f3f3f3f3f3f3f3f;
    if(l<=mid) ret=max(ret,query(l,r,Lson));
    if(r>mid) ret=max(ret,query(l,r,Rson));
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(mx,-0x3f,sizeof(mx));
    int n,m,p;
    cin>>n>>m>>p;
    vc<Event> all;
    for(int i=0,v,cv;i<n;i++)
    {
        cin>>v>>cv;
        all.push_back(Event{v,-1,cv});
    }
    for(int i=0;i<m;i++)
    {
        cin>>a[i].v>>a[i].cv;
        modify(a[i].v,-a[i].cv);
    }
    for(int i=0,x,y,z;i<p;i++)
    {
        cin>>x>>y>>z;
        all.push_back(Event{x,y,z});
    }
    sort(all.begin(),all.end());
    ll ans=-0x3f3f3f3f3f3f3f3f;
    for(auto u:all)
    {
        //dbg(u.x,u.y,u.v);
        if(u.y==-1)
            ans=max(ans,query(1,maxv-1)-u.v);
        else{
            add(u.y+1,maxv-1,u.v);
        }
    }
    print(ans);
}