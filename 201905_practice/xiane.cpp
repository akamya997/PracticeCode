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
int val[maxn];
vector<int> G[maxn];
int fa[maxn], dep[maxn], maxson[maxn], son[maxn]; //dfs数组
int top[maxn], dfn[maxn], tot;                    //link数组
int dfs(int u)
{
    int ret = 0;
    for (auto& v:G[u])
    {
        if (v == fa[u])
            continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        int sz = dfs(v);
        ret += sz;
        if (sz > maxson[u])
        {
            maxson[u] = sz;
            son[u] = v;
        }
    }
    return ret + 1;
}
void link(int u, int t)
{
    dfn[u] = ++tot;
    top[u] = t;
    if (son[u])
        link(son[u], t);
    for (auto& v:G[u])
    {
        if (v == fa[u] || v == son[u])
            continue;
        link(v, v);
    }
}
void hld()
{
    dfs(1);
    link(1, 1);
}
int n,m;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
namespace SGT{
	int sum[maxn*4];
	int tag[maxn*4][2];
	void pushup(int o)
	{
		sum[o]=sum[lson]^sum[rson];
	}
	void upd(int o,int len,int p,int val)
	{
		if(!p)
			sum[o]&=val;
		else{
			if(len&1)
				sum[o]|=val;
			else sum[o]&=(~val);
		}
	}
	void pushdown(int o,int len,int p)
	{
		if(tag[o][p])
		{
			tag[lson][p]|=tag[o][p];
			tag[rson][p]|=tag[o][p];
			upd(lson,len-len/2,p,tag[o][p]);
			upd(rson,len/2,p,tag[o][p]);
		}
	}
	void update(int l,int r,int p,int val,int L=1,int R=n,int o=1)
	{
		if(l<=L&&r>=R)
		{
			tag[o][p]|=val;
			tag[o][p^1]&=(~val);
			upd(o,R-L+1,p,val);
			return;
		}
		pushdown(o,R-L+1,p);
		pushdown(o,R-L+1,p^1);
		int mid=L+R>>1;
		if(l<=mid)
			update(l,r,p,val,Lson);
		if(r>mid)
			update(l,r,p,val,Rson);
		pushup(o);
	}
	int query(int l,int r,int L=1,int R=n,int o=1)
	{
		if(l<=L&&r>=R)
			return sum[o];
		int mid=L+R>>1;
		int ret=0;
		pushdown(o,R-L+1,1);
		pushdown(o,R-L+1,0);
		if(l<=mid) ret^=query(l,r,Lson);
		if(r>mid) ret^=query(l,r,Rson);
		pushup(o);
		return ret;
	}
};
void build()
{
	for(int i=1;i<=n;i++)
		SGT::update(dfn[i],dfn[i],1,val[i]);
}
void update(int u,int v,int va,int opt)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		SGT::update(dfn[top[u]],dfn[u],opt,va);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])
		swap(u,v);
	SGT::update(dfn[u],dfn[v],opt,va);
}
int query(int u,int v)
{
	int ret=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		ret^=SGT::query(dfn[top[u]],dfn[u]);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	ret^=SGT::query(dfn[u],dfn[v]);
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	hld();
	build();
	for(int i=0;i<m;i++)
	{
		int opt,u,v;
		scanf("%d%d%d",&opt,&u,&v);
		if(opt==1)
			update(1,u,v,1);
		else if(opt==2)
			update(1,u,v,0);
		else {
			int ans=query(1,u);
			ans^=v;
			if(ans) puts("YES");
			else puts("NO");
		}
	}

}
