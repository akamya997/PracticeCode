#include <algorithm>
#include <cstdio>
#include<iostream>
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
const int maxn=2e3+7;
int arr[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&arr[i]);
		sort(arr+1,arr+n+1);
		for(int i=n;i>0;i-=2)
			ans^=(arr[i]-arr[i-1]-1);
		if(ans&1) puts("Georgia will win");
		else puts("Bob will win");
	}
}
