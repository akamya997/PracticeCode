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
const int maxn=2e4+7;
struct Edge{
	int to,w;
};
vector<Edge> G[maxn];
int sz[maxn],rt,maxson[maxn],minson,cursz;
bool vis[maxn];
void findrt(int u,int fa=-1)
{
	sz[u]=1,maxson[u]=0;
	for(auto &e:G[u])
	{
		int v=e.to;
		if(v==fa||vis[v]) continue;
		findrt(v,u);
		sz[u]+=sz[v];
		maxson[u]=max(maxson[u],sz[v]);
	}
	maxson[u]=max(maxson[u],cursz-sz[u]);
	if(minson>maxson[u]) minson=maxson[u],rt=u;
}
int ans;
int cnt[3];
void getdis(int u,int d,int fa=-1)
{
	cnt[d]++;
	for(auto &e:G[u])
	{
		int v=e.to;
		if(v==fa||vis[v]) continue;
		getdis(v,(d+e.w)%3,u);
	}
}
int solve(int u,int d)
{
	memset(cnt,0,sizeof(cnt));
	getdis(u,d%3);
	//dbg(u,d,cnt[0],cnt[1],cnt[2]);
	return cnt[0]*cnt[0]+cnt[1]*cnt[2]*2;
}
void dfs(int u)
{
	ans+=solve(u,0);
	vis[u]=1;
	int totsz=cursz;
	for(auto &e:G[u])
	{
		int v=e.to;
		if(vis[v]) continue;
		minson=INF,rt=0;
		cursz=sz[v]>sz[u]?totsz-sz[u]:sz[v];
		ans-=solve(v,e.w);
		findrt(v);
		dfs(rt);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	int tot=n*n;
	minson=INF,rt=0,cursz=n;
	findrt(1);
	dfs(rt);
	int g=__gcd(tot,ans);
	printf("%d/%d\n",ans/g,tot/g);
}
