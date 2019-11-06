#include <iostream>
#include<algorithm>
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
const int maxn=1e6+7;
char str[maxn];
int fail[maxn];
int n;
void getfail()
{
	int i=0,j=fail[0]=-1;
	while(i<n)
	{
		while(j!=-1&&str[i]!=str[j]) j=fail[j];
		fail[++i]=++j;
	}
}
typedef pair<int,int> PII;
int main()
{
	int kas=0;
	while(~scanf("%d",&n)&&n)
	{
		scanf("%s",str);
		getfail();
		vector<PII> ans;
		for(int i=1;i<=n;i++)
		{
			if(i!=i-fail[i]&&(i%(i-fail[i])==0))
				ans.push_back(make_pair(i,i/(i-fail[i])));
		}
		printf("Test case #%d\n",++kas);
		for(int i=0;i<ans.size();i++)
			printf("%d %d\n",ans[i].first,ans[i].second);
		puts("");
	}
}
