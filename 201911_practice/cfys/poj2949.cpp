#include<iostream>
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
const double eps=1e-4;
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
char s[maxn];
struct Edge{
	int to;double w;int nxt;
}edge[maxn];
const int maxv=1e3+7;
int head[maxv],tot;
inline void addedge(int u,int v,double w)
{
	edge[tot]={v,w,head[u]};
	head[u]=tot++;
}
int n;
double dis[maxv];
bool inq[maxv];
int cnt[maxv];
bool check(double x)
{
	for(int i=0;i<tot;i++) edge[i].w-=x;
	for(int i=0;i<maxv;i++) dis[i]=0;
	memset(inq,0,sizeof(inq));
	memset(cnt,0,sizeof(cnt));
	bool ret=0;
	queue<int> q;
	for(int i=0;i<maxv;i++) q.push(i),inq[i]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=head[u];i!=-1;i=edge[i].nxt)
		{
			Edge& e=edge[i];
			int v=e.to;
			if(dis[v]<dis[u]+e.w) 
			{
				dis[v]=dis[u]+e.w;
				if(!inq[v])
				{
					inq[v]=1;
					q.push(v);
					cnt[v]=cnt[u]+1;
					if(cnt[v]>maxv)
					{
						ret=1;
						break;
					}
				}
			}
		}
		if(ret) break;
	}
	for(int i=0;i<tot;i++) edge[i].w+=x;
	return ret;
}
int main()
{
	while(~scanf("%d",&n)&&n)
	{
		memset(head,-1,sizeof(head));
		tot=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			int len=strlen(s);
			int u=(s[0]-'a')*26+(s[1]-'a');
			int v=(s[len-2]-'a')*26+(s[len-1]-'a');
			addedge(u,v,len);
		}
		double L=0,R=100000000,ans=-1;
		while(R-L>eps)
		{
			double mid=(L+R)/2;
			if(check(mid))
				ans=mid,L=mid;
			else R=mid;
		}
		if(ans<0) puts("No solution.");
		else printf("%.2f\n",ans);
	}
}
