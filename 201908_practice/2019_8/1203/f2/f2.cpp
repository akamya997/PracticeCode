#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
ll quick(ll a,ll b,ll mod)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a,ll mod){return quick(a,mod-2,mod);}
const int maxn=6e4+7;
int dp[maxn];
bool cmp(PII a,PII b)
{
	return max(a.first,-a.second)<max(b.first,-b.second);
}
int main()
{
	int n,r;
	cin>>n>>r;
	vector<PII> pos,neg;
	for(int i=0,a,b;i<n;i++)
	{
		cin>>a>>b;
		if(b>=0) pos.emplace_back(a,b);
		else neg.emplace_back(a,b);
	}
	sort(pos.begin(),pos.end());
	sort(neg.begin(),neg.end());
	int ans=0;
	for(auto u:pos)
	{
		if(u.first<=r)
		{
			r+=u.second;
			ans++;
		}
		else break;
	}
	dbg(r);
	for(auto u:neg)
	{
		dbg(u.first,u.second);
		for(int i=r;i>=max(u.first,-u.second);i--)
		{
			dp[i]=max(dp[i],dp[i+u.second]+1);
			dbg(i,dp[i]);
		}
		dbg(dp[r]);
	}
	cout<<ans+dp[r]<<endl;
}
