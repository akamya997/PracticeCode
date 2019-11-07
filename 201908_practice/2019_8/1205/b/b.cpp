#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int INF=0x3f3f3f3f;
const int maxn=1e5+7;
int G[65][65];
int ans=INF;
bool vis[65];
void dfs(int u,int fa,int len)
{
	dbg(u,fa,len);
	if(vis[u])
	{
		ans=min(ans,len);
		return;
	}
	vis[u]=1;
	for(int i=0;i<61;i++)
	{
		if(G[u][i]&&i!=fa)
		{
			dfs(i,u,len+1);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll tmp;
		cin>>tmp;
		static vector<int> cur;
		cur.clear();
		for(int j=0;j<61;j++)
			if(tmp>>j&1)
				cur.push_back(j);
		for(int j=0;j<cur.size();j++)
			for(int k=0;k<j;k++)
				G[cur[k]][cur[j]]=G[cur[j]][cur[k]]=1;
	}
	for(int i=0;i<61;i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(i,-1,0);
	}
	if(ans==INF) ans=-1;
	cout<<ans<<endl;
}
