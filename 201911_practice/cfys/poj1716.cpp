#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
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
const int maxn=1e4+7;
struct Edge{
	int to,w,nxt;
}edge[maxn*3];
int head[maxn];
int tot=0;
inline void addedge(int u,int v,int w)//x_u-x_v<=w (v->u)
{
	edge[tot]={u,w,head[v]};
	head[v]=tot++;
}
bool inq[maxn];
int dis[maxn];
int spfa()
{
	memset(dis,0x3f,sizeof(dis));
	memset(inq,0,sizeof(inq));
	queue<int> q;
	int mx=10001;
	q.push(mx);
	dis[mx]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=head[u];i!=-1;i=edge[i].nxt)
		{
			Edge& e=edge[i];
			int v=e.to;
			if(dis[v]>dis[u]+e.w)
			{
				dis[v]=dis[u]+e.w;
				if(!inq[v])
				{
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
	return -dis[0];
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		tot=0;
		memset(head,-1,sizeof(head));
		for(int i=0,l,r;i<n;i++)
		{
			scanf("%d%d",&l,&r);
			addedge(l,r+1,-2);
		}
		for(int i=0;i<=10000;i++)
		{
			addedge(i+1,i,1);
			addedge(i,i+1,0);
		}
		printf("%d\n",spfa());
	}
}
