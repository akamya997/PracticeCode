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
typedef long long ll;
const int maxn=1e4+7;
const int INF=0x3f3f3f3f;
ll arr[maxn];
ll dp[5005][maxn];
int deq[maxn];
ll calc(int i,int u)
{
	return dp[u][i]+arr[i+1]*arr[i+1];
}
ll getdown(int p,int q)
{
	return arr[p+1]-arr[q+1];
}
int main()
{
	int n,m;
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
		sort(arr+1,arr+1+n);
		for(int i=1;i<=n;i++) dp[1][i]=(arr[i]-arr[1])*(arr[i]-arr[1]);
		for(int i=2;i<=m;i++)
		{
			int head=0,tail=0;
			deq[++tail]=0;
			for(int j=i-1;j<=n;j++)
			{
				while(head+1<tail&&calc(j,i-1)-calc(deq[head+1],i-1)<=2*arr[j]*getdown(j,deq[head+1])) head++;
				dbg(deq[head+1]);
				dp[i][j]=dp[i-1][deq[head+1]]+(arr[j]-arr[deq[head+1]+1])*(arr[j]-arr[deq[head+1]+1]);
				while(head+1<tail&&(calc(j,i-1)-calc(deq[tail],i-1))*getdown(deq[tail],deq[tail-1])<=(calc(deq[tail],i-1)-calc(deq[tail-1],i-1))*getdown(j,deq[tail])) tail--;
				deq[++tail]=j;
			}
		}
		printf("Case %d: %lld\n",++kas,dp[m][n]);
	}
}
