#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>
#include<cstring>
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
const int maxn=5e4+7;
struct Seg{
	int l,r,k;
}seg[maxn];
int n;
struct Edge{
	int to,w,nxt;
}edge[maxn*2];
int head[maxn];
int tot=0;
//vector<Edge> G[maxn];
inline void addedge(int u,int v,int w)//x_u-x_v<=w
{
	edge[tot]={u,w,head[v]};
	head[v]=tot++;
}
bool inq[maxn];
int dis[maxn];
int cnt[maxn];
bool spfa()
{
	memset(inq,0,sizeof(inq));
	memset(dis,0x3f,sizeof(dis));
	dis[maxn-1]=0;
	queue<int> q;
	cnt[maxn-1]=0;
	q.push(maxn-1);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=head[u];i!=-1;i=edge[i].nxt)
		{
			Edge &e=edge[i];
			int v=e.to;
			if(dis[v]>dis[u]+e.w)
			{
				dis[v]=dis[u]+e.w;
				if(!inq[v])
				{
					cnt[v]=cnt[u]+1;
					q.push(v);
					if(cnt[v]>maxn) return false;
					inq[v]=1;
				}
			}
		}
	}
	return true;
}
bool solve()
{
	tot=0;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)
		addedge(seg[i].l-1,seg[i].r,-seg[i].k);
	for(int i=1;i<maxn;i++)
	{
		addedge(i,i-1,1);
		addedge(i-1,i,0);
	}
	return spfa();
}
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&seg[i].l,&seg[i].r,&seg[i].k);
			seg[i].l++;
			seg[i].r++;
		}
		solve();
		printf("%d\n",abs(dis[0]));
	}
}
