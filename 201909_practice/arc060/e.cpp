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
int x[maxn];
int n;
int l,q;
int r[maxn][20];
int getnxt(int cur)
{
	int L=cur,R=n,ret=-1;
	while(L<=R)
	{
		int mid=L+R>>1;
		if(x[mid]-x[cur]<=l)
			L=mid+1,ret=mid;
		else R=mid-1;
	}
	assert(ret!=-1);
	return ret;
}
void db()
{
	for(int i=1;i<=n;i++)
		r[i][0]=getnxt(i);
	for(int j=1;j<20;j++)
	{
		for(int i=1;i<=n;i++)
			r[i][j]=r[r[i][j-1]][j-1];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	scanf("%d%d",&l,&q);
	db();
	while(q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		int L=1,R=n,ans=-1;
		while(L<=R)
		{
			int mid=L+R>>1;
			int st=mid;
			int tmp=0;
			int fin=a;
			while(st)
			{
				if(st&1)
					fin=r[fin][tmp];
				tmp++;
				st>>=1;
			}
			if(fin>=b)
				R=mid-1,ans=mid;
			else L=mid+1;
		}
		printf("%d\n",ans);
	}
}
