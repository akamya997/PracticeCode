#include<bits/stdc++.h>
using namespace std;
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
const int maxn=1e5+7;
int arr[maxn];
vector<int> all;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	for(int i=1;i<n;i++)
		all.push_back(arr[i]-arr[i-1]);
	int gap=0;
	for(int i=0;i<all.size();i++)
		gap=__gcd(gap,all[i]);
	long long ans=0;
	int ma=0;
	for(int i=0;i<all.size();i++)
	{
		ans+=all[i]/gap-1;
		ma=max(ma,all[i]/gap);
	}
	ans-=ma-1;
	printf("%lld\n",ans);
}
