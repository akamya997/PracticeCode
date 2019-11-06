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
bool can[11];
bool check(int u)
{
	while(u)
	{
		if(!can[u%10]) return false;
		u/=10;
	}
	return true;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<=9;i++) can[i]=1;
	for(int i=0,t;i<k;i++)
	{
		scanf("%d",&t);
		can[t]=0;
	}
	do{
		if(check(n)) break;
	}while(n++);
	printf("%d\n",n);
}
