#include <cstdio>
#include <iostream>
#include <vector>
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
	int n,m;
	while(~scanf("%d%d",&n,&m)&&n+m)
	{
		vector<int> ti;
		while(n&&m)
		{
			if(n>m) swap(n,m);
			ti.push_back(m/n);
			m%=n;
		}
		bool all=1;
		for(int i=0;i<ti.size();i++)
			if(ti[i]!=1) all=0;
		if(all)
		{
			if(ti.size()&1) puts("Stan wins");
			else puts("Ollie wins");
		}
		else{
			int pp=1;
			for(int i=0;i<ti.size();i++)
			{
				if(ti[i]!=1) break;
				pp^=1;
			}
			if(pp) puts("Stan wins");
			else puts("Ollie wins");
		}
	}
}
