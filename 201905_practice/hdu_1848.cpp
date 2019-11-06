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
const int maxn=1005;
int sg[maxn];
vector<int> all;
int getsg(int x)
{
	if(sg[x]!=-1) return sg[x];
	set<int> ext;
	int ret=0;
	for(int i=0;i<all.size();i++)
	{
		int u=all[i];
		if(u>x) break;
		ext.insert(getsg(x-u));
	}
	for(int i=0;;i++)
	{
		if(!ext.count(i))
		{
			ret=i;break;
		}
	}
	return sg[x]=ret;
}
void db()
{
	memset(sg,-1,sizeof(sg));
	all.push_back(1);
	all.push_back(2);
	while(all.back()<1000)
		all.push_back(all[all.size()-1]+all[all.size()-2]);
	getsg(1000);
}
int main()
{
	int m,n,p;
	db();
	while(~scanf("%d%d%d",&m,&n,&p)&&m+n+p)
	{
		if(sg[m]^sg[n]^sg[p]) puts("Fibo");
		else puts("Nacci");
	}
}
