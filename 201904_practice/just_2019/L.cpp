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
const int maxn=1e3+7;
int maze[maxn][maxn];
int cur[maxn][maxn];
int n,m,h,w;
int dp[maxn][maxn];
bool check(int k)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(maze[i-1][j-1]>=k) cur[i][j]=1;
			else cur[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=-dp[i-1][j-1]+dp[i-1][j]+dp[i][j-1]+cur[i][j];
		}
	}
	int tar=(h*w+1)/2;
	for(int i=h;i<=n;i++)
	{
		for(int j=w;j<=m;j++)
		{
			int res=dp[i][j]-dp[i-h][j]-dp[i][j-w]+dp[i-h][j-w];
			if(res<tar) return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&h,&w);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&maze[i][j]);
		}
	}
	int l=1,r=n*m,ans=r;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid-1;
		else l=mid+1,ans=mid;
	}
	printf("%d\n",ans);
}
