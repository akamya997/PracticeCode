#include <iostream>
#include<cstring>
#include <set>
#include <cstdio>
#include <vector>
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
const int maxn=1005;
int G[maxn][maxn];
int sg[maxn];
int n;
int dfs(int u)
{
	if(sg[u]!=-1) return sg[u];
	int ret=0;
	set<int> ext;
	for(int i=0;i<n;i++)
	{
		if(G[u][i]) ext.insert(dfs(i));
	}
	for(int i=0;;i++)
		if(!ext.count(i))
		{ret=i;break;}
	return sg[u]=ret;
}
int main()
{
	while(~scanf("%d",&n)&&n)
	{
		memset(G,0,sizeof(G));
		for(int i=0;i<n;i++)
		{
			sg[i]=-1;
			int k;
			scanf("%d",&k);
			while(k--)
			{
				int v;
				scanf("%d",&v);
				G[i][v]=1;
			}
		}
		for(int i=0;i<n;i++)
			dfs(i);
		int m;
		while(~scanf("%d",&m)&&m)
		{
			int ans=0;
			while(m--)
			{
				int tmp;
				scanf("%d",&tmp);
				ans^=sg[tmp];
			}
			if(ans) puts("WIN");
			else puts("LOSE");
		}
	}

}
