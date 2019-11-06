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
const int maxn=1005;
int l[maxn],r[maxn];
vector<int> all;
int dp[maxn][maxn*4];
int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin();
}
inline int dis(int i,int j)
{
	return (abs(all[i]-all[j])+1)/2;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		all.clear();
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i]>>r[i];
			all.push_back(l[i]);
			all.push_back(r[i]);
			if(l[i]<r[i])
			{
				all.push_back(l[i]+1);
				all.push_back(r[i]-1);
			}
		}
		sort(all.begin(),all.end());
		all.erase(unique(all.begin(),all.end()),all.end());
		for(int i=1;i<=n;i++)
			l[i]=getid(l[i]),r[i]=getid(r[i]);
		int ans=INF;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<all.size();j++)
				dp[i][j]=INF;
		}
		for(int i=0;i<all.size();i++) dp[0][i]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<all.size();j++)
			{
				if(dp[i][j]==INF) continue;
				if(j>=l[i+1]&&j<=r[i+1]) dp[i+1][j]=dp[i][j];
				dp[i+1][l[i+1]]=min(dp[i+1][l[i+1]],dp[i][j]+dis(j,l[i+1]));
				if(l[i+1]!=r[i+1])
					dp[i+1][l[i+1]+1]=min(dp[i+1][l[i+1]+1],dp[i][j]+dis(j,l[i+1]+1));
				dp[i+1][r[i+1]]=min(dp[i+1][r[i+1]],dp[i][j]+dis(j,r[i+1]));
				if(l[i+1]!=r[i+1])
					dp[i+1][r[i+1]-1]=min(dp[i+1][r[i+1]-1],dp[i][j]+dis(j,r[i+1]-1));
				if(i==n-1)
				{
					ans=min({ans,dp[n][l[i+1]],dp[n][r[i+1]],dp[n][j]});
					if(l[i+1]!=r[i+1])
						ans=min({ans,dp[n][l[i+1]+1],dp[n][r[i+1]-1]});
				}
			}
		}
		cout<<ans<<endl;
	}
}
