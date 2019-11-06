#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
	int u,v;
};
vector<Edge> seg[maxn<<2];
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
int n,m,T;
int fa[maxn],col[maxn],sz[maxn];
void init()
{
	for(int i=0;i<=n;i++) fa[i]=i,sz[i]=1,col[i]=0;
}
int Find(int x)
{
	return fa[x]==x?x:Find(fa[x]);
}
int getval(int x)
{
	int ret=0;
	while(fa[x]!=x) ret^=col[x],x=fa[x];
	return ret;
}

void update(int l,int r,Edge e,int L=1,int R=T,int o=1)
{
	if(l<=L&&r>=R)
	{
		seg[o].push_back(e);
		return;
	}
	int mid=L+R>>1;
	if(l<=mid)
		update(l,r,e,Lson);
	if(r>mid) update(l,r,e,Rson);
}
void solve(int L=1,int R=T,int o=1,bool ok=0)
{
	int mid=L+R>>1;
	if(ok){
		if(L==R) puts(ok?"No":"Yes");
		else
		{
			solve(Lson,1);
			solve(Rson,1);
		}
	}
	else{
		vector<int> cur;
		for(int i=0;i<seg[o].size();i++)
		{
			Edge e=seg[o][i];
			int u=e.u,v=e.v;
			int colu=getval(u),colv=getval(v);
			u=Find(u),v=Find(v);
			if(u==v&&colu==colv)
				ok=1;
			else{
				if(sz[u]>sz[v]) swap(u,v);
				sz[v]+=sz[u];
				fa[u]=v;
				col[u]=colu^colv^1;
				cur.push_back(u);
			}
		}
		if(L==R)
			puts(ok?"No":"Yes");
		else solve(Lson,ok),solve(Rson,ok);
		for(int i=cur.size()-1;i>=0;i--)
		{
			int u=cur[i];
			sz[fa[u]]-=sz[u],fa[u]=u,col[u]=0;
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&T);
	init();
	for(int i=0,u,v,s,e;i<m;i++)
	{
		scanf("%d%d%d%d",&u,&v,&s,&e);
		s++;
		if(s<=e)
			update(s,e,Edge{u,v});
	}
	solve();
}
