#include <bits/stdc++.h>
#include "testlib.h"
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
int main(int argc,char* argv[])
{
	registerValidation(argc,argv);
	int T = inf.readInt(1,100,"T");
	ll up=1e18;
	while(T--)
	{
		int n=inf.readInt(1,100000,"n");
		inf.readSpace();
		ll tar=inf.readLong(1LL,up,"tar");
		inf.readEoln();
	}
	inf.readEof();
}
