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
const int maxn=17;
int b[maxn];
int n,t;
int vis[4000];
void bfs()
{
	queue<int> q;
	q.push(0);
	memset(vis,-1,sizeof(vis));
	vis[0]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			int nxt=max(0,u+b[i]);
			if(nxt>3600) nxt=3600;
			if(vis[nxt]==-1)
			{
				q.push(nxt);
				vis[nxt]=vis[u]+1;
			}
		}
	}
	for(int i=t;;i++)
	{
		if(vis[i]!=-1)
		{
			printf("%d %d\n",vis[i],i-t);
			return;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	bfs();
}
