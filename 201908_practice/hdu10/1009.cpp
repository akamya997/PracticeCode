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
const int maxn=2e3+7;
int maze[maxn][maxn];
int n,m,q;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
bool ok(int x,int y)
{
	if(x==0||y==0||x==n+1||y==m+1) return false;
	if((maze[x+1][y]==0||maze[x-1][y]==0)&&(maze[x][y+1]==0||maze[x][y-1]==0))
		return true;
	return false;
}
int del(int x,int y)
{
	if(x<=0||x>n||y<=0||y>m||maze[x][y]==0) return 0;
	int ret=1;
	maze[x][y]=0;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(ok(nx,ny)) ret+=del(nx,ny);
	}
	return ret;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=m+1;j++)
				maze[i][j]=1;
		while(q--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",del(x,y));
		}
	}
}
