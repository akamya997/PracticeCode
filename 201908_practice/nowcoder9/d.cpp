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
const int maxn=38;
ll a[maxn];
map<ll,ll> st;
ll ans1,ans2;
int n;
ll s;
void dfs(int id,ll val,ll state)
{
	if(id==n/2)
	{
		st[val]=state;
		return;
	}
	dfs(id+1,val,state);
	dfs(id+1,val+a[id],state|(1LL<<id));
}
void dfs2(int id,ll val,ll state)
{
	if(id==n)
	{
		if(st.count(s-val))
		{
			ans1=st[s-val];
			ans2=state;
		}
		return;
	}
	dfs2(id+1,val,state);
	dfs2(id+1,val+a[id],state|=(1LL<<(id-n/2)));
}
int main()
{
	scanf("%d%lld",&n,&s);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	dfs(0,0,0);
	dfs2(n/2,0,0);
	for(int i=0;i<n/2;i++)
	{
		if(ans1>>i&1)
			printf("1");
		else printf("0");
	}
	for(int i=0;i<n-n/2;i++)
	{
		if(ans2>>i&1)
			printf("1");
		else printf("0");
	}
	puts("");
}
