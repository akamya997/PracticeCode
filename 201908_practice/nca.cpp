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
const int maxn=35;
struct Edge{
	int to,w;
};
vector<Edge> G[maxn];
map<string,int> id;
int n,m;
PII tar[4];
int st[35];
int dp[35][1<<8];
int dis[1<<8];
bool inq[35];
queue<int> q;
int cur=0;
bool check(int S)
{
	bool ok=1;
	for(int i=0;i<4;i++)
	{
		if(S&st[tar[i].first])
			ok&=((S&st[tar[i].second])!=0);
	}
	return ok;
}
void spfa(int S)
{
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(auto e:G[u])
		{
			int v=e.to;
			if(dp[v][S|st[v]]>dp[u][S]+e.w)
			{
				dp[v][S|st[v]]=dp[u][S]+e.w;
				if(inq[v]||(st[v]|S)!=S) continue;
				inq[v]=1;
				q.push(v);
			}
		}
	}
}
void solve()
{
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		if(st[i])
			dp[i][st[i]]=0;
	}
	for(int S=0;S<(1<<cur);S++)
	{
		memset(inq,0,sizeof(inq));
		for(int i=0;i<n;i++)
		{
			if(st[i]&&(st[i]&S)==0) continue;
			for(int T=(S-1)&S;T;T=(T-1)&S)
				dp[i][S]=min(dp[i][S],dp[i][T|st[i]]+dp[i][(S-T)|st[i]]);
			if(dp[i][S]!=INF)
			{
				inq[i]=1;
				q.push(i);
			}
		}
		spfa(S);
	}
	memset(dis,0x3f,sizeof(dis));
	for(int S=0;S<(1<<cur);S++)
	{
		for(int i=0;i<n;i++)
			dis[S]=min(dis[S],dp[i][S]);
	}
	for(int S=0;S<(1<<cur);S++)
	{
		if(!check(S)) continue;
		for(int T=(S-1)&S;T;T=(T-1)&S)
		{
			if(!check(T)||!check(S-T)) continue;
			dis[S]=min(dis[S],dis[T]+dis[S-T]);
		}
	}
	cout<<dis[(1<<cur)-1]<<endl;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		string tmp;
		cin>>tmp;
		id[tmp]=i;
	}
	for(int i=0,w;i<m;i++)
	{
		string s,t;
		cin>>s>>t>>w;
		int u=id[s],v=id[t];
		G[u].push_back(Edge {v,w});
		G[v].push_back(Edge {u,w});
	}
	for(int i=0;i<4;i++)
	{
		string s,t;
		cin>>s>>t;
		tar[i].first=id[s];
		tar[i].second=id[t];
		if(!st[tar[i].first])
		{
			st[tar[i].first]=1<<cur;
			cur++;
		}
		if(!st[tar[i].second])
		{
			st[tar[i].second]=1<<cur;
			cur++;
		}
	}
	solve();
}
