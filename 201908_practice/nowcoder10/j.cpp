#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
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
ll dp[2005][5005];
struct Board{
	int h,w;
	bool operator<(const Board &a)const{
		if(h==a.h)
			return w<a.w;
		return h<a.h;
	}
}board[5005];
int deq[5005];
ll pre[5005];
ll prew[5005];
inline ll getup(int i,int u)
{
	return dp[i][u]-pre[u]+board[u+1].h*prew[u];
}
inline ll getdown(int u,int v)//u>v
{
	return board[u+1].h-board[v+1].h;
}
inline ll UP(int i,int u,int v)
{
	return getup(i,u)-getup(i,v);
}
int main()
{
	int n,k;
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&board[i].w,&board[i].h);
	sort(board+1,board+1+n);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+1LL*board[i].h*board[i].w;
		prew[i]=prew[i-1]+board[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		int head=0,tail=0;
		deq[tail++]=0;
		for(int j=1;j<=n;j++)
		{
			while(tail-head>=2&&UP(i-1,deq[head+1],deq[head])<=prew[j]*getdown(deq[head+1],deq[head])) head++;
			int id=deq[head];
			dp[i][j]=dp[i-1][id]+(pre[j]-pre[id])-board[id+1].h*(prew[j]-prew[id]);
	//		dbg(i,j,id,dp[i][j]);
			if(j==n) break;
			while(tail-head>=2&&UP(i-1,j,deq[tail-1])*getdown(deq[tail-1],deq[tail-2])<=UP(i-1,deq[tail-1],deq[tail-2])*getdown(j,deq[tail-1])) tail--;
			deq[tail++]=j;
		}
	}
	printf("%lld\n",(long long)dp[k][n]);
}
