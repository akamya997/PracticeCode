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
int n,m,a,p;
const int maxn=1e6+7;
vector<int> prime;
int mu[maxn];
bool vis[maxn];
ll quick(ll a,ll b,int mod)
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
int lp;
ll fib[maxn];
void db()
{
	mu[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!vis[i]) {mu[i]=-1;vis[i]=1;prime.push_back(i);}
		for(auto &pri:prime)
		{
			if(pri*i>=maxn) break;
			if(i%pri==0)
			{
				vis[i*pri]=1;
				mu[i*pri]=0;
				break;
			}
			vis[i*pri]=1;
			mu[i*pri]=mu[i]*mu[pri];
		}
	}
	fib[1]=fib[2]=1;
	for(int i=3;i<maxn;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		fib[i]%=p;
		if(!lp&&fib[i]==1&&fib[i-1]==1) lp=i-2;
	}
}
ll getg(int d)
{
	if(a==1) return 0;
	ll num=(quick(a,d,lp)-1+lp)%lp;
	return fib[num];
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&p);
	db();
	ll ans=0;
	for(int d=1;d<=min(n,m);d++)
	{
		ll g=getg(d);
		ll cur=0;
		for(int k=1;k<=min(n/d,m/d);k++)
			cur=(cur+1LL*mu[k]*(n/d/k)%p*(m/d/k)%p+p)%p;
		ans=(ans+cur*g%p)%p;
	}
	printf("%lld\n",ans);
}
