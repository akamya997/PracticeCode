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
int a[]={5,13,24,46};
int main()
{
	for(int i=2;i<=20;i++)
	{
		cout<<i<<":";
		for(int j=0;j<4;j++)
		cout<<a[j]%i<<" ";
		cout<<endl;
	}
}
