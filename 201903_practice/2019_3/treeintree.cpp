#include<bits/stdc++.h>
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
const int maxn=1e5+7;
struct sgt{
	int l,r,cnt;
}seg[maxn*10];
struct query{
	char op[3];
	int i,j,k,t;
}Q[maxn/2];
int tot=0;
int rt[maxn];
int arr[maxn];
vector<int> all;
int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
void pushup(int o){seg[o].cnt=seg[seg[o].l].cnt+seg[seg[o].r].cnt;}
void build(int& o,int l,int r)
{
	o=++tot;
	if(l==r)
	{
		seg[o].cnt=0;
		return;
	}
	int mid=l+r>>1;
	build(seg[o].l,l,mid);
	build(seg[o].r,mid+1,r);
	pushup(o);
}
void update(int& o,int val,int d,int L,int R)
{
	if(!o) 
	{
		o=++tot;
		seg[o]
	}
}
void add(int x,int val,int d)
{
	while(x<maxn)
	{
		update(rt[x],val,d,1,all.size());
		x+=x&-x;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(rt,0,sizeof(rt));
		tot=0;
		all.clear();
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&arr[i]);
			all.push_back(arr[i]);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%s",Q.op);
			if(Q.op[0]=='Q')
				scanf("%d%d%d",&Q[i].i,&Q[i].j,&Q[i].k);
			else 
			{
				scanf("%d%d",&Q[i].i,&Q[i].t);
				all.push_back(Q[i].t);
			}
		}
		sort(all.begin(),all.end());
		all.erase(unique(all.begin(),all.end()),all.end());
		build(rt[0],1,all.size());
		for(int i=1;i<=n;i++) add(rt[i],getid(arr[i]),1);
	}
}
