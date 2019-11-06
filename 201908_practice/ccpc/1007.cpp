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
char ans[1<<10][1<<10];
int main()
{
	ans[0][0]='C';
	ans[0][1]='C';
	ans[1][0]='P';
	ans[1][1]='C';
	for(int i=2;i<=10;i++)
	{
		int x=(1<<(i-1)),y=x;
		for(int ii=0;ii<x*2;ii++)
			for(int jj=y;jj<y*2;jj++)
			{
				ans[ii][jj]=ans[ii%x][jj-y];
			}
		for(int ii=x;ii<x*2;ii++)
			for(int jj=0;jj<y;jj++)
			{
				if(ans[ii-x][jj]=='C')
					ans[ii][jj]='P';
				else ans[ii][jj]='C';
			}
				
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int k;
		scanf("%d",&k);
		for(int i=0;i<(1<<k);i++)
		{
			for(int j=0;j<(1<<k);j++)
			{
				printf("%c",ans[i][j]);
			}
			puts("");
		}
	}
}
