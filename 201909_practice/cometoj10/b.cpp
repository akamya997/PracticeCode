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
const int maxn=1e5+7;
int arr[maxn];
map<int,int> cnt;
int c2,c3,c1;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&arr[i]);
		cnt[arr[i]]++;
	}
	for(auto u:cnt) 
	{
		if(u.second==1) c1++;
		else if(u.second==2) c2++;
		else c3++;
	}
	int ans=0;
	if(!c2&&!c3) ans=c1;
	else if(!c3)
		ans=c2-1+c1;
	else{
		ans=c3-1+c2+c1/2;
	}
	printf("%d\n",ans);
}
