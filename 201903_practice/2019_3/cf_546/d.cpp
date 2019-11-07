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
const int maxn=3e5+7;
int dep[maxn];
int low[maxn];
bool vis[maxn];
vector<int> G[maxn];
bool cmp(int a,int b)
{
	return dep[a]>dep[b];
}
bool cmp2(int a,int b)
{
	return low[a]>low[b];
}
int dfs(int cur)
{
	vis[cur]=1;
	low[cur]=dep[cur];
	for(int i=0;i<G[cur].size();i++)
	{
		int v=G[cur][i];
		if(dep[v]<dep[cur]) continue;
		if(vis[v]&&low[cur]>=dep[v]-1) low[cur]=max(low[cur],low[v]);
		else if(!vis[v])
		{
			int ret=dfs(v);
			if(low[cur]>=ret-1) low[cur]=max(low[cur],ret);
		}
	}
	return low[cur];
}
vector<int> op;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int tt=0;
	for(int i=1;i<=n;i++)
	{
		int cur;
		scanf("%d",&cur);
		if(i==n) tt=cur;
		dep[cur]=i;
	}
	for(int i=0,u,v;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		if(v==tt) op.push_back(u);
	}
	for(int i=1;i<=n;i++){sort(G[i].begin(),G[i].end(),cmp);reverse(G[i].begin(),G[i].end());}
	sort(op.begin(),op.end(),cmp);
	int ans=0,pos=n;
	for(int i=0;i<op.size();i++)
	{
		dfs(op[i]);
	}
	sort(op.begin(),op.end(),cmp2);
	for(int i=0;i<op.size();i++)
	{
		dbg(op[i]);
		dbg(low[op[i]]);
		if(low[op[i]]>=pos-1)
		{
			pos--;
			ans++;
		}
		else break;
	}
	printf("%d\n",ans);
}
