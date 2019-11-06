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
const int maxn=1e5+7;
int dp[maxn];
void db()
{
	dp[0]=1;
	for(int i=1;i<maxn;i++)
	{
		if(i>=3)
			dp[i]=(dp[i-1]+dp[i-3])%mod;
		else dp[i]=dp[i-1];
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	db();
	int T;
	cin>>T;
	while(T--)
	{
		int n,x,y;
		cin>>n>>x>>y;
		int tar=y-x-2;
		if(x==1)
			tar++;
		if(y==n) tar++;
		if(tar<0) cout<<"0\n";
		else cout<<dp[tar]<<'\n';
	}
}
