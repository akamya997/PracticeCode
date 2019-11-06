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
vector<int> G[maxn];
int sz[maxn],dfn[maxn];
int st[maxn*10],depth[maxn],pos[maxn];
int timer;
int tot;
int bg[maxn];
void dfs(int u,int fa=-1)
{
	sz[u]=1;
	dfn[++tot]=u;
	pos[u]=tot;
	st[++timer]=u;
	bg[u]=timer;
	for(auto v:G[u])if(v!=fa)
	{
		depth[v]=depth[u]+1;
		dfs(v,u);
		st[++timer]=u;
		sz[u]+=sz[v];
	}
}
int dp[maxn*10][20];
void ST()
{
	for(int i=1;i<=timer;i++)
		dp[i][0]=st[i];
	for (int j = 1; (1 << j) <= timer; j++)
    {
     	for (int i = 1; i + (1 << j) - 1 <= timer; i++)
		{
			if(depth[dp[i][j - 1]]<depth[dp[i + (1 << (j - 1))][j - 1]])
				dp[i][j]=dp[i][j-1];
			else dp[i][j]=dp[i + (1 << (j - 1))][j - 1];
		}
    }
}
int lca(int u, int v)
{
	u=bg[u],v=bg[v];
	if(u>v) swap(u,v);
    int k = 31 - __builtin_clz(v - u + 1);
   	if(depth[dp[u][k]]<depth[dp[v - (1 << k) + 1][k]])
		return dp[u][k];
	return dp[v - (1 << k) + 1][k];
}
int cnt[maxn<<6],lson[maxn<<6],rson[maxn<<6];
int rt[maxn];
int n;
#define Lson lson[o],L,mid
#define Rson rson[o],mid+1,R
void update(int p,int pre,int &o,int L=1,int R=n)
{
	o=++tot;
	lson[o]=0,rson[o]=0;
	cnt[o]=cnt[pre]+1;
	if(L==R) return;
	int mid=L+R>>1;
	if(p<=mid)
	{
		rson[o]=rson[pre];
		update(p,lson[pre],Lson);
	}
	else{
		lson[o]=lson[pre];
		update(p,rson[pre],Rson);
	}
}
int query(int v,int pre,int o,int L=1,int R=n)
{
	//dbg(v,L,R,cnt[pre],cnt[o]);
	if(v<=L)
		return cnt[o]-cnt[pre];
	int mid=L+R>>1;
	int ret=0;
	if(v<=mid) ret+=query(v,lson[pre],Lson);
	ret+=query(v,rson[pre],Rson);
	return ret;
}
int fa[maxn];
bool vis[maxn];
void init()
{
	for(int i=0;i<=n;i++) fa[i]=i,vis[i]=0;
	timer=0;depth[1]=0;
}
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	fa[y]=x;
}
void solve(int x,int fa=-1)
{
	if(fa!=-1) Union(fa,x);
	if(vis[x]) return;
	vis[x]=1;
	for(auto v:G[x])if(depth[v]>depth[x])
		solve(v,x);
}
int answer(int u,int v)
{
	int fu=Find(u),fv=Find(v);
	if(fv==fu)
		return -query(v+1,rt[pos[fv]-1],rt[pos[fv]+sz[fv]-1])+query(u+1,rt[pos[fu]-1],rt[pos[fu]+sz[fu]-1]);
	int LCA=lca(fu,fv);
	int dis=depth[fu]+depth[fv]-2*depth[LCA];
	//dbg(u,v,fu,fv,sz[u],sz[v],pos[fu],pos[fv]);
	if(vis[v]) dis+=query(v+1,rt[pos[fv]-1],rt[pos[fv]+sz[fv]-1]);
	if(vis[u]) dis+=query(u+1,rt[pos[fu]-1],rt[pos[fu]+sz[fu]-1]);
	return dis;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		tot=0;
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1,u,v;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1);
		ST();
		tot=0;
		for(int i=1;i<=n;i++)
			update(dfn[i],rt[i-1],rt[i]);
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int op;
			scanf("%d",&op);
			if(op==1)
			{
				int x;
				scanf("%d",&x);
				solve(x);
			}
			else{
				int u,v;
				scanf("%d%d",&u,&v);
				if(u>v) swap(u,v);
				printf("%d\n",answer(u,v));
			}
		}
		
	}
}
