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
ll countpre(ll pre,ll n)
{
	ll ret=1,p=10;
	while(pre*p<=n)
	{
		ret+=min(n,pre*p-1+p)-pre*p+1;
		p*=10;
	}
	return ret;
}
ll calc(ll n,ll m)
{
	ll t=0,ret=0;
	while(m)
	{
		t=t*10+m%10;
		m/=10;
		ret+=!t;
	}
	while(t)
	{
		m=m*10;
		ll s=0;
		if(m==0)
			s=m=1;
		for(ll i=s;i<t%10;i++,m++)
			ret+=countpre(m,n);
		if(m<=n) ret++;
		t/=10;
	}
	return ret;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		printf("%lld\n",calc(n,k));
	}
}
