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
const int maxn=5e5+7;
struct Edge{
	int to,w,nxt;
}edge[maxn*2],g[maxn*2];
int head[maxn],ghead[maxn];
int cnt,gcnt;
void addedge(int u,int v,int c)
{
	edge[cnt].to=v;
	edge[cnt].w=c;
	edge[cnt].nxt=head[u];
	head[u]=cnt++;
	edge[cnt].to=u;
	edge[cnt].w=c;
	edge[cnt].nxt=head[v];
	head[v]=cnt++;
}
void addedgev(int u,int v,int c)
{
	g[gcnt].to=v;
	g[gcnt].w=c;
	g[gcnt].nxt=ghead[u];
	ghead[u]=gcnt++;
	g[gcnt].to=u;
	g[gcnt].w=c;
	g[gcnt].nxt=ghead[v];
	ghead[v]=gcnt++;
}
int ti;
void init()
{
	cnt=0;
	gcnt=0;
	ti=0;
	memset(ghead,-1,sizeof(ghead));
	memset(head,-1,sizeof(head));
}
int ts[maxn];
int depth[maxn];
int pre[maxn][22];
int far[maxn][22];
int dfn[maxn];
void dfs(int u,int fa=-1)
{
	dfn[u]=++ti;
	ts[ti]=u;
	for(int i=head[u];i!=-1;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa) continue;
		depth[v]=depth[u]+1;
		pre[v][0]=edge[i].w;
		far[v][0]=u;
		dfs(v,u);
		ts[++ti]=u;
	}
}
int ST[maxn][22];
bool cmp(int x,int y)
{
	return depth[x]<depth[y];
}
void RMQ()
{
	for(int i=1;i<=ti;i++) ST[i][0]=ts[i];
	for(int j=1;(1<<j)<=ti;j++)
	{
		for(int i=1;i+(1<<(j-1))-1<=ti;i++)
		{
			if(cmp(ST[i][j-1],ST[i+(1<<(j-1))][j-1]))
				ST[i][j]=ST[i][j-1];
			else ST[i][j]=ST[i+(1<<(j-1))][j-1];
		}
	}
}
int LCA(int u,int v)
{
	int l=dfn[u],r=dfn[v];
	if(l>r)swap(l,r);
	int k = 31 - __builtin_clz(r - l + 1);
	if(cmp(ST[l][k],ST[r-(1<<k)+1][k])) return ST[l][k];
	return ST[r-(1<<k)+1][k];
}
int getw(int u,int v)
{
	int ret=0x3f3f3f3f;
	if(depth[u]<depth[v]) swap(u,v);
	int dis=depth[u]-depth[v];
	int step=0;
	while(dis)
	{
		if(dis&1)
		{
			ret=min(ret,pre[u][step]);
			u=far[u][step];
		}
		step++;
		dis>>=1;
	}
	return ret;
}
void build(vector<int> &all)
{
	int st[maxn];
	int top=0;
	vector<int> used;
	for(int i=0;i<all.size();i++)
	{
		int u=all[i];
		if(top==0) st[++top]=u;
		else{
			int lca=LCA(st[top],u);
			used.push_back(lca);
			while(top>1&&dfn[st[top-1]]>=dfn[lca])
			{
				addedgev(st[top],st[top-1],getw(st[top],st[top-1]));
				top--;
			}
			if(lca!=st[top]) 
			{
				addedgev(st[top],lca,getw(lca,st[top]));
				st[top]=lca;
			}
			st[++top]=u;
		}
	}
	while(top>1)
	{
		addedgev(st[top],st[top-1],getw(st[top],st[top-1]));
		--top;
	}
	for(int i=0;i<used.size();i++) all.push_back(used[i]);
}
int n;
void db()
{
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			pre[i][j]=min(pre[i][j-1],pre[far[i][j-1]][j-1]);
			far[i][j]=far[far[i][j-1]][j-1];
		}
	}
}
bool iskey[maxn];
ll dp[maxn];
ll dfsans(int u,int fa=-1)
{
	ll ret=0;
	for(int i=ghead[u];i!=-1;i=g[i].nxt)
	{
		int v=g[i].to;
		if(v==fa) continue;
		dfsans(v,u);
		if(iskey[v]) ret+=g[i].w;
		else
			ret+=min(1LL*g[i].w,dp[v]);
	}
	return dp[u]=ret;
}
void solve()
{
	ll ans=dfsans(1);
	printf("%lld\n",ans);
}
bool cpp(int x,int y){return dfn[x]<dfn[y];}
int main()
{
	init();memset(pre,0x3f,sizeof(pre));
	scanf("%d",&n);
	for(int i=0,u,v,c;i<n-1;i++)
	{
		scanf("%d%d%d",&u,&v,&c);
		addedge(u,v,c);
	}
	depth[1]=1;
	dfs(1);
	RMQ();
	db();
	int q;
	scanf("%d",&q);
	while(q--)
	{
		gcnt=0;
		int k;
		scanf("%d",&k);
		vector<int> all;
		all.push_back(1);
		for(int i=0,h;i<k;i++)
		{
			scanf("%d",&h);
			all.push_back(h);
			iskey[h]=1;
		}
		sort(all.begin(),all.end(),cpp);
		all.erase(unique(all.begin(),all.end()),all.end());
		build(all);
		solve();
		for(int i=0;i<all.size();i++) 
		{
			int u=all[i];
			ghead[u]=-1,iskey[u]=0;
		}
	}
}
