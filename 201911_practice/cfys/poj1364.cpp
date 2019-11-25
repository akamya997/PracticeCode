#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
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
int n,m;
const int maxn=105;
struct cons{
	int l,r,tp,k;
}con[maxn];
struct Edge{
	int to,w,nxt;
}edge[maxn*10];
int head[maxn];
int tot=0;
inline void addedge(int u,int v,int w)//x_u-x_v<=w
{
	edge[tot]={u,w,head[v]};
	head[v]=tot++;
}
int cnt[maxn];
bool inq[maxn];
int dis[maxn];
bool spfa()
{
	tot=0;
	memset(head,-1,sizeof(head));
	memset(dis,0x3f,sizeof(dis));
	memset(inq,0,sizeof(inq));
	for(int i=0;i<m;i++)
	{
		if(!con[i].tp)
			addedge(con[i].r+con[i].l,con[i].l-1,con[i].k-1);
		else{
			addedge(con[i].l-1,con[i].l+con[i].r,-con[i].k-1);
		}
	}
	for(int i=0;i<=n;i++) addedge(i,n+1,0);
	queue<int> q;
	q.push(n+1);
	cnt[n+1]=0;
	dis[n+1]=0;
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
					q.push(v);
					inq[v]=1;
					cnt[v]=cnt[u]+1;
					if(cnt[v]>n+1) return false;
				}
			}
		}
	}
	return true;

}
int main()
{
	while(~scanf("%d",&n)&&n)
	{
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			char op[5];
			scanf("%d%d%s%d",&con[i].l,&con[i].r,op,&con[i].k);
			if(op[0]=='g') con[i].tp=1;
			else con[i].tp=0;
		}
		if(spfa())
			puts("lamentable kingdom");
		else puts("successful conspiracy");

	}
}
