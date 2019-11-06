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
const ll ini=123456789123456789LL;
struct Edge{
	int to;ll w;
};
vector<Edge> G[maxn];
int son[maxn],maxson[maxn],fa[maxn],dep[maxn];
ll dis[maxn];
int top[maxn],dfn[maxn],ti,id[maxn];
int dfs(int u,int faa=-1)
{
	int ret=0;
	for(int i=0;i<G[u].size();i++)
	{
		Edge e=G[u][i];
		int v=e.to;
		if(v==faa) continue;
		dep[v]=dep[u]+1;
		dis[v]=dis[u]+e.w;
		fa[v]=u;
		int sz=dfs(v,u);
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
	top[u]=t;
	dfn[u]=++ti;
	id[ti]=u;
	if(son[u])
		link(son[u],t);
	for(int i=0;i<G[u].size();i++)
	{
		Edge e=G[u][i];
		int v=e.to;
		if(v==fa[u]||v==son[u]) continue;
		link(v,v);
	}
}
void hld()
{
	dfs(1);
	link(1,1);
}
int LCA(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	return u;
}
int n,m;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
struct Line{
	ll a,b;
	ll s;
}seg[maxn*4];
ll mi[maxn*4];
ll calc(Line a,int u)
{
	ll dist=dis[u]-dis[a.s];
	return a.a*dist+a.b;
}
namespace SGT{

void build(int L=1,int R=n,int o=1)
{
	mi[o]=ini;
	if(L==R)
	{
		seg[o]=Line{0,ini,0};
		return;
	}
	int mid=L+R>>1;
	seg[o]=Line {0,ini,0};
	build(Lson);build(Rson);
}

void pushup(int o)
{
	mi[o]=min(mi[o],min(mi[lson],mi[rson]));
}
void maintain(Line a,int L,int R,int o)
{
	ll M=min(calc(a,id[L]),calc(a,id[R]));
	Line tmp=seg[o];
	if(L==R)
	{
		if(M<calc(seg[o],id[L]))
			seg[o]=a,mi[o]=M;
		return;
	}
	int mid=L+R>>1;
	M=min(mi[o],M);
	if(a.a>tmp.a) swap(a,tmp);
	if(calc(a,id[mid])<calc(tmp,id[mid]))
	{
		seg[o]=a;
		mi[o]=min(mi[o],M);
		maintain(tmp,Lson);
	}
	else{
		seg[o]=tmp;
		mi[o]=min(mi[o],M);
		maintain(a,Rson);
	}
	pushup(o);
}

void add(Line a,int l,int r,int L=1,int R=n,int o=1)
{
	if(l<=L&&r>=R)
	{
		maintain(a,L,R,o);
		return;
	}
	int mid=L+R>>1;
	if(l<=mid)
		add(a,l,r,Lson);
	if(r>mid) add(a,l,r,Rson);
	pushup(o);
}

ll query(int l,int r,int L=1,int R=n,int o=1)
{
	int LL=max(l,L),RR=min(r,R);
	ll ret=min(calc(seg[o],id[LL]),calc(seg[o],id[RR]));
	if(l<=L&&r>=R)
		return min(ret,mi[o]);
	int mid=L+R>>1;
	if(l<=mid) ret=min(ret,query(l,r,Lson));
	if(r>mid) ret=min(ret,query(l,r,Rson));
	return ret;
}

};
void update(int x,int y,ll a,ll b)
{
	Line ins;
	int lca=LCA(x,y),s=x;
	bool rec=true;
	ll base;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
		{
			swap(x,y);rec^=1;
		}
		base=dis[top[x]]+dis[s]-2*dis[lca];
		if(rec) base=dis[s]-dis[top[x]];
		base=a*base+b;
		if(!rec) ins=Line {a,base,top[x]};
		else ins=Line {-a,base,top[x]};
		SGT::add(ins,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	else rec^=1;
	base=dis[x]+dis[s]-2*dis[lca];
	if(rec) base=dis[s]-dis[x];
	base=a*base+b;
	if(!rec) ins=Line {a,base,x};
	else ins=Line {-a,base,x};
	SGT::add(ins,dfn[x],dfn[y]);
}
ll query(int x,int y)
{
	ll ret=ini;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ret=min(ret,SGT::query(dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	ret=min(ret,SGT::query(dfn[x],dfn[y]));
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n-1;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back(Edge {v,w});
		G[v].push_back(Edge {u,w});
	}
	hld();
	SGT::build();
	while(m--)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int u,v;
			ll a,b;
			scanf("%d%d",&u,&v);
			scanf("%lld%lld",&a,&b);
			update(u,v,a,b);
		}
		else{
			int u,v;
			scanf("%d%d",&u,&v);
			printf("%lld\n",query(u,v));
		}
	}
}
