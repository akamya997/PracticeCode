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
const int maxn=2e5+7;
int arr[maxn];
int n,k;
int dp[maxn][20];
void ST()
{
	for(int i=1;i<=n;i++) dp[i][0]=arr[i];
	for(int j=1;(1<<j)<=n+1;j++)
	{
		for(int i=1;(i+(1<<j)-1)<=n;i++)
		{
			dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
		}
	}
}
int query(int l,int r)
{
	int k=(int)(log((double)(r-l+1))/log(2.0));
	return max(dp[l][k],dp[r-(1<<k)+1][k]);
}
int check(int cur)
{
	int l=1,r=n/cur,step=n/cur;
	int ret=0;
	while(r<=n)
	{
		ret+=query(l,r);
		l+=step;r+=step;
	}
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin>>n>>k&&n>=0&&k>=0)
	{
		for(int i=1;i<=n;i++) cin>>arr[i];
		ST();
		int l=1,r=n,ans=-1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid)>=k) r=mid-1,ans=mid;
			else l=mid+1;
		}
		cout<<ans<<endl;
	}

}
