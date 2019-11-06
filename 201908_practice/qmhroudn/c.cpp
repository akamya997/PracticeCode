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
const int INF=0x3f3f3f3f;
ll two[33];
int main()
{
	ll x;
	two[0]=1;
	for(int i=1;i<=32;i++) two[i]=two[i-1]*2;
	while(cin>>x)
	{
		if(x==(1LL<<31)-1) cout<<(1LL<<31)<<endl;
		else cout<<two[__builtin_popcountll(x)+1]<<endl;
	}
}
