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
const int mod=998244353;
const int maxn=1e6+7;
long long ans[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int w,n,q;
	cin>>w>>q;
	ans[1]=w;
	for(int i=2;i<maxn;i++) ans[i]=ans[i-1]*(2*i-1)%mod;
	while(q--)
	{
		cin>>n;
		cout<<ans[n]<<endl;
	}
}
