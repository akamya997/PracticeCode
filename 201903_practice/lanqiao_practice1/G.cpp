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
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int ans=0;
	ans=(ceil(n/2.0)+n-(ceil(n/2.0)))*(m/2);
	if(m%2==1)
	{
		ans+=ceil(n/2.0);
	}
	printf("%d\n",ans);
}
