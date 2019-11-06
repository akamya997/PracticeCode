#include<bits/stdc++.h>
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
map<string,int> num;
int m;
struct Edge{
	int u,v,w;
	bool operator<(const Edge& a)const{
		return w<a.w;
	}
}edge[105];
int far[105];
void init()
{
	for(int i=0;i<105;i++) far[i]=i;
}
int Find(int x)
{
	return x==far[x]?x:far[x]=Find(far[x]);
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	far[y]=x;
}
int kruskal()
{
	sort(edge,edge+m);
	int ret=0;
	for(int i=0;i<m;i++)
	{
		if(Find(edge[i].u)==Find(edge[i].v)) continue;
		else{
			Union(edge[i].u,edge[i].v);
			ret+=edge[i].w;
		}
	}
	return ret;
}
int main()
{
	int n;
	while(cin>>n&&n)
	{
		init();
		num.clear();
		int cnt=0;
		m=0;
		string s;
		int w;
		for(int i=0;i<n-1;i++)
		{
			int q;
			cin>>s>>q;
			if(!num.count(s)) num[s]=++cnt;
			string v;
			while(q--)
			{
				cin>>v>>w;
				if(!num.count(v)) num[v]=++cnt;
				edge[m++].u=num[s];
				edge[m-1].v=num[v];
				edge[m-1].w=w;
			}
		}
		cout<<kruskal()<<endl;
	}
}
