#include <iostream>
#include <cstring>
#include <cstdio>
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
vector<int> all;
int n;
int sg[21][1<<14];
bool getsg(int pos,int remain)
{
	pos%=n;
	if(sg[pos][remain]!=-1) return sg[pos][remain];
	if(!remain) return 1;
	bool win=0;
	for(int i=1;i<=all[pos];i++)
	{
		if(i>remain) break;
		if(!getsg(pos+1,remain-i))
		{
			win=1;
			break;
		}
	}
	return sg[pos][remain]=win;
}
int main()
{
	while(~scanf("%d",&n)&&n)
	{
		n*=2;
		all.clear();
		memset(sg,-1,sizeof(sg));
		int s;scanf("%d",&s);
		for(int i=0;i<n;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			all.push_back(tmp);
		}
		int ans=getsg(0,s);
		printf("%d\n",ans);
	}
}
