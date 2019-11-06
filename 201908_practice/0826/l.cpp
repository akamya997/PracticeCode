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
int nxt[maxn];
PII ans[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	nxt[n]=n+1;
	bool tp=0;
	if(arr[n-1]<=arr[n]) tp=1;
	for(int i=n-1;i>=1;i--)
	{
		if(arr[i]<=arr[i+1]&&tp) nxt[i]=nxt[i+1];
		else if(arr[i]>arr[i+1]&&!tp)
			nxt[i]=nxt[i+1];
		else if(arr[i]<=arr[i+1]&&!tp)
		{
			tp=1;
			nxt[i]=i+2;
		}
		else if(arr[i]>arr[i+1]&&tp)
		{
			tp=0;
			nxt[i]=i+2;
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n;)
		{
			int len=nxt[j]-j;
			ans[i].first++;
			if(len>=i)
				j=nxt[j];
			else{
				j+=i;
				ans[i].second+=i-len;
				if(j>n) ans[i].second-=j-n-1;
			}
		}
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int mr;
		scanf("%d",&mr);
		printf("%d %d\n",ans[mr].first,ans[mr].second);
	}
}
