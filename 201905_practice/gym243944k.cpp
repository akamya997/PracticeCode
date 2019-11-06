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
const int maxn=1e5+7;
vector<int> G[maxn];
int dfn[maxn];
int ti;
vector<int> leaf;
void dfs(int u,int fa=-1)
{
	dfn[u]=++ti;
	for(auto v:G[u])
	{
		if(v==fa) continue;
		dfs(v,u);
	}
	if(G[u].size()==1) leaf.push_back(u);
}
int main()
{
	int n,h;
	scanf("%d%d",&n,&h);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(h);
	sort(leaf.begin(),leaf.end(),[](int x,int y){return dfn[x]<dfn[y];});
	printf("%d\n",(int)(leaf.size()+1)/2);
	for(int i=0;i<(leaf.size()+1)/2;i++)
		printf("%d %d\n",leaf[i],leaf[i+(leaf.size()+1)/2]);
}
