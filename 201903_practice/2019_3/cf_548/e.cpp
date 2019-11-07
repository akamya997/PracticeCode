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
const int maxn=5005;
int ext[maxn][maxn];
int cnt[maxn];
bool vis[maxn];
int fi[maxn];
int pot[maxn];
int club[maxn];
int ans[maxn];
vector<int> query;
void add(int x)
{
	for(int i=0)
}
int main()
{
	memset(fi,-1,sizeof(fi));
	int m,n;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&pot[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&club[i]);
	int d;
	scanf("%d",&d);
	for(int i=1,temp;i<=d;i++)
	{
		scanf("%d",&temp);
		vis[temp]=1;
		query.push_back(temp);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		add(i);
	}
	for(int i=d;i>=1;i--)
	{
		int cur=0;
		int person=query[i-1];
		for(int j=0;j<maxn;j++)
		{
			if(cnt[j]) cur++;
			else break;
		}
		ans[i]=cur;
		add(person);
	}
	for(int i=1;i<=d;i++)
		printf("%d\n",ans[i]);

}
