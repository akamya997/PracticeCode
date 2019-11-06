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
const int maxn=1e4+7;
struct Edge{
	int to,w,nxt;
}edge[maxn*2];
struct Edges{
	int u,v,w;
}edges[maxn];
int cnt;
int head[maxn];
int arr[maxn],fa[maxn],dep[maxn];
int maxson[maxn],son[maxn], val[maxn];
int dfs(int u)
{
	int ret=0;
	for(int i=head[u];i!=-1;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa[u]) continue;
		fa[v]=u;
		val[v]= edge[i].w;
		int sz=dfs(v);
		ret+=sz;
		dep[v]=dep[u]+1;
		if(sz>maxson[u])
		{
			maxson[u]=sz;
			son[u]=v;
		}
	}
	return ret+1;
}
int top[maxn],dfn[maxn],tot;
void link(int u,int t)
{
	dfn[u]=++tot;
	arr[tot]=val[u];
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
}
int n;
int seg[maxn*4];
#define Lson L,mid,o<<1
#define Rson mid+1,R,o<<1|1
void pushup(int o)
{
	seg[o]=max(seg[o<<1],seg[o<<1|1]);
}
void buildtree(int L=1,int R=n,int o=1)
{
	if(L==R)
	{
		seg[o]=arr[L];
		return;
	}
	int mid=L+R>>1;
	buildtree(Lson);buildtree(Rson);
	pushup(o);
}
void update(int p,int val,int L=1,int R=n,int o=1)
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
int query(int l,int r,int L=1,int R=n,int o=1)
{
	if(l<=L&&r>=R)
		return seg[o];
	int mid=L+R>>1;
	int ret=0;
	if(l<=mid) ret=query(l,r,Lson);
	if(r>mid) ret=max(ret,query(l,r,Rson));
	return ret;
}
void init()
{
	tot=0;cnt=0;
	for(int i=0;i<=n;i++) head[i]=-1,maxson[i]=0,son[i]=0,dep[i]=0,fa[i]=-1;
}
void addedge(int u,int v,int w)
{
	edge[cnt]={v,w,head[u]};
	head[u]=cnt++;
	edge[cnt]={u,w,head[v]};
	head[v]=cnt++;
}
void answer(int l,int r)
{
	int ret=0;
	while(top[l]!=top[r])
	{
		if(dep[top[l]]<dep[top[r]]) swap(l,r);
		ret=max(ret,query(dfn[top[l]],dfn[l]));
		l=fa[top[l]];
	}
	if(l!=r)
	{
		if(dep[l]>dep[r]) swap(l,r);
		ret=max(ret,query(dfn[l]+1,dfn[r]));
	}
	printf("%d\n",ret);
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
			edges[i+1]={u,v,w};
			addedge(u,v,w);
		}
		build();
		buildtree();
		while(1)
		{
			char op[10];
			scanf("%s",op);
			if(op[0]=='C')
			{
				int a,b;
				scanf("%d%d",&a,&b);
				int u=edges[a].u,v=edges[a].v;
				if(fa[u]==v)
					update(dfn[u],b);
				else update(dfn[v],b);
			}
			else if(op[0]=='Q')
			{
				int l,r;
				scanf("%d%d",&l,&r);
				answer(l,r);
			}
			else break;
		}
	}
}
