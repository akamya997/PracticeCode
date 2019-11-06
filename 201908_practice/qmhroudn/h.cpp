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
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
const int maxn=2e5+7;
struct OPT{
	int u,v,w;
	bool operator<(const OPT& a)const{
		if(w==a.w) return v>a.v;
		return w<a.w;
	}
}opt[maxn*10];
int fa[maxn];
int sz[maxn];
void init()
{
	for(int i=0;i<maxn;i++) fa[i]=i,sz[i]=1;
}
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x);y=Find(y);
	if(x!=y) 
	{
		sz[x]+=sz[y];
		fa[y]=x;
	}
}
int ans[maxn];
int main()
{
	int n,m,q;
	init();
	scanf("%d%d%d",&n,&m,&q);
	int cnt=0;
	for(int i=0,u,v,w;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		opt[cnt++]={u,v,w};
	}
	for(int i=0;i<q;i++)
	{
		int t;
		scanf("%d",&t);
		opt[cnt++]={i,-1,t};
	}
	sort(opt,opt+cnt);
	for(int i=0;i<cnt;i++)
	{
		if(opt[i].v==-1)
			ans[opt[i].u]=sz[Find(1)];
		else Union(opt[i].u,opt[i].v);
	}
	for(int i=0;i<q;i++)
		printf("%d\n",ans[i]);
}
