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
const int mod=998244353;
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
const int maxn=3e3+7;
int dp[maxn];
int C[maxn][maxn];
inline int ADD(int a,int b)
{
	a+=b;
	if(a>=mod) a-=mod;
	return a;
}
void init()
{
	for(int i=0;i<maxn;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=ADD(C[i-1][j-1],C[i-1][j]);
	}
}
char s[maxn],t[maxn];
int main()
{
	init();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		scanf("%s%s",s+1,t+1);
		for(int i=0;i<=m;i++)
				dp[i]=0;
		dp[0]=1;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0') continue;
			for(int j=m;i+j<=n;j++)
				ans=ADD(ans,C[n-i][j]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=1;j--)
			{
				if(s[i]>t[j]&&n-i>=m-j)
					ans=ADD(ans,dp[j-1]*C[n-i][m-j]);
				if(s[i]==t[j])
					dp[j]=ADD(dp[j-1],dp[j]);
			}
		}
		printf("%d\n",ans);
	}
}
