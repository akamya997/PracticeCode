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
vector<int> all;
int maze[105][105];
int dp[105][105];
int g[105*105];
int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
int main()
{
	int n,m,T;
	scanf("%d%d%d",&n,&m,&T);
	T++;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&maze[i][j]);
			all.push_back(maze[i][j]);
		}
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			maze[i][j]=getid(maze[i][j]);
	int len=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(dp[i][j]==0) dp[i][j]=1;
			if(maze[i+1][j]==maze[i][j])
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1);
			if(maze[i][j+1]==maze[i][j])
				dp[i][j+1]=max(dp[i][j+1],dp[i][j]+1);
			len=max(len,dp[i][j]);
		}
	}
	memset(dp,0,sizeof(dp));
	int up=min(T,(n*m)/2);
	for(int k=1;k<=up;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				dp[i][j]=max(dp[i][j],g[maze[i][j]]+1);
				if(maze[i+1][j]>=maze[i][j]) dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1);
				if(maze[i][j+1]>=maze[i][j]) dp[i][j+1]=max(dp[i][j+1],dp[i][j]+1);
			}
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				g[maze[i][j]]=max(g[maze[i][j]],dp[i][j]);
		for(int i=1;i<=all.size();i++) g[i]=max(g[i],g[i-1]);
	}
	ll ans=0;
	for(int i=1;i<=all.size();i++) ans=max(ans,1LL*g[i]);
	ans+=1LL*(T-up)*len;
	printf("%lld\n",ans);
}
