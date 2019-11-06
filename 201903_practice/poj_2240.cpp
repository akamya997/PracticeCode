#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
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
struct Edge{
	int to;
	double rate;
};
map<string,int> num;
const int maxn=50;
vector<Edge> G[maxn];
double dis[maxn];
bool inq[maxn];
int cnt[maxn];
bool spfa(int st,int tot)
{
	queue<int> q;
	memset(dis,0,sizeof(dis));
	memset(inq,0,sizeof(inq));
	q.push(st);
	cnt[st]=0;
	dis[st]=1;
	inq[st]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=0;i<G[u].size();i++)
		{
			Edge v=G[u][i];
			if(dis[v.to]<dis[u]*v.rate)
			{
				dis[v.to]=dis[u]*v.rate;
				cnt[v.to]=cnt[u]+1;
				if(cnt[v.to]>tot||dis[v.to]>1.0) return true;
				if(!inq[v.to])
				{
					q.push(v.to);
					inq[v.to]=1;
				}
			}
		}
	}
	return false;
}
int main()
{
	int n,kas=0;
	while(cin>>n&&n)
	{
		memset(cnt,-1,sizeof(cnt));
		for(int i=0;i<=n;i++) G[i].clear();
		num.clear();
		string s;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			num[s]=i;
		}
		int m;
		cin>>m;
		string u,v;
		for(int i=0;i<m;i++)
		{
			cin>>u;
			double rate;
			cin>>rate;
			cin>>v;
			G[num[u]].push_back(Edge{num[v],rate});
		}
		bool ok=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt[i]==-1)
				if(spfa(i,n))
				{
					ok=1;
					break;
				}
		}
		cout<<"Case "<<++kas<<": ";
		if(ok)
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;

	}
}
