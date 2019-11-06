#include<iostream>
#include<cstdio>
using namespace std;
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
const int maxn=105;
int G[maxn][maxn];
int rel[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0,u,v;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		u--,v--;
		G[u][v]=1;
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				G[i][j]|=(G[i][k]&G[k][j]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(G[i][j])
			{
				rel[i]++;
				rel[j]++;
			}
		}
	}
	for(int i=0;i<n;i++) if(rel[i]==n-1) ans++;
	printf("%d\n",ans);
}
