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
const int maxn=1e3+7;
long long dp[maxn][maxn];
long long pre[maxn];
long long sq[maxn];
int n,m;
long long getup(int u,int i,int j)
{
	return 2*dp[u][i]+pre[i]*pre[i]+sq[i]-(2*dp[u][j]+pre[j]*pre[j]+sq[j]);
}
long long getdown(int i,int j){return pre[i]-pre[j];}
void upd(int i,int cur,int k)
{
	dp[i][cur]=dp[i-1][k]+((pre[cur]-pre[k])*(pre[cur]-pre[k])-(sq[cur]-sq[k]))/2;
}
int main()
{
	while(~scanf("%d%d",&n,&m)&&n+m)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&pre[i]);
			sq[i]=sq[i-1]+pre[i]*pre[i];
			pre[i]+=pre[i-1];
		}
		int deq[maxn];
		int head=0,tail=0;
		for(int j=1;j<=n;j++) upd(1,j,0);
		for(int i=2;i<=m+1;i++)
		{
			head=0,tail=0;
			deq[++tail]=0;
			for(int j=1;j<=n;j++)
			{
				while(head+1<tail&&getup(i-1,deq[head+2],deq[head+1])<=2*pre[j]*getdown(deq[head+2],deq[head+1])) head++;
				upd(i,j,deq[head+1]);
				while(head+1<tail&&getup(i-1,j,deq[tail])*getdown(deq[tail],deq[tail-1])<=getup(i-1,deq[tail],deq[tail-1])*getdown(j,deq[tail])) tail--;
				deq[++tail]=j;
			}
		}
		printf("%lld\n",dp[m+1][n]);
	}
}
