#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int val[maxn];
vector<int> G[maxn];
int fa[maxn],dep[maxn],maxson[maxn],son[maxn];
int top[maxn],dfn[maxn],tot;
int dfs(int u)
{
	int ret=0;
	for(auto& v:G[u])
	{
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
	for(auto& v:G[u])
	{
		if(v==fa[u]||v==son[u]) continue;
		link(v,v);
	}
}
void hld()
{
	dfs(1);
	link(1,1);
}
namespace SGT{
	struct node{
		int XOR,allo,allz;
	}seg[maxn*4][32];
	void pushup(int o)
	{
		
	}
};
int main()
{
	int n,m;
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
	


}
