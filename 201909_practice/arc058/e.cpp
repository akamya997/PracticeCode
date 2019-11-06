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
ll dp[42][1<<18];
int n,x,y,z;
inline int Merge(int cur,int num)
{
	cur<<=num;
	num=1<<(num-1);
	cur|=num;
	cur&=(1<<(x+y+z))-1;
	return cur;
}
bool check(int cur)
{
	return !((cur&(1<<(x+y+z-1)))&&(cur&(1<<(y+z-1)))&&(cur&(1<<(z-1))));
}
ll dfs(int p,int st)
{
	if(p==n)
		return 1;
	if(dp[p][st]!=-1) return dp[p][st];
	ll ret=0;
	for(int i=1;i<=10;i++)
	{
		int nxt=Merge(st,i);
		if(check(nxt)) ret=(ret+dfs(p+1,nxt))%mod;
	}
	return dp[p][st]=ret;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>n>>x>>y>>z;
	cout<<(quick(10,n)-dfs(0,0)+mod)%mod<<endl;
}
