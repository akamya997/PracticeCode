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
const ll INF=0x3f3f3f3f3f3f3f3f;
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
const int maxn=1e3+7;
ll tree[maxn][maxn];
void add(int i,int x,ll val)
{
	while(x>0)
	{
		tree[i][x]=min(tree[i][x],val);
		x-=x&-x;
	}
}
ll query(int i,int x)
{
	ll ret=INF;
	while(x<maxn)
	{
		ret=min(tree[i][x],ret);
		x+=x&-x;
	}
	return ret;
}
ll d[maxn];
ll cost[maxn][maxn];
ll pre[maxn][maxn];
int main()
{
	int T;
	int kas=0;
	scanf("%d",&T);
	while(T--)
	{
		memset(tree,0x3f,sizeof(tree));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%lld",&cost[i][j]);
		for(int i=1;i<=m;i++) 
		{
			scanf("%lld",&d[i]);
			d[i]+=d[i-1];
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				pre[i][j]=pre[i][j-1]+cost[i][j];
				add(i,j,pre[i][j]);
			}
		ll ans=0;
		ll cc=0;
		for(int j=1;j<=n;j++)
			cc-=min(0LL,query(j,1));
		for(int j=1;j<=n;j++)
			ans=max(ans,cc+min(query(j,1),0LL));
		for(int i=1;i<=m;i++)
		{
			ll cur=d[i];
			for(int j=1;j<=n;j++)
				cur-=query(j,i);
			for(int j=1;j<=n;j++)
				ans=max(ans,cur-pre[j][i]+query(j,i));
		}
		printf("Case #%d: %lld\n",++kas,ans);
	}
}
