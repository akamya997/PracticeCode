#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
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
	int to;
	ll w;
	int nxt;
}edge[maxn*2];
struct Edges{
	int u,v;
}sv[maxn];
int head[maxn];
int cnt;
int n;
void init()
{
	memset(head,-1,sizeof(head));
	cnt=0;
}
void addedge(int u,int v,ll w)
{
	edge[cnt]={v,w,head[u]};
	head[u]=cnt++;
	edge[cnt]={u,w,head[v]};
	head[v]=cnt++;
}
#define Lson L,mid,o<<1
#define Rson mid+1,R,o<<1|1
namespace sgt{
	ll seg[maxn*4];
	void pushup(int o)
	{
		seg[o]=seg[o<<1]+seg[o<<1|1];
	}
	void update(int p,ll val,int L=1,int R=n,int o=1)
	{
		if(L==R)
		{
			seg[o]=val;
			return;
		}
		int mid=L+R>>1;
		if(p<=mid) update(p,val,Lson);
		else update(p,val,Rson);
		pushup(o);
	}
	ll query(int l,int r,int L=1,int R=n,int o=1)
	{
		if(l<=L&&r>=R)
			return seg[o];
		int mid=L+R>>1;
		ll ret=0;
		if(l<=mid) ret+=query(l,r,Lson);
		if(r>mid) ret+=query(l,r,Rson);
		return ret;
	}
};
int fa[maxn],maxson[maxn],son[maxn],dep[maxn];
ll val[maxn];
int dfs(int u)
{
	int ret=0;
	for(int i=head[u];i!=-1;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa[u]) continue;
		fa[v]=u;
		val[v]=edge[i].w;
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
int dfn[maxn],top[maxn],tot;
void link(int u,int t)
{
	top[u]=t;
	dfn[u]=++tot;
	if(son[u])
		link(son[u],t);
	for(int i=head[u];i!=-1;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==son[u]||v==fa[u]) continue;
		link(v,v);
	}
}
ll query(int u,int v)
{
	ll ret=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		ret+=sgt::query(dfn[top[u]],dfn[u]);
		u=fa[top[u]];
	}
	if(u!=v)
	{
		if(dep[u]>dep[v]) swap(u,v);
		ret+=sgt::query(dfn[son[u]],dfn[v]);
	}
	return ret;
}
void update(int p,ll val)
{
	int u=sv[p].u,v=sv[p].v;
	if(dep[u]<dep[v]) swap(u,v);
	sgt::update(dfn[u],val);
}
void hld()
{
	dfs(1);
	link(1,1);
	for(int i=1;i<=n;i++)
		sgt::update(dfn[i],val[i]);
}
int main()
{
	init();
	int q;
	scanf("%d%d",&n,&q);
	for(int i=0,u,v,w;i<n-1;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		sv[i+1]={u,v};
		addedge(u,v,w);
	}
	hld();
	while(q--)
	{
		int op;
		scanf("%d",&op);
		int u,v;
		scanf("%d%d",&u,&v);
		if(op)
		{
			printf("%lld\n",query(u,v));
		}
		else{
			update(u,v);
		}
	}
}
