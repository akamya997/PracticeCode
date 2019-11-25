#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn=2e5+7;
struct node{
	int l,r,sz;
}sgt[maxn*10];
int arr[maxn];
int rt[maxn];
vector<int> all;
int cur=0;
void build(int& o,int l,int r)
{
	o=++cur;
	if(l==r) return;
	int mid=l+r>>1;
	build(sgt[o].l,l,mid);
	build(sgt[o].r,mid+1,r);
}
void pushup(int o)
{
	sgt[o].sz=sgt[sgt[o].l].sz+sgt[sgt[o].r].sz;
}
void update(int& o,int last,int l,int r,int pos)
{
	o=++cur;
	sgt[o]=sgt[last];
	if(l==r)
	{
		sgt[o].sz++;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) update(sgt[o].l,sgt[last].l,l,mid,pos);
	if(pos>mid) update(sgt[o].r,sgt[last].r,mid+1,r,pos);
	pushup(o);
}
int query(int l,int r,int L,int R,int k)
{
	int num=sgt[sgt[r].l].sz-sgt[sgt[l].l].sz;
	if(L==R) return R;
	int mid=L+R>>1;
	if(k<=num) return query(sgt[l].l,sgt[r].l,L,mid,k);
	return query(sgt[l].r,sgt[r].r,mid+1,R,k-num);
}
int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&arr[i]);
		all.push_back(arr[i]);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	build(rt[0],1,all.size());
	for(int i=1;i<=n;i++) update(rt[i],rt[i-1],1,all.size(),getid(arr[i]));
	while(m--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",all[query(rt[l-1],rt[r],1,all.size(),k)-1]);
	}
}
