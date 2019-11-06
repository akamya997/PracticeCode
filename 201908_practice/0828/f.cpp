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
const int maxn=205;
int G[maxn][maxn];
int r[maxn];
int id[maxn];
int dis[maxn][maxn];
int ans[20005];
bool cmp(int i,int j)
{
	return r[i]<r[j];
}
struct Query{
	int u,v,id,val;
	bool operator<(const Query& a)const{
		return val<a.val;
	}
}Q[20005];
int main()
{
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&r[i]);
			id[i]=i;
		}
		sort(id+1,id+1+n,cmp);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&G[i][j]);
				dis[i][j]=G[i][j];
			}
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d%d",&Q[i].u,&Q[i].v,&Q[i].val);
			ans[i]=dis[Q[i].u][Q[i].v];
			Q[i].id=i;
		}
		sort(Q+1,Q+q+1);
		int pos=1;
		for(int k=1;k<=n;k++)
		{
			int cur=id[k];
			while(pos<=q&&Q[pos].val<r[cur])
			{
				ans[Q[pos].id]=dis[Q[pos].u][Q[pos].v];
				pos++;
			}
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dis[i][j]=min(dis[i][j],dis[i][cur]+dis[cur][j]);
		}
		while(pos<=q)
		{
			ans[Q[pos].id]=dis[Q[pos].u][Q[pos].v];
			pos++;
		}
		printf("Case #%d:\n",++kas);
		for(int i=1;i<=q;i++)
			printf("%d\n",ans[i]);
	}
}
