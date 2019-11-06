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
const int maxn=1e5+7;
struct Pt{
	int x,y,len;
};
int n;
vector<int> G[maxn];
int fa[maxn],dep[maxn],maxson[maxn],son[maxn];
int top[maxn],dfn[maxn],tot;
int dfs(int u)
{
	int ret=0;
	for(auto &v:G[u])
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
	tot=0;
	for(int i=0;i<=n;i++) dep[1]=1,maxson[i]=0,son[i]=0;
	dfs(1);
	link(1,1);
}
int LCA(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	return x;
}
Pt dp[maxn];
inline int dis(int x,int y)
{
	int lca=LCA(x,y);
	return dep[x]+dep[y]-dep[lca]*2+1;
}
inline Pt Merge(Pt a,Pt b)
{
	Pt ret;
	if(a.len>b.len) ret=a;
	else ret=b;
	if(dis(a.x,b.x)>ret.len) ret={a.x,b.x,dis(a.x,b.x)};
	if(dis(a.x,b.y)>ret.len) ret={a.x,b.y,dis(a.x,b.y)};
	if(dis(a.y,b.x)>ret.len) ret={a.y,b.x,dis(a.y,b.x)};
	if(dis(a.y,b.y)>ret.len) ret={a.y,b.y,dis(a.y,b.y)};
	return ret;
}
void solve(int u)
{
	dp[u]={u,u,1};
	for(auto &v:G[u])
	{
		if(v==fa[u]) continue;
		solve(v);
		dp[u]=Merge(dp[u],dp[v]);
	}
	//dbg(u,dp[u].x,dp[u].y,dp[u].len);
}
vector<Pt> suf[maxn];
int ans[maxn];
inline void update(int x,int y)
{
	if(x>y) swap(x,y);
	ans[x]=max(ans[x],y);
}
void ss(int u)
{
	suf[u].push_back(dp[u]);
	for(auto &v:G[u])
	{
		if(v==fa[u]) continue;
		suf[u].push_back(Merge(suf[u].back(),dp[v]));
	}
	int tag=suf[u].size()-2;
	Pt pre=dp[u];
	for(int i=G[u].size()-1;i>=0;i--)
	{
		int v=G[u][i];
		if(v==fa[u]) continue;
		Pt cur=Merge(pre,suf[u][tag]);
		//dbg(u,v,dp[v].len,cur.len);
		update(dp[v].len,cur.len);
		pre=Merge(pre,dp[v]);
		//Pt sv=dp[v];
		dp[v]=Merge({v,v,1},cur);
		ss(v);
		tag--;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++) ans[i]=0,G[i].clear(),ans[i]=0,suf[i].clear();
		for(int i=1,u,v;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		hld();
		solve(1);
		dp[1]={1,1,1};
		ss(1);
		ll op=0;
		for(int i=n;i>0;i--)
		{
			ans[i]=max(ans[i],ans[i+1]);
			if(ans[i])
				op+=1+(ans[i]-i)*2;
		}
		printf("%lld\n",op);
	}
}
