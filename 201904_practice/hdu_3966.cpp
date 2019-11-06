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
const int maxn=5e4+7;
struct Edge{
	int to,nxt;
}edge[maxn*2];
int head[maxn],cnt;
int arr[maxn];
template <typename T>
bool scan_d(T &num)
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}
template <typename T>
void o(T p) {
    static int stk[70], tp;
    if (p == 0) { putchar('0'); return; }
    if (p < 0) { p = -p; putchar('-'); }
    while (p) stk[++tp] = p % 10, p /= 10;
    while (tp) putchar(stk[tp--] + '0');
}
void addedge(int u,int v)
{
	edge[cnt]={v,head[u]};
	head[u]=cnt++;
	edge[cnt]={u,head[v]};
	head[v]=cnt++;
}
int depth[maxn],maxson[maxn],son[maxn],fa[maxn];
int dfs1(int u)
{
	int ret=0;
	for(int i=head[u];i!=-1;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa[u]) continue;
		depth[v]=depth[u]+1;
		fa[v]=u;
		int sz=dfs1(v);
		ret+=sz;
		if(maxson[u]<sz)
		{
			maxson[u]=sz;
			son[u]=v;
		}
	}
	return ret+1;
}
int top[maxn],dfn[maxn],id[maxn],tot;
void dfs2(int u,int t)
{
	dfn[u]=++tot;
	id[tot]=u;
	top[u]=t;
	if(son[u])
		dfs2(son[u],t);
	for(int i=head[u];i!=-1;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==son[u]||v==fa[u]) continue;
		dfs2(v,v);
	}
}
int n,m,p;
int tree[maxn];
void init()
{
	cnt=0;
	for(int i=0;i<=n;i++) head[i]=-1,maxson[i]=0,son[i]=0,tree[i]=0,depth[i]=0;
	tot=0;
}
void add(int x,int k)
{
	while(x<maxn)
	{
		tree[x]+=k;
		x+=x&-x;
	}
}
int query(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=tree[x];
		x-=x&-x;
	}
	return ret;
}
void update(int l,int r,int k)
{
	while(top[l]!=top[r])
	{
		if(depth[top[l]]<depth[top[r]]) swap(l,r);
		add(dfn[top[l]],k);
		add(dfn[l]+1,-k);
		l=fa[top[l]];
	}
	if(depth[l]>depth[r]) swap(l,r);
	add(dfn[l],k);
	add(dfn[r]+1,-k);
}
void Exec()
{
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=n;i++)
	{
		add(dfn[i],arr[i]);
		add(dfn[i]+1,-arr[i]);
	}
}
int main()
{
	while(~scanf("%d%d%d",&n,&m,&p))
	{
		init();
		for(int i=1;i<=n;i++) 
			scan_d(arr[i]);
		for(int i=0,u,v;i<m;i++)
		{
			scan_d(u);
			scan_d(v);
			addedge(u,v);
		}
		Exec();
		char op[5];
		while(p--)
		{
			scanf("%s",op);
			if(op[0]=='I'||op[0]=='D')
			{
				int l,r,k;
				scan_d(l);
				scan_d(r);
				scan_d(k);
				if(op[0]=='D') k=-k;
				update(l,r,k);
			}
			else{
				int x;
				scan_d(x);
				o(query(dfn[x]));
				puts("");
			}
		}
	}
}
