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
vector<int> as,bs;
vector<int> G[maxn];
int n,m;
int far[maxn][20];
int dep[maxn];
void dfs(int u,int fa)
{
	far[u][0]=fa;
	for(int i=1;i<20;i++)
		far[u][i]=far[far[u][i-1]][i-1];
	for(auto& v:G[u]) if(v!=fa)
	{
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
void db()
{
	memset(far,0,sizeof(far));
	dep[1]=1;
	dfs(1,0);
}
int getfa(int u,int dis)
{
	for(int i=0;i<20;i++)
	{
		if(dis&(1<<i)) u=far[u][i];
	}
	return u;
}
bool check(int cur)
{
	set<int> ext;
	for(auto &u:as)
	{
		if(dep[u]>=cur)
			ext.insert(getfa(u,dep[u]-cur));
	}
	for(auto &u:bs)
	{
		if(dep[u]>=cur)
		{
			int fa=getfa(u,dep[u]-cur);
			if(ext.count(fa)) return true;
		}
	}
	return false;
}
void solve()
{
	int l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",ans);
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<=n;i++) G[i].clear();
		for(int i=0,u,v;i<n-1;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		db();
		while(m--)
		{
			int k;
			scanf("%d",&k);
			as.clear();bs.clear();
			for(int i=0,tmp;i<k;i++)
			{
				scanf("%d",&tmp);
				as.push_back(tmp);
			}
			scanf("%d",&k);
			for(int i=0,tmp;i<k;i++)
			{
				scanf("%d",&tmp);
				bs.push_back(tmp);
			}
			solve();
		}
	}
}
