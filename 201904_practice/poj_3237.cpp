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
const int maxn=1e4+7;
struct Edge{
	int to,w,nxt;
}edge[maxn*2];
struct Edges{
	int u,v;
}sp[maxn];
int head[maxn];
int cnt;
int n;
void addedge(int u,int v,int w)
{
	edge[cnt]={v,w,head[u]};
	head[u]=cnt++;
	edge[cnt]={u,w,head[v]};
	head[v]=cnt++;
}
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,o<<1
#define Rson mid+1,R,o<<1|1
namespace sgt{
	int segmax[maxn*4],lazy[maxn*4],segmin[maxn*4];
	void init()
	{
		memset(lazy,0,sizeof(lazy));
	}
	void pushup(int o)
	{
		segmax[o]=max(segmax[o<<1],segmax[o<<1|1]);
		segmin[o]=min(segmin[o<<1],segmin[o<<1|1]);
	}
	void pushdown(int o)
	{
		if(lazy[o])
		{
			lazy[lson]^=1;
			lazy[rson]^=1;
			lazy[o]=0;
			swap(segmax[lson],segmin[lson]);
			segmax[lson]*=-1;segmin[lson]*=-1;
			swap(segmax[rson],segmin[rson]);
			segmax[rson]*=-1;segmin[rson]*=-1;
		}
	}
	void change(int p,int val,int L=1,int R=n,int o=1)
	{
		if(L==R)
		{
			segmax[o]=segmin[o]=val;
			return;
		}
		pushdown(o);
		int mid=L+R>>1;
		if(p<=mid) change(p,val,Lson);
		else change(p,val,Rson);
		pushup(o);
	}
	void neg(int l,int r,int L=1,int R=n,int o=1)
	{
		if(l<=L&&r>=R)
		{
			swap(segmax[o],segmin[o]);
			segmax[o]*=-1;segmin[o]*=-1;
			lazy[o]^=1;
			return;
		}
		pushdown(o);
		int mid=L+R>>1;
		if(l<=mid) neg(l,r,Lson);
		if(r>mid) neg(l,r,Rson);
		pushup(o);
	}
	int query(int l,int r,int L=1,int R=n,int o=1)
	{
		if(l<=L&&r>=R)
			return segmax[o];
		pushdown(o);
		int mid=L+R>>1;
		int ret=-0x3f3f3f3f;
		if(l<=mid) ret=max(ret,query(l,r,Lson));
		if(r>mid) ret=max(ret,query(l,r,Rson));
		return ret;
	}
};
int fa[maxn],maxson[maxn],son[maxn],dep[maxn];
int dfn[maxn],top[maxn],val[maxn],tot;
int dfs(int u)
{
	int ret=0;
	for(int i=head[u];i!=-1;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa[u]) continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		val[v]=edge[i].w;
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
void hld()
{
	dfs(1);
	link(1,1);
	for(int i=1;i<=n;i++)
		sgt::change(dfn[i],val[i]);
}
void init()
{
	for(int i=0;i<=n;i++) head[i]=-1,fa[i]=0,dep[i]=0,maxson[i]=0,son[i]=0;
	cnt=0;tot=0;
	sgt::init();
}
int query(int u,int v)
{
	int ret=-0x3f3f3f3f;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		ret=max(ret,sgt::query(dfn[top[u]],dfn[u]));
		u=fa[top[u]];
	}
	if(u!=v)
	{
		if(dep[u]>dep[v]) swap(u,v);
		ret=max(ret,sgt::query(dfn[son[u]],dfn[v]));
	}
	return ret;
}
void change(int i,int val)
{
	int u=sp[i].u,v=sp[i].v;
	if(dep[u]<dep[v]) swap(u,v);
	sgt::change(dfn[u],val);
}
void neg(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		sgt::neg(dfn[top[u]],dfn[u]);
		u=fa[top[u]];
	}
	if(u!=v)
	{
		if(dep[u]>dep[v]) swap(u,v);
		sgt::neg(dfn[son[u]],dfn[v]);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		init();
		for(int i=0,u,v,w;i<n-1;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			sp[i+1]={u,v};
		}
		hld();
		while(1)
		{
			char op[10];
			scanf("%s",op);
			int a,b;
			if(op[0]=='D') break;
			scanf("%d%d",&a,&b);
			if(op[0]=='Q')
				printf("%d\n",query(a,b));
			else if(op[0]=='C')
				change(a,b);
			else if(op[0]=='N')
				neg(a,b);
			else break;
		}
	}
}
