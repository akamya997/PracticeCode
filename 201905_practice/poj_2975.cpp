#include <iostream>
#include <cstdio>
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
const int maxn=1e4+7;
int arr[maxn];
int cnt[maxn];
int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cnt[i]=0;
			scanf("%d",&arr[i]);
			ans^=arr[i];
		}
		int res=0;
		for(int i=1;i<=n;i++)
			if((ans^arr[i])<arr[i]) res++;
		if(!ans) res=0;
		printf("%d\n",res);
	}
}
