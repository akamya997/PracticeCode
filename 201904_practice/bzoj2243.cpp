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
const int maxn=1e5+7;
struct Edge{
	int to,nxt;
}edge[maxn*2];
int head[maxn];
int cnt;
struct Seg{
	int l,r,cnt;
};
void addedge(int u,int v)
{
	edge[cnt]={v,head[u]};
	head[u]=cnt++;
	edge[cnt]={u,head[v]};
	head[v]=cnt++;
}
int n;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,o<<1
#define Rson mid+1,R,o<<1|1
Seg merge(Seg l,Seg r)
{
	if(l.l==-1) return r;
	if(r.l==-1) return l;
	Seg ret;
	ret.l=l.l;ret.r=r.r;
	ret.cnt=l.cnt+r.cnt-(l.r==r.l);
	return ret;
}
namespace sgt{
	Seg seg[maxn*4];
	int lazy[maxn*4];
	void init(){memset(lazy,-1,sizeof(lazy));}
	void pushup(int o)
	{
		seg[o]=merge(seg[lson],seg[rson]);
	}
	void pushdown(int o)
	{
		if(lazy[o]!=-1)
		{
			lazy[lson]=lazy[rson]=lazy[o];
			seg[lson].cnt=seg[rson].cnt=1;
			seg[lson].l=seg[lson].r=seg[rson].l=seg[rson].r=lazy[o];
			lazy[o]=-1;
		}
	}
	void change(int l,int r,int val,int L=1,int R=n,int o=1)
	{
		if(l<=L&&r>=R)
		{
			lazy[o]=val;
			seg[o].cnt=1;
			seg[o].l=seg[o].r=val;
			return;
		}
		pushdown(o);
		int mid=L+R>>1;
		if(l<=mid) change(l,r,val,Lson);
		if(r>mid) change(l,r,val,Rson);
		pushup(o);
	}
	Seg query(int l,int r,int L=1,int R=n,int o=1)
	{
		if(l<=L&&r>=R)
			return seg[o];
		pushdown(o);
		int mid=L+R>>1;
		Seg ret={-1,-1,0};
		Seg ll=ret,rr=ret;
		if(l<=mid)
			ll=query(l,r,Lson);
		if(r>mid)
			rr=query(l,r,Rson);
		ret=merge(ll,rr);
		return ret;
	}
};
void init()
{
	sgt::init();
	memset(head,-1,sizeof(head));
	cnt=0;
}
int fa[maxn],dep[maxn],maxson[maxn],son[maxn];
int top[maxn],dfn[maxn],tot;
int dfs(int u)
{
	int ret=0;
	for(int i=head[u];i!=-1;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa[u]) continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		int sz=dfs(v);
		ret+=sz;
		if(sz>maxson[u])
		{
			maxson[u]=sz;
			son[u]=v;
		}
	}
	return ret+1;
}
void link(int u,int t)
{
	dfn[u]=++tot;
	top[u]=t;
	if(son[u])
		link(son[u],t);
	for(int i=head[u];i!=-1;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa[u]||v==son[u]) continue;
		link(v,v);
	}
}
int arr[maxn];
void hld()
{
	dfs(1);
	link(1,1);
	for(int i=1;i<=n;i++) 
		sgt::change(dfn[i],dfn[i],arr[i]);
}
int query(int u,int v)
{
	Seg l={-1,-1,0},r={-1,-1,0};
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
		{
			r=merge(sgt::query(dfn[top[v]],dfn[v]),r);
			v=fa[top[v]];
		}
		else{
			l=merge(sgt::query(dfn[top[u]],dfn[u]),l);
			u=fa[top[u]];
		}
	}
	Seg ret;
	//dbg(l.l,l.r,l.cnt);dbg(r.l,r.r,r.cnt);
	if(dep[u]>dep[v])
	{
		swap(r.l,r.r);
		ret=merge(merge(r,sgt::query(dfn[v],dfn[u])),l);
	}
	else 
	{
		swap(l.l,l.r);
		ret=merge(merge(l,sgt::query(dfn[u],dfn[v])),r);
	}
	//dbg(ret.l,ret.r,ret.cnt);
	return ret.cnt;
}
void change(int u,int v,int val)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		sgt::change(dfn[top[u]],dfn[u],val);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	sgt::change(dfn[u],dfn[v],val);
}
int main()
{
	init();
	int q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	hld();
	while(q--)
	{
		char op[5];
		scanf("%s",op);
		if(op[0]=='Q')
		{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",query(a,b));
		}
		else{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			change(a,b,c);
		}
	}
}
