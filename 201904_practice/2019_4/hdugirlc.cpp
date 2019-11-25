#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn=1e6+7;
int arr[maxn];
int suf[maxn],pre[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>arr[i];
		for(int i=1;i<=n;i++)
			pre[i]=__gcd(pre[i-1],arr[i]);
		for(int i=n;i>=1;i--)
			suf[i]=__gcd(suf[i+1],arr[i]);
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=max(ans,__gcd(pre[i-1],suf[i+1]));
		cout<<ans<<endl;
	}
}
