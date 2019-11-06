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
const int maxn=1e6+7;
int dp[maxn];
int nxt[maxn][26];
char s[maxn],t[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	int cur[27];
	memset(cur,-1,sizeof(cur));
	for(int i=n;i>=0;i--)
	{
		for(int j=0;j<26;j++) nxt[i][j]=cur[j];
		cur[s[i]-'a']=i;
	}
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=m;j>=1;j--)
		{
			if(dp[j-1]==-1) continue;
			int cur=nxt[dp[j-1]][t[i]-'a'];
			if(cur==-1) continue;
			if(dp[j]==-1) dp[j]=cur;
			else dp[j]=min(dp[j],cur);
			ans=max(ans,j);
		}
	}
	printf("%d\n",ans);
}
