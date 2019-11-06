#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
map<int,int> dp[32];
const int mod=1e9+7;
int dfs(int k,int n)
{
	if(n==1) return 0;
	if(k==1) return 1;
	if(dp[k].count(n)) return dp[k][n];
	ll ret=0;
	for(int i=2;i<=n;i++)
	{
		if(n%i==0)
			ret=(ret+dfs(k-1,n/i))%mod;
	}
	return dp[k][n]=ret;
}
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans=(ans+dfs(k,i))%mod;
		cout<<ans<<endl;
	}
}
