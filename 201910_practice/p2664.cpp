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
int cnt[maxn],col[maxn];
ll ans[maxn];
vector<int> G[maxn];
int minson,sz[maxn],maxson[maxn],cursz,rt;
bool vis[maxn];
void findrt(int u,int fa=-1)
{
	sz[u]=1,maxson[u]=0;
	for(auto v:G[u])if(v!=fa&&!vis[v])
	{
		findrt(v,u);
		maxson[u]=max(maxson[u],sz[v]);
		sz[u]+=sz[v];
	}
	maxson[u]=max(maxson[u],cursz-sz[u]);
	if(minson>maxson[u]) minson=maxson[u],rt=u;
}
int tsz[maxn];
vector<int> used;
int fi[maxn];
int tag[maxn];
void getsz(int u,int fa=-1)
{
	tsz[u]=1;
	if(!fi[col[u]])
	{
		used.push_back(col[u]);
		fi[col[u]]=1;
	}
	for(auto v:G[u])if(v!=fa&&!vis[v])
	{
		getsz(v,u);
		tsz[u]+=tsz[v];
	}
}
void db(int u,int fa=-1)
{
	if(!fi[col[u]])
	{
		cnt[col[u]]+=tsz[u];
		tag[u]=1;
	}
	fi[col[u]]++;
	for(auto v:G[u])if(v!=fa&&!vis[v])
		db(v,u);
	fi[col[u]]--;
}
ll tot;
void del(int u,int fa=-1)
{
	if(tag[u])
	{
		cnt[col[u]]-=tsz[u];
		tot-=tsz[u];
	}
	for(auto v:G[u])if(v!=fa&&!vis[v])
		del(v,u);
}
void add(int u,int fa=-1)
{
	if(tag[u])
	{
		cnt[col[u]]+=tsz[u];
		tot+=tsz[u];
		tag[u]=0;
	}
	for(auto v:G[u])if(v!=fa&&!vis[v])
		add(v,u);
}
int othsz;
void calc(int u,ll val,int fa=-1,int cc=0)
{
	if(!fi[col[u]])
	{
		cc++;
		val-=cnt[col[u]];
	}
	fi[col[u]]++;
	ans[u]+=val+1LL*cc*othsz;
	for(auto v:G[u])if(v!=fa&&!vis[v])
		calc(v,val,u,cc);
	fi[col[u]]--;
}
void solve(int u)
{
	getsz(u);
	for(auto v:used) fi[v]=0;
	for(auto v:G[u])if(!vis[v])
		db(v,u);
	tot=0;
	for(auto v:used) 
		tot+=cnt[v];
	}
	ans[u]+=tot+tsz[u]-cnt[col[u]];
	for(auto v:G[u])if(!vis[v])
	{
		othsz=tsz[u]-tsz[v];
		del(v,u);
		fi[col[u]]=1;
		calc(v,tot-cnt[col[u]],u,1);
		add(v,u);
	}
	for(auto v:used) cnt[v]=0;
	used.clear();
}
void dfs(int u)
{
	solve(u);
	vis[u]=1;
	int totsz=cursz;
	for(auto v:G[u])if(!vis[v])
	{
		minson=INF,rt=0;
		cursz=sz[v]>sz[u]?totsz-sz[u]:sz[v];
		findrt(v);
		dfs(rt);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&col[i]);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	minson=INF,rt=0,cursz=n;
	findrt(1);
	dfs(rt);
	for(int i=1;i<=n;i++)
		printf("%lld\n",ans[i]);
}
