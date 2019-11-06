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
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
const int maxn=305;
int maze[maxn][maxn];
int pre[maxn][maxn];
int mi[maxn][maxn][maxn];
int dp[2];
int main()
{
	int n,m,p;
	while(~scanf("%d%d%d",&n,&m,&p))
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&maze[i][j]);
				//pre[i][j]=pre[i][j-1]+maze[i][j];
				sum+=maze[i][j];
			}
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
				pre[j][i]=pre[j][i-1]+maze[i][j];
		}
		for(int i=1;i<=m;i++)
		{
			for(int l=1;l<=n;l++)
			{
				for(int r=l;r<=n;r++)
				{
					if(l==r) mi[i][l][r]=maze[l][i];
					else mi[i][l][r]=min(maze[r][i],mi[i][l][r-1]);
				}
			}
		}
		int ans=-0x3f3f3f3f;
		for(int l=1;l<=n;l++)
		{
			for(int r=l;r<=n;r++)
			{
				dp[0]=0;dp[1]=-0x3f3f3f3f;
				for(int i=1;i<=m;i++)
				{
					int cur=pre[i][r]-pre[i][l-1];
					int tmp=dp[0];
					dp[0]=max(tmp,0)+cur;
					dp[1]=max(max(tmp,0)+cur-mi[i][l][r]+p,dp[1]+cur);
	//				dbg(l,r,i,mi[i][l][r],cur,dp[0],dp[1]);
					if(l==1&&r==n&&i==m&&dp[0]==sum) ans=max(ans,dp[1]);
					else ans=max({ans,dp[1],dp[0]});
				}
			}
		}
		printf("%d\n",ans);
	}
}
