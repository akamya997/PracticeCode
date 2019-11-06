#include <iostream>
#include<cstdio>
#include<cmath>
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
int main()
{
	int a,b;
	double r=(sqrt(5.0)+1)/2;
	while(~scanf("%d%d",&a,&b))
	{
		if(a>b) swap(a,b);
		if(a==(int)(r*abs(b-a))) puts("0");
		else puts("1");
	}
}
