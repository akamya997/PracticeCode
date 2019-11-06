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
const ll INF=0x3f3f3f3f3f3f3f3f;
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
const int maxn=255050;
ll dp[2][2][2][10][10];
int w[maxn];
int main()
{
	memset(dp,0x3f,sizeof(dp));
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	int cur=0;
	dp[0][1][0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int l=0;l<2;l++)
			{
				for(int u=0;u<=k;u++)
				{
					for(int v=0;v<=k;v++)
					{
						if(dp[cur][j][l][u][v]==INF) continue;
						//light
						if(!j&&!l)
						{
							dp[cur^1][l][1][u][v]=min(dp[cur^1][l][1][u][v],dp[cur][j][l][u][v]+w[i]);
							if(v<k)
								dp[cur^1][l][1][u][v+1]=min(dp[cur^1][l][1][u][v+1],dp[cur][j][l][u][v]);
						}
						//no
						else{
							if(u!=k)
								dp[cur^1][l][0][u+1][v]=min(dp[cur^1][l][0][u+1][v],dp[cur][j][l][u][v]+w[i]);
							dp[cur^1][l][0][u][v]=min(dp[cur^1][l][0][u][v],dp[cur][j][l][u][v]);
							dp[cur^1][l][1][u][v]=min(dp[cur^1][l][1][u][v],dp[cur][j][l][u][v]+w[i]);
							if(v<k)
								dp[cur^1][l][1][u][v+1]=min(dp[cur^1][l][1][u][v+1],dp[cur][j][l][u][v]);
						}
						dp[cur][j][l][u][v]=INF;
					}
				}
			}
		}
		cur^=1;
	}
	ll ans=INF;
	for(int j=0;j<2;j++)
	{
		for(int l=0;l<2;l++)
		{
			for(int u=0;u<=k;u++) if(j||l)
				ans=min(ans,dp[cur][j][l][u][u]);
		}
	}
	printf("%lld\n",ans);
}
