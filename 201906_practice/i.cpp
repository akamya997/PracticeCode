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
const int maxn=2e4+7;
char L[maxn],R[maxn];
int lenl,lenr;
int l[maxn],r[maxn];
int curl[maxn],curr[maxn];
ll fac[maxn];
ll ans=0;
const int mod=998244353;
void init()
{
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	for(int i=0;i<lenl;i++)
		l[i]=L[i]-'0';
	for(int i=0;i<lenr;i++)
		r[i]=R[i]-'0';
}
bool solve(int d)
{
	memset(curl,0,sizeof(curl));
	memset(curr,0,sizeof(curr));
	for()
}
int main()
{
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%s",L);
		scanf("%s",R);
		lenl=strlen(L),lenr=strlen(R);
		init();
		int d=2;
		while(solve(d))
			d++;
		printf("%lld\n",ans);
	}
}
