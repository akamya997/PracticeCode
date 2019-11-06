#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=1e6+7;
int sum[maxn<<2],lz[maxn<<2];
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
int len;
void pushup(int o)
{
	sum[o]=sum[lson]+sum[rson];
}
void pushdown(int o,int len)
{
	if(lz[o])
	{
		lz[lson]=1;
		lz[rson]=1;
		sum[lson]=len-len/2;
		sum[rson]=len/2;
		lz[o]=0;
	}
}
void update(int l,int r,int L=0,int R=len,int o=1)
{
	if(l<=L&&r>=R)
	{
		sum[o]=R-L+1;
		lz[o]=1;
		return;
	}
	pushdown(o,R-L+1);
	int mid=L+R>>1;
	if(l<=mid) update(l,r,Lson);
	if(r>mid) update(l,r,Rson);
	pushup(o);
}
int query(int l,int r,int L=0,int R=len,int o=1)
{
	if(l<=L&&r>=R)
		return sum[o];
	pushdown(o,R-L+1);
	int mid=L+R>>1;
	int ret=0;
	if(l<=mid) ret+=query(l,r,Lson);
	if(r>mid) ret+=query(l,r,Rson);
	return ret;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);

}
