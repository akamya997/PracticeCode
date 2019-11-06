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
const int maxn=26;
char dp[1<<maxn];
int e[maxn];
map<int,int> lb;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0,u,v;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		e[u]|=(1<<v);
		e[v]|=(1<<u);
	}
	for(int i=0;i<26;i++)
		lb[1<<i]=i;
	for(int i=0;i<n;i++)
	{
		e[i]|=(1<<i);
		e[i]=~e[i];
	}
	int ans=0;
	for(int i=1;i<(1<<n);i++)
	{
		int cur=(i&-i);
		dp[i]=max(dp[i-cur],char(dp[i&e[lb[cur]]]+1));
		ans+=dp[i];
	}
	printf("%d\n",ans);
}
