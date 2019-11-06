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
ll quick(ll a,ll b,ll mod)
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
inline ll inv(ll a,ll mod){return quick(a,mod-2,mod);}
ll mod;
ll dp[66][33][33][33];
ll invtwo[1005];
ll C[105][105];
ll pr[105][105];
void init()
{
	for(int i=0;i<1005;i++)
		invtwo[i]=quick(inv(2,mod),i,mod);
	for(int i=0;i<105;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	for(int l=1;l<=30;l++)
	{
		for(int r=1;r<=30;r++)
			pr[l][r]=quick(1-invtwo[l]+mod,r,mod);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d%lld",&n,&m,&mod);
		init();
		memset(dp,0,sizeof(dp));
		dp[0][1][0][1]=1;
		ll ans=0;
		for(int i=0;i<n+m-1;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=0;k<=m;k++)
				{
					for(int l=1;l<=max(n,m);l++)
					{
						if(!dp[i][j][k][l]) continue;
						if(i&1)
						{
							for(int r=1;r+j<=n;r++)
							{
								dp[i+1][j+r][k][r]=(dp[i+1][j+r][k][r]+dp[i][j][k][l]*invtwo[l*(n-j-r)]%mod*pr[l][r]%mod*C[n-j][r]%mod)%mod;
							}
						}
						else{
							for(int r=1;r+k<=m;r++)
							{
								dp[i+1][j][k+r][r]=(dp[i+1][j][k+r][r]+invtwo[l*(m-k-r)]*C[m-k][r]%mod*dp[i][j][k][l]%mod*pr[l][r]%mod)%mod;
							}
						}
					}
				}
			}
		}
		ll invm=inv(m,mod);
		for(int i=1;i<=n+m;i+=2)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=m;k++)
					for(int l=1;l<=max(n,m);l++)
						if(dp[i][j][k][l])
							ans=(ans+1LL*i*dp[i][j][k][l]%mod*invm%mod*l%mod)%mod;
	//	ans=ans*inv(m,mod)%mod;
		printf("%lld\n",ans);
	}
}
