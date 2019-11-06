#include <vector>
#include <map>
#include <algorithm>
#include<cstdio>
#include <iostream>
#include <cstring>
#include <set>
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
const int maxn=1e4+7;
int sg[maxn];
vector<int> all;
vector<int> num[maxn];
void db()
{
	memset(sg,0,sizeof(sg));
	for(int i=0;i<maxn;i++) num[i].clear();
	for(int i=0;i<maxn;i++)
	{
		sort(num[i].begin(),num[i].end());
		num[i].erase(unique(num[i].begin(),num[i].end()),num[i].end());
		bool ok=0;
		for(int j=0;j<num[i].size();j++)
		{
			if(num[i][j]!=j)
			{
				ok=1;
				sg[i]=j;break;
			}
		}
		if(!ok&&num[i].size()) sg[i]=num[i].size();
		for(int j=0;j<all.size();j++)
		{
			int u=all[j];
			if(u+i>=maxn) break;
			num[u+i].push_back(sg[i]);
		}
	}
}
int main()
{
	int k;
	while(~scanf("%d",&k)&&k)
	{
		all.clear();
		for(int i=0,tmp;i<k;i++)
		{
			scanf("%d",&tmp);
			all.push_back(tmp);
		}
		sort(all.begin(),all.end());
		db();
		int m;
		scanf("%d",&m);
		while(m--)
		{
			int l;
			scanf("%d",&l);
			int win=0;
			int tmp;
			while(l--)
			{
				scanf("%d",&tmp);
				win^=sg[tmp];
			}
			printf("%c",win?'W':'L');
		}
		puts("");
	}
}
