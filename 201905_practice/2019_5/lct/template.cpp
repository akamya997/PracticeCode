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
const int maxn=3e4+7;
#define lc ch[x][0]
#define rc ch[x][1]
namespace LCT{
	int fa[maxn],ch[maxn][2],val[maxn],pre[maxn],lz[maxn];
	inline bool nroot (int x)
	{
		return ch[fa[x]][0]==x||ch[fa[x]][1]==x;
	}
	inline void pushup(int x)//维护链信息
	{
		pre[x]=pre[lc]^pre[rc]^val[x];
	}
	inline void pushr(int x){swap(lc,rc);lz[x]^=1;}//反转
	inline void pushdown(int x)
	{
		if(lz[x])
		{
			if(lc) pushr(lc);
			if(rc) pushr(rc);
			lz[x]=0;
		}
	}
	void rotate(int x)//单次旋转
	{
		int y=fa[x],z=fa[y],k=ch[y][1]==x,w=ch[x][!k];
		if(nroot(y)) ch[z][ch[z][1]==y]=x;
		ch[x][!k]=y;ch[y][k]=w;
		if(w) fa[w]=y;
		fa[y]=x;fa[x]=z;
		pushup(y);
	}
	void pushall(int x)//递归下放标记
	{
		if(nroot(x)) pushall(fa[x]);
		pushdown(x);
	}
	void splay(int x)
	{
		pushall(x);
		while(nroot(x))
		{
			int y=fa[x];int z=fa[y];
			if(nroot(y))
				rotate((ch[y][0]==x)^(ch[z][0]==y)?x:y);
			rotate(x);
		}
		pushup(x);
	}
	void access(int x)
	{
		for(int y=0;x;x=fa[y=x])
		{
			splay(x);rc=y;pushup(x);
		}
	}
	void makeroot(int x)
	{
		access(x);splay(x);
		pushr(x);
	}
	int findroot(int x)
	{
		access(x);splay(x);
		while(lc) pushdown(x),x=lc;
		splay(x);
		return x;
	}
	void split(int x,int y)
	{
		makeroot(x);
		access(y);splay(y);
	}
	void link(int x,int y)
	{
		makeroot(x);
		if(findroot(y)!=x) fa[x]=y;
	}
	void cut(int x,int y)
	{
		makeroot(x);
		if(findroot(y)==x&&fa[y]==x&&!ch[y][0])
		{
			fa[y]=ch[x][1]=0;
			pushup(x);
		}
	}
};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		char op[10];
		scanf("%s",op);
		int u,v;
		scanf("%d%d",&u,&v);
		if(op[0]=='Q')
		{
			LCT::makeroot(u);
			if(LCT::findroot(v)==u) puts("Yes");
			else puts("No");
		}
		else if(op[0]=='C')
			LCT::link(u,v);
		else LCT::cut(u,v);
	}
}
