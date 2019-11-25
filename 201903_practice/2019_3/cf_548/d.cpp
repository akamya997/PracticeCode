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
const int mod=1e9+7;
long long quick(long long a,long long b)
{
	long long ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
long long inv(long long a){return quick(a,mod-2);}
void db(int m)
{
	int ret=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(__gcd(i,j)!=1) ret++;
		}
	}
	cout<<ret<<endl;
}
int main()
{
	int m;
	cin>>m;
	db(m);
}
