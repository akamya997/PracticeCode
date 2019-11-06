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
const int maxn=3e4+7;
struct Edge{
	int to,nxt;
}edge[maxn*2];
int cnt;
int head[maxn];
void addedge(int u,int v)
{
	edge[cnt]={v,head[u]};
	head[u]=cnt++;
	edge[cnt]={u,head[v]};
	head[v]=cnt++;
}
void init()
{
	memset(head,-1,sizeof(head));
	cnt=0;
}
int n;
#define Lson L,mid,o<<1
#define Rson mid+1,R,o<<1|1
namespace Sgt{
	struct Node{
		int mx,sum;
	};
	Node seg[maxn*4];
	void pushup(int o)
	{
		seg[o].mx=max(seg[o<<1].mx,seg[o<<1|1].mx);
		seg[o].sum=seg[o<<1].sum+seg[o<<1|1].sum;
	}
	void update(int p,int val,int L=1,int R=n,int o=1)
	{
		if(L==R)
		{
			seg[o].mx=seg[o].sum=val;
			return;
		}
		int mid=L+R>>1;
		if(p<=mid) update(p,val,Lson);
		else update(p,val,Rson);
		pushup(o);
	}
	int querymax(int l,int r,int L=1,int R=n,int o=1)
	{
		if(l<=L&&r>=R)
			return seg[o].mx;
		int mid=L+R>>1;
		int ret=-30001;
		if(l<=mid) ret=max(ret,querymax(l,r,Lson));
		if(r>mid) ret=max(ret,querymax(l,r,Rson));
		return ret;
	}
	int querysum(int l,int r,int L=1,int R=n,int o=1)
	{
		if(l<=L&&r>=R)
			return seg[o].sum;
		int mid=L+R>>1;
		int ret=0;
		if(l<=mid) ret+=querysum(l,r,Lson);
		if(r>mid) ret+=querysum(l,r,Rson);
		return ret;
	}
};
int fa[maxn],dep[maxn],maxson[maxn],son[maxn];
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
int dfn[maxn],top[maxn],tot;
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
void build()
{
	dfs(1);
	link(1,1);
	for(int i=1,val;i<=n;i++) 
	{
		scanf("%d",&val);
		Sgt::update(dfn[i],val);
	}
}
int querymax(int u,int v)
{
	int ret=-30001;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		ret=max(ret,Sgt::querymax(dfn[top[u]],dfn[u]));
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	ret=max(ret,Sgt::querymax(dfn[u],dfn[v]));
	return ret;
}
int querysum(int u,int v)
{
	int ret=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		ret+=Sgt::querysum(dfn[top[u]],dfn[u]);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	ret+=Sgt::querysum(dfn[u],dfn[v]);
	return ret;
}
int main()
{
	init();
	scanf("%d",&n);
	for(int i=0,u,v;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	build();
	int q;
	scanf("%d",&q);
	while(q--)
	{
		char op[10];
		scanf("%s",op);
		if(op[0]=='Q')
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(op[1]=='M')
			{
				int ans=querymax(u,v);
				printf("%d\n",ans);
			}
			else {
				int ans=querysum(u,v);
				printf("%d\n",ans);
			}
		}
		else{
			int u,t;
			scanf("%d%d",&u,&t);
			Sgt::update(dfn[u],t);
		}
	}

}
