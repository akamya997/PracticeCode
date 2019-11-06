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
int dp[1<<24];
char maze[15][15];
int val[15][15];
int T;
int n;
inline bool cantake(int S,int i)
{
	return !(S>>i&1)&&(S>>(i-1)&1);
}
pair<int,PII> tmp[15];
int sz;
void getok(int S)
{
	int x=0,y=0;
	sz=0;
	for(int i=2*n-1;i>0;i--)
	{
		if(cantake(S,i))
			tmp[sz++]=(make_pair(i,make_pair(x,y)));
		if(S>>i&1) y++;
		else x++;
	}
}
int solve(int S)
{
	if(dp[S]!=-1) return dp[S];
	if(S==T) return 0;
	pair<int,PII> cango[15];
	getok(S);
	int csz=sz;
	for(int i=0;i<sz;i++)
		cango[i]=tmp[i];
	int ret=INF;
	for(int i=0;i<csz;i++)
	{
		auto u=cango[i];
		int nxt=S+(1<<u.first)-(1<<(u.first-1));
		ret=min(ret,solve(nxt)+val[u.second.first][u.second.second]);
		for(int j=i+1;j<csz;j++)
		{
			auto v=cango[j];
			if(maze[u.second.first][u.second.second]=='.'||maze[v.second.first][v.second.second]=='.'||maze[u.second.first][u.second.second]==maze[v.second.first][v.second.second]) continue;
			nxt=S+(1<<u.first)-(1<<(u.first-1))+(1<<v.first)-(1<<(v.first-1));
			ret=min(ret,solve(nxt)+abs(val[u.second.first][u.second.second]-val[v.second.first][v.second.second]));
		}
	}
	return dp[S]=ret;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%s",maze[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&val[i][j]);
	int S=(1<<n)-1;
	T=((1<<n)-1)<<n;
	printf("%d\n",solve(S));
}
