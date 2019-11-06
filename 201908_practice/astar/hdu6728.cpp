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
const int maxn=3e3+7;
int arr[maxn];
vector<int> all;
vector<int> delta;
ll dp[maxn][maxn];
int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin();
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		all.clear();
		delta.clear();
		int n;
		scanf("%d",&n);
		all.push_back(1);
		for(int i=2;i<=n;i++)
		{
			scanf("%d",&arr[i]);
			all.push_back(arr[i]);
		}
		sort(all.begin(),all.end());
		all.erase(unique(all.begin(),all.end()),all.end());
		int sz=all.size();
		for(int i=0;i<sz;i++)
			for(int j=0;j<i;j++)
				all.push_back(all[i]-all[j]);
		sort(all.begin(),all.end());
		all.erase(unique(all.begin(),all.end()),all.end());
		for(int i=1;i<all.size();i++) delta.push_back(all[i]-all[i-1]);
		for(int i=2;i<=n;i++)
			arr[i]=getid(arr[i]);
		for(int i=0;i<all.size();i++) dp[1][i]=1;
		for(int i=2;i<=n;i++)
		{
			dp[i][arr[i]]=dp[i-1][arr[i]];
			for(int j=0;j<arr[i];j++)
				dp[i][arr[i]]=(dp[i][arr[i]]+dp[i-1][j]*delta[j]%mod)%mod;
			for(int j=0;j<arr[i];j++)
			{
				dp[i][j]=(dp[i-1][arr[i]-1-j]+dp[i-1][arr[i]])%mod;
				if(j<arr[i]/2)
					swap(delta[j],delta[arr[i]-1-j]);
				dbg(i,j,dp[i][j]);
			}
			dbg(i,arr[i],dp[i][arr[i]]);
		}
		ll ans=0;
		for(int i=0;i<all.size();i++) 
			ans=(ans+dp[n][i])%mod;
		printf("%lld\n",ans);
	}
}
