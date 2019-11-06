#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1)
            ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
ll inv(ll a){return quick(a,mod-2);}
const int maxn=1e5+7;
int arr[maxn];
int mx[maxn<<2];
int pp[maxn];
int n,m;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
void build(int L=1,int R=n,int o=1)
{
    if(L==R)
    {
        mx[o]=pp[L];
        return ;
    }
    int mid=L+R>>1;
    build(Lson);
    build(Rson);
    mx[o]=max(mx[lson],mx[rson]);
}
void update(int val,int L=1,int R=n,int o=1)
{
    if(L==R)
    {
        mx[o]=INF;
        return;
    }
    int mid=L+R>>1;
    if(val<=mid) update(val,Lson);
    else update(val,Rson);
    mx[o]=max(mx[lson],mx[rson]);
}
int query(int l,int r,int var,int L=1,int R=n,int o=1)
{
    if(l<=L&&r>=R)
        return mx[o];
    int mid=L+R>>1;
    int ret=0;
    if(l<=mid&&mx[lson]>var) ret=max(ret,query(l,r,var,Lson));
    if(r>mid&&ret<mx[rson]&&mx[rson]>var) ret=max(ret,query(l,r,var,Rson));
    return ret;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
            pp[arr[i]]=i;
        }
        build();
        int lastans=0;
        while(m--)
        {
            int op,t1,t2,t3;
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d",&t1);
                int pos=t1^lastans;
                update(arr[pos]);
            }
            else{
                scanf("%d%d",&t2,&t3);
                int r=t2^lastans,k=t3^lastans;
                int L=k,R=n,ans=k-1;
                while(L<=R)
                {
                    int mid=L+R>>1;
                    int mxx=query(k,mid,r);
                    if(mxx>r)
                        R=mid-1;
                    else L=mid+1,ans=mid;
                }
                lastans=ans+1;
                printf("%d\n",lastans);
            }
        }
    }
}
