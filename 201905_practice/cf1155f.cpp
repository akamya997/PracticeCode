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
const int maxn=15;
struct Edge{
	int u,v;
};
int G[maxn][maxn];
vector<Edge> ans[1<<15];
int dp[maxn];
int n,m;
bool ok(int S,int T)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(G[i][j]&&S&(1<<i)&&T&(1<<j))
			{
				cnt++;
				if(cnt>=2) return true;
			}
		}
	}
	return false;
}
vector<Edge> merge(int S,int T)
{
	vector<Edge> ret=ans[S];
	for(auto i:ans[T]) ret.push_back(i);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(G[i][j]&&S&(1<<i)&&T&(1<<j))
			{
				cnt++;
				ret.push_back(Edge {i,j});
				if(cnt>=2) return ret;
			}
		}
	}
	assert(0);
	return ret;
}
int main()
{
	memset(dp,0x3f,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--,v--;
		G[u][v]=G[v][u]=1;
	}
	for(int i=0;i<n;i++)
		dp[1<<i]=0;
	for(int S=0;S<(1<<n);S++)
	{
		for (int T = S; T; T = (T - 1) & S)
		{
			if(ok(S,T))
			{
				if(dp[S]>dp[T]+dp[S-T]+2)
				{
					dp[S]=dp[T]+dp[S-T]+2;
					ans[S]=merge(S,T);
				}
			}
		}
		dbg(S,dp[S]);
	}
	printf("%d\n",(int)ans[(1<<n)-1].size());
	for(auto i:ans[(1<<n)-1])
		printf("%d %d\n",i.u+1,i.v+1);


}
