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
const int maxn=1e2+7;
vector<int> prime;
int pm[maxn];
void db()
{
	for(int i=2;i<maxn;i++)
	{
		if(!pm[i]) {pm[i]=i;prime.push_back(i);}
		for(auto p:prime)
		{
			if(i*p>=maxn) break;
			if(i%p==0)
			{
				pm[i*p]=i;
				break;
			}
			pm[i*p]=i;
		}
	}
	for(int i=2;i<=100;i++) cout<<i<<":"<<pm[i]<<endl;
}
int main()
{
	db();
}
