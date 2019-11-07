#include<bits/stdc++.h>
using namespace std;
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
const int maxn=15e4+7;
const long long INF=-0x3f3f3f3f3f3f3f3f;
long long dp[maxn][2];
long long a[maxn],b[maxn],t[maxn];
int main()
{
	int n,m,d;
	dbg(maxn);
	cin>>n>>m>>d;
	for(int i=1;i<=m;i++)
		cin>>a[i]>>b[i]>>t[i];
	int cc=0;
	for(int i=1;i<=m;i++)
	{
		int pre=t[i-1];
		int cur=t[i];
		long long var=1LL*(cur-pre)*d;//range
		for(int j=0;j<=n;j++) dp[j][cc^1]=INF;
		deque<int> q;
		//f=dp[j+_var][i-1]+a[p]*abs(b[p]-j)
		for(int j=1;j<=n;j++)
		{
			while(!q.empty()&&dp[q.back()][cc]<=dp[j][cc])
			{
				q.pop_back();
			}
			q.push_back(j);
			if(j-q.front()>var) q.pop_front();
			dp[j][cc^1]=max(dp[j][cc^1],dp[q.front()][cc]+b[i]-abs(a[i]-j));
		}
		while(!q.empty()) q.pop_back();
		for(int j=n;j>=1;j--)
		{
			while(!q.empty()&&dp[q.back()][cc]<=dp[j][cc])
			{
				q.pop_back();
			}
			q.push_back(j);
			if(q.front()-j>var) q.pop_front();
			dp[j][cc^1]=max(dp[j][cc^1],dp[q.front()][cc]+b[i]-abs(a[i]-j));
		}
		cc^=1;
	}
	long long ans=INF;
	for(int i=1;i<=n;i++) ans=max(ans,dp[i][cc]);
	cout<<ans<<endl;
}
