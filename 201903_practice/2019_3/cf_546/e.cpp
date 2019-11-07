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
long long sum[maxn*4];
long long lazy[maxn*4];
long long k[maxn];
long long pre[maxn];
const long long INF=0x3f3f3f3f3f3f3f3f;
long long prepre[maxn];
void pushup(int rt)
{
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}
void build(int l,int r, int rt)
{
	if(l==r)
	{
		scanf("%lld",&sum[rt]);
		return;
	}
	int mid=l+r>>1;
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
	pushup(rt);
}
void pushdown(int rt,int L,int R)
{
	if(lazy[rt]==INF) return;
	int mid=L+R>>1;
	lazy[rt*2]=lazy[rt*2+1]=lazy[rt];
	sum[rt*2]=prepre[mid]-prepre[L-1]+lazy[rt]*(mid-L+1);
	sum[rt*2+1]=prepre[R]-prepre[mid]+lazy[rt]*(R-mid);
	lazy[rt]=INF;
	dbg(L);dbg(R);
	dbg(sum[rt*2]);
	dbg(sum[rt*2+1]);
}
void update(int l,int r,long long val,int L,int R,int rt)
{
	if(l<=L&&r>=R)
	{
		sum[rt]=prepre[R]-prepre[L-1]+val*(R-L+1);
		dbg(sum[rt]);
		lazy[rt]=val;
		return;
	}
	pushdown(rt,L,R);
	int mid=L+R>>1;
	if(l<=mid)
		update(l,r,val,L,mid,rt*2);
	if(r>mid) update(l,r,val,mid+1,R,rt*2+1);
	pushup(rt);
}
long long query(int l,int r,int L,int R,int rt)
{
	if(l<=L&&r>=R)
	{
		return sum[rt];
	}
	pushdown(rt,L,R);
	long long ret=0;
	int mid=L+R>>1;
	if(l<=mid) ret+=query(l,r,L,mid,rt*2);
	if(r>mid) ret+=query(l,r,mid+1,R,rt*2+1);
	return ret;
}
void output(int l,int r,int rt)
{
	if(l==r) cout<<sum[rt]<<" ";
	else{
		int mid=l+r>>1;
		pushdown(rt,l,r);
		output(l,mid,rt*2);
		output(mid+1,r,rt*2+1);
	}
}
int main()
{
	for(int i=0;i<maxn*4;i++) lazy[i]=INF;
	int n;
	scanf("%d",&n);
	build(1,n,1);
	for(int i=1;i<n;i++) scanf("%lld",&k[i]);
	for(int i=1;i<n;i++) pre[i]=pre[i-1]+k[i];
	for(int i=1;i<=n;i++) prepre[i]=prepre[i-1]+pre[i];
	int q;
	scanf("%d",&q);
	char op[10];
	while(q--)
	{
		scanf("%s",op);
		if(op[0]=='+')
		{
			long long i,x;
			int l=1,r=n+1,pos=n;
			scanf("%lld%lld",&i,&x);
			l=i;
			long long cur=query(i,i,1,n,1);
			while(l<r)
			{
				int mid=l+r>>1;
				if(cur+x+pre[mid-1]-pre[i-2>0?i-2:0]>query(mid,mid,1,n,1)) l=mid+1,pos=mid;
				else r=mid;
			}
			dbg(pos);
			dbg(x+cur-pre[i-2>0?i-2:0]);
			update(i+1,pos,x+cur-pre[i-2>0?i-2:0],1,n,1);
			update(i,i,x+cur,1,n,1);
		}
		else
		{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(l,r,1,n,1));
		}
		//output(1,n,1);
		//puts("");
	}
}
