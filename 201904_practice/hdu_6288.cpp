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
int a,b;
ll k;
bool check(ll cur)
{
	ll rhs=k;
	for(int i=0;i<a;i++) rhs/=cur;
	for(int i=0;i<b;i++) rhs/=ceil(log2(cur));
	return rhs>=1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		scanf("%lld",&k);
		ll l=1,r=1e18,ans=0;
		while(l<=r)
		{
			ll mid=l+(r-l+1)/2;
			if(check(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%lld\n",ans);
	}
}
