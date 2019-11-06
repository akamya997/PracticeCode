#include <bits/stdc++.h>
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
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int h,m;
		double zone;
		scanf("%d %d UTC%lf",&h,&m,&zone);
		int tot=h*60+m;
		tot+=round((zone-8)*60);
		while(tot>=1440) tot-=1440;
		while(tot<0) tot+=1440;
		printf("%02d:%02d\n",tot/60,tot%60);
	}
}
