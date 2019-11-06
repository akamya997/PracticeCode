#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=205;
const ll INF=0x3f3f3f3f3f3f3f3f;
int st[maxn];
int fac[maxn];
struct Edge{
	int to,w;
};
vector<Edge> G[maxn];
ll d[maxn][1<<8];
ll dp[1<<8];
bool inq[maxn];
queue<int> q;
bool check(int S)
{
	int l=0,r=0;
	for(int i=0;i<4;i++)
		if(S&(1<<i)) l+=fac[i];
	for(int i=4;i<8;i++)
		if(S&(1<<i)) r++;
	return r<=l;
}
void spfa(int S)
{
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(auto& e:G[u])
		{
			int v=e.to;
			if(d[v][S|st[v]]>d[u][S]+e.w)
			{
				d[v][S|st[v]]=d[u][S]+e.w;
				if(inq[v]||st[v]|S!=S)
					continue;
				inq[v]=1;
				q.push(v);
			}
		}
	}
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(d,0x3f,sizeof(d));
		memset(dp,0x3f,sizeof(dp));
		memset(st,0,sizeof(st));
		memset(fac,0,sizeof(fac));
		int p=0,s=4;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
			int u,v;
			scanf("%d%d",&u,&v);
			if(u)
			{
				fac[p]=u;
				st[i]|=1<<p;
				p++;
			}
			if(v)
			{
				st[i]|=1<<s;
				s++;
			}
			if(st[i])
				d[i][st[i]]=0;
		}
		int m;
		scanf("%d",&m);
		while(m--)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			G[u].push_back(Edge {v,w});
			G[v].push_back(Edge {u,w});
		}
		for(int S=0;S<(1<<8);S++)
		{
			memset(inq,0,sizeof(inq));
			for(int i=1;i<=n;i++)
			{
				if(st[i]&&(st[i]&S)==0) continue;
				for(int T=(S-1)&S;T;T=(T-1)&S)
				{
					d[i][S]=min(d[i][S],d[i][T|st[i]]+d[i][(S-T)|st[i]]);
				}
				if(d[i][S]!=INF)
				{
					inq[i]=1;
					q.push(i);
				}
			}
			spfa(S);
		}
		for(int S=0;S<(1<<8);S++)
		{
			for(int i=1;i<=n;i++)
				dp[S]=min(dp[S],d[i][S]);
	//		dbg(S,dp[S]);
		}
		ll ans1=0,ans2=0;
		for(int S=0;S<(1<<8);S++)
		{
			if(!check(S)) continue;
			for(int T=(S-1)&S;T;T=(T-1)&S)
			{
				if(check(T)&&check(S-T))
					dp[S]=min(dp[S],dp[S-T]+dp[T]);
			}
			if(dp[S]==INF) continue;
			int cnt1=0;
			for(int i=4;i<8;i++)
				if(S&(1<<i)) cnt1++;
	//		dbg(S,cnt1,dp[S]);
			if(cnt1>ans1)
			{
				ans1=cnt1;
				ans2=dp[S];
			}
			else if(cnt1==ans1)
				ans2=min(ans2,dp[S]);
		}
		printf("%lld %lld\n",ans+ans1,ans2);

	}
}
