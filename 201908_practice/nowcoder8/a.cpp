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
int a[maxn][maxn],b[maxn][maxn];
int sta[maxn],val[maxn];
int L;
bool cmp(int i,int j)
{
	return b[L][i]<b[L][j];
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",maze[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=maze[i][j]-'0';
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		L=i;
		for(int j=1;j<=m;j++)
			b[i][j]=(a[i][j]?b[i-1][j]+1:0);
		int top=0;
		int z=0;
		for(int j=1;j<=m;j++)
		{
			while(top&&b[i][sta[top]]>=b[i][j]) --top;
			sta[++top]=j,val[top]=sta[top-1]+1;
			if(a[i+1][j]==0) z=j;
			int r=upper_bound(val+1,val+1+top,z)-val-1;
			int l=upper_bound(sta+1,sta+1+top,j+1,cmp)-sta;
			if(1<=l&&l<=r&&r<=top) ans+=r-l+1;
			dbg(i,j,l,r);
		}
	}
	printf("%lld\n",ans);
}
