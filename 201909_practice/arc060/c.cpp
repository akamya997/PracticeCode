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
const int maxn=55;
ll dp[maxn][maxn][maxn*maxn];
int x[maxn];
int main()
{
	int n,a;
	cin>>n>>a;
	for(int i=1;i<=n;i++) cin>>x[i];
	ll ans=0;
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int s=0;s<=j*50;s++)
			{
				if(s>=x[i]&&j>=1)
					dp[i][j][s]=dp[i-1][j][s]+dp[i-1][j-1][s-x[i]];
				else dp[i][j][s]=dp[i-1][j][s];
				if(j&&i==n&&s%j==0&&s/j==a) ans+=dp[i][j][s];
			}
		}
	}
	cout<<ans<<endl;
}
