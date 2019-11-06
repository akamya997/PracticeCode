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
set<int> G[maxn];
inline void add(int u,int v)
{
	if(G[u].count(v)) return;
	G[u].insert(v);
	G[v].insert(u);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(G[i].size()==2)
			q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(G[u].size()!=2) continue;
		int v1=*G[u].begin(),v2=*G[u].rbegin();
		add(v1,v2);
		for(auto v:G[u])
		{
			G[v].erase(u);
			if(G[v].size()==2)
			{
				q.push(v);
			}
		}
		G[u].clear();
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(G[i].size()==1) cnt++;
	if(cnt==2) puts("Yes");
	else puts("No");
}
