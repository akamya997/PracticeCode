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
ll dp[19][19];
int a[maxn];
int d;
ll dfs(int pos,int cnt,int limit)
{
	if(pos==-1)
		return cnt;
	int up=limit?a[pos]:9;
	if(!limit&&dp[pos][cnt]!=-1) return dp[pos][cnt];
	ll ret=0;
	for(int i=0;i<=up;i++)
	{
		if(i==d)
			ret+=dfs(pos-1,cnt+1,limit&&i==up);
		else ret+=dfs(pos-1,cnt,limit&&i==up);
	}
	if(!limit) dp[pos][cnt]=ret;
	return ret;
}
int pos;
inline ll solve(ll cur)
{
	memset(dp,-1,sizeof(dp));
	pos=0;
	while(cur)
	{
		a[pos++]=cur%10;
		cur/=10;
	}
	return dfs(pos-1,0,1);
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		ll x;
		scanf("%d%lld",&d,&x);
		while(x)
		{
			ll cnt=solve(x);
			if(cnt==x) break;
			if(cnt>x) 
			{
				if((cnt-x)/pos==0) x--;
				else x-=(cnt-x)/pos;
			}
			else x=cnt;
			x=max(x,0LL);
		}
		printf("%lld\n",x);
	}
}
