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
const int maxn=1e5+7;
vector<int> G[maxn];
double f[maxn],g[maxn];
int n,m;
void dfs1(int u)
{
	f[u]=0,g[u]=0;
	if(u==n) return;
	int cnt=G[u].size()+1;
	f[u]=1+1.0/(cnt-1);
	for(auto v:G[u])
	{
		dfs1(v);
		f[u]+=1.0/(cnt-1)*f[v];
	}
}
void dfs2(int u)
{
	if(u==n) return;
	int cnt=G[u].size()+1;
	g[u]=1.0*f[u]/(cnt-1)+1.0*cnt/(cnt-1);
	for(auto v:G[u])
	{
		dfs2(v);
		g[u]+=1.0*(g[v]+f[v])/(cnt-1);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1,u,v;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
		}
		dfs1(1);
		dfs2(1);
		printf("%.2f\n",g[1]);
	}
}
