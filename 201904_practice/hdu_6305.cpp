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
const int mod=1e9+7;
const int maxn=1<<20;
int arr[maxn];
int lc[maxn],fa[maxn],rc[maxn];
ll fac[maxn];
void db()
{
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
}
ll ans=1;
ll dfs(int u)
{
	if(u==-1) return 0;
	ll ret=0;
	ret=dfs(lc[u]);
	ret+=dfs(rc[u])+1;
	ans=ans*ret%mod;
	return ret;
}
ll quick(ll a,ll b)
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
ll inv(ll a){return quick(a,mod-2);}
int main()
{
	int T;
	db();
	scanf("%d",&T);
	while(T--)
	{
		ans=1;
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			fa[i]=lc[i]=rc[i]=-1;
		}
		stack<int> st;
		for(int i=0;i<n;i++)
		{
			int last=-1;
			while(!st.empty()&&arr[i]>arr[st.top()]) last=st.top(),st.pop();
			if(!st.empty()) rc[st.top()]=i,fa[i]=st.top();
			lc[i]=last;
			if(~last) fa[last]=i;
			st.push(i);
		}
		int root=-1;
		for(int i=0;i<n;i++)
			if(!~fa[i]) root=i;
		dfs(root);
		printf("%lld\n",inv(ans)*n%mod*inv(2)%mod);
	}
}
