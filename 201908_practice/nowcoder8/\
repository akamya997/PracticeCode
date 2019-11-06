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
const int maxn=3005;
char maze[maxn][maxn];
bool vis[maxn][maxn];
int ans=0;
void dfs(int r,int c,int w,int h)
{
	bool ok1=1,ok2=1;
	for(int i=r;i<=r+h-1;i++)
		if(maze[i][c+w]!='1')
		{
			ok1=0;break;
		}
	for(int i=c;i<=c+w-1;i++)
		if(maze[r+h][i]!='1')
		{
			ok2=0;break;
		}
	if(ok2&&ok1)
	{
		if(maze[r+h][c+w]=='1')
		{
			vis[r+h][c+w]=1;
			dfs(r,c,w+1,h+1);
		}
		else{
			dfs(r,c,w+1,h);
			dfs(r,c,w,h+1);
		}
	}
	else if(ok1)
		dfs(r,c,w+1,h);
	else if(ok2)
		dfs(r,c,w,h+1);
	else ans++;
	//dbg(r,c,w,h,ok1,ok2,ans);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",maze[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(maze[i][j]=='1')
				dfs(i,j,1,1);
		}
	}
	printf("%d\n",ans);
}
