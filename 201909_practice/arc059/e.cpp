#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
const int maxn=407;
ll pre[maxn][maxn];
int a[maxn],b[maxn];
ll dp[maxn][maxn];
int main()
{
	for(int j=1;j<=400;j++)
	{
		ll cur=1;
		for(int i=0;i<=400;i++)
		{
			pre[i][j]=(pre[i][j-1]+cur)%mod;
			cur=cur*j%mod;
		}
	}
	int n,c;
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=c;j++)
			for(int k=0;k<=j;k++)
				dp[i][j]=(dp[i][j]+dp[i-1][k]*(pre[j-k][b[i]]-pre[j-k][a[i]-1]+mod)%mod)%mod;
	printf("%lld\n",dp[n][c]);
}
