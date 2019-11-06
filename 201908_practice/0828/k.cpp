#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
int val[40];
int n,m,p;
int G[40][40];
vector<int> vec[40];
void solve()
{
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		G[u][v]=G[v][u]=1;
	}
	int var=n/2;
	for(int i=1;i<=var;i++)
	{
		for(int j=var+1;j<=n;j++)
		{
			if(G[i][j])
			{
				
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&p);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&val[i]);
			vec[i].clear();
		}
		solve();
	}
}
