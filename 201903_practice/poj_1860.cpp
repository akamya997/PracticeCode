#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
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
	double rate,com;
};
const int maxn=105;
vector<Edge> G[maxn];
int cnt[maxn];
bool inq[maxn];
double money[maxn];
bool spfa(int st,int tot,double v)
{
	queue<int> q;
	q.push(st);
	inq[st]=1;
	money[st]=v;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=0;i<G[u].size();i++)
		{
			Edge v=G[u][i];
			if(money[u]<v.com) continue;
			if((money[u]-v.com)*v.rate>money[v.to])
			{
				money[v.to]=(money[u]-v.com)*v.rate;
				cnt[v.to]=cnt[u]+1;
				if(cnt[u]>tot) return true;
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
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,s;
	double v;
	cin>>n>>m>>s>>v;
	double r,c;
	for(int i=0,u,v;i<m;i++)
	{
		cin>>u>>v;
		cin>>r>>c;
		G[u].push_back(Edge{v,r,c});
		cin>>r>>c;
		G[v].push_back(Edge{u,r,c});
	}
	if(spfa(s,n,v))
		cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
