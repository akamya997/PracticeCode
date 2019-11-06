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
struct Edge{
	int to,w;
};
const int INF=0x3f3f3f3f;
const int maxn=55;
vector<Edge> G[maxn];
int d[maxn][1<<10];
bool inq[maxn];
queue<int> q;
int n,m,k;
int id(int x)
{
	if(x<k) return x;
	if(x>=n-k) return x-n+2*k;
	return -1;
}
void spfa(int S)
{
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		inq[u]=false;
		for(auto& e:G[u])
		{
			int v=e.to;
			int state=(id(v)==-1?0:(1<<id(v)));
	//		dbg(u,v,state);
			if(d[v][S|state]>d[u][S]+e.w)
			{
				d[v][S|state]=d[u][S]+e.w;
				if((state|S!=S)||inq[v]) continue;
				inq[v]=1;
				q.push(v);
			}
		}
	}
}
int dp[1<<10];
bool check(int S)
{
	int bk=0,rk=0;
	for(int i=0;i<k;i++)
		if(S&(1<<i)) bk++;
	for(int i=k;i<2*k;i++)
		if(S&(1<<i)) rk++;
	return bk==rk;
}
void solve()
{
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<k;i++) d[i][1<<i]=0;
	for(int i=n-k;i<n;i++) d[i][1<<(i-n+2*k)]=0;
	for(int S=0;S<(1<<(2*k));S++)
	{
		memset(inq,0,sizeof(inq));
		for(int i=0;i<n;i++)
		{
			if(id(i)!=-1&&((1<<id(i))&S)==0) continue;
			for(int T=(S-1)&S;T;T=(T-1)&S)
			{
				int state=id(i)==-1?0:(1<<id(i));
				int u=state|T,v=state|(S-T);
				d[i][S]=min(d[i][S],d[i][u]+d[i][v]);
			}
			if(d[i][S]!=INF)
			{
				q.push(i);
				inq[i]=1;
			}
		}
		spfa(S);
	}
	memset(dp,0x3f,sizeof(dp));
	for(int S=0;S<(1<<(2*k));S++)
	{
		for(int i=0;i<n;i++)
			dp[S]=min(dp[S],d[i][S]);
		//dbg(S,dp[S]);
	}
	for(int S=0;S<(1<<(2*k));S++)
	{
		if(check(S))
		for(int T=(S-1)&S;T;T=(T-1)&S)
		{
			if(check(T))
				dp[S]=min(dp[S],dp[S-T]+dp[T]);
		}
	}
	if(dp[(1<<(2*k))-1]==INF) puts("No solution");
	else printf("%d\n",dp[(1<<(2*k))-1]);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<=n;i++) G[i].clear();
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			u--,v--;
			G[u].push_back(Edge {v,w});
			G[v].push_back(Edge {u,w});
		}
		solve();
	}
}
