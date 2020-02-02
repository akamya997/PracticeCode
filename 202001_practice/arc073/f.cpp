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
const ll INF=0x3f3f3f3f3f3f3f3f;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
int n,q,a,b;
struct Sgt{
    ll sum[maxn<<2];
    ll lz[maxn<<2];
    inline void pushdown(int o)
    {
        if(lz[o])
        {
            sum[lson]+=lz[o];
            sum[rson]+=lz[o];
            lz[lson]+=lz[o];
            lz[rson]+=lz[o];
            lz[o]=0;
        }
    }
    void modify(int p,ll val,int L=1,int R=n,int o=1)
    {
        if(L==R)
        {
            sum[o]=val;
            return;
        }
        pushdown(o);
        int mid=L+R>>1;
        if(p<=mid) modify(p,val,Lson);
        else modify(p,val,Rson);
        sum[o]=min(sum[lson],sum[rson]);
    }
    void add(int l,int r,int val,int L=1,int R=n,int o=1)
    {
        if(l<=L&&r>=R)
        {
            sum[o]+=val;
            lz[o]+=val;
            return;
        }
        pushdown(o);
        int mid=L+R>>1;
        if(l<=mid) add(l,r,val,Lson);
        if(r>mid) add(l,r,val,Rson);
        sum[o]=min(sum[lson],sum[rson]);
    }
    ll query(int l,int r,int L=1,int R=n,int o=1)
    {
        if(l<=L&&r>=R)
            return sum[o];
        pushdown(o);
        int mid=L+R>>1;
        ll ret=INF;
        if(l<=mid) ret=min(ret,query(l,r,Lson));
        if(r>mid) ret=min(ret,query(l,r,Rson));
        return ret;
    }
}Tp,Tm,Ta;
int main()
{
    cin>>n>>q>>a>>b;
    memset(Tm.sum,0x3f,sizeof(Tm.sum));
    memset(Tp.sum,0x3f,sizeof(Tp.sum));
    memset(Ta.sum,0x3f,sizeof(Ta.sum));
    int tt;
    cin>>tt;
    int d=abs(tt-a);
    Ta.modify(b,d);
    Tm.modify(b,d-b);
    Tp.modify(b,d+b);
    d=abs(tt-b);
    Ta.modify(a,d);
    Tm.modify(a,d-a);
    Tp.modify(a,d+a);
    
    //for(int j=1;j<=n;j++) dbg(j,Ta.query(j,j),Tm.query(j,j),Tp.query(j,j));
    for(int i=1,x;i<q;i++)
    {
        cin>>x;
        d=abs(tt-x);
        ll minv=min(Tm.query(1,x)+x,Tp.query(x,n)-x);
        Ta.add(1,n,d);
        Tm.add(1,n,d);
        Tp.add(1,n,d);
        ll curv=Ta.query(tt,tt);
        if(curv>minv)
        {
            Ta.modify(tt,minv);
            Tp.modify(tt,minv+tt);
            Tm.modify(tt,minv-tt);
        }
        tt=x;
        //dbg(i,minv);
        //for(int j=1;j<=n;j++) dbg(Ta.query(j,j));
    }
    cout<<Ta.query(1,n)<<'\n';
}