#include<bits/stdc++.h>
using namespace std;
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
int dp[305][305][305];
int dfs(int n,int k,int up)
{
	if(dp[n][k][up]!=-1) return dp[n][k][up];
	if(n==0) return 1;
	if(k==0) return 0;
	int ret=0;
	for(int i=1;i<=min(up,n);i++)
		ret+=dfs(n-i,k-1,i);
	return dp[n][k][up]=ret;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	int n,k;
	cin>>n>>k;
	cout<<dfs(n,k,n)<<endl;
}
