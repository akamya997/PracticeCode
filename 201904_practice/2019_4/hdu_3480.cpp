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
const int maxn=1e4+7;
int arr[maxn];
int dp[5005][maxn];
int deq[maxn];
int getup(int rd,int i,int j)
{
	return dp[rd][i]-dp[rd][j]+arr[i+1]*arr[i+1]-arr[j+1]*arr[j+1];
}
int getdown(int i,int j)
{
	return arr[i+1]-arr[j+1];
}
void upd(int rd,int i,int k)
{
	dp[rd][i]=dp[rd-1][k]+(arr[i]-arr[k+1])*(arr[i]-arr[k+1]);
}
int main()
{
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
		sort(arr+1,arr+1+n);
		for(int i=1;i<=n;i++) dp[1][i]=(arr[i]-arr[1])*(arr[i]-arr[1]);
		for(int i=2;i<=m;i++)
		{
			int head=0,tail=0;
			for(int j=1;j<=n;j++)
			{
				while(head+1<tail&&getup(i-1,deq[head+2],deq[head+1])<=2*arr[j]*getdown(deq[head+2],deq[head+1])) head++;
				upd(i,j,deq[head+1]);
				while(head+1<tail&&getup(i-1,j,deq[tail])*getdown(deq[tail],deq[tail-1])<=getup(i-1,deq[tail],deq[tail-1])*getdown(j,deq[tail])) tail--;
				deq[++tail]=j;
			}
		}
		printf("Case %d: %d\n",++kas,dp[m][n]);
	}
}
