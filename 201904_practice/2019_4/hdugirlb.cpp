#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=3005;
struct shop{
	int x,c;
	bool operator<(const shop& a)const{
		return x<a.x;
	}
}sp[maxn];
ll pre[maxn],dp[maxn][maxn];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++) scanf("%d%d",&sp[i].x,&sp[i].c);
		sort(sp+1,sp+n+1);
		memset(dp,0x3f,sizeof(dp));
		dp[1][1]=sp[1].c;
		for(int i=2;i<=n;i++) dp[i][1]=dp[i-1][1]+sp[i].x-sp[1].x;
		for(int i=2;i<=n;i++)
		{
			ll pre=INF;
			for(int j=1;j<=i-1;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j]+sp[i].x-sp[j].x);
				pre=min(pre,dp[i-1][j]);
			}
			dp[i][i]=pre+sp[i].c;
		}
		ll ans=INF;
		for(int i=1;i<=n;i++) ans=min(ans,dp[n][i]);
		printf("%lld\n",ans);
	}
}
