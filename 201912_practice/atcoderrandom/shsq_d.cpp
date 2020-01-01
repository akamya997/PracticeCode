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
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int INF=0x3f3f3f3f;
struct Edge{
	int to;ll w;
};
const int maxn=1e5+7;
vc<Edge> G[2][maxn];
ll dis[2][maxn];
ll a[maxn],b[maxn];
ll ans[maxn];
struct D{
	int u;
	ll d;
	bool operator<(const D& a)const{
		return d>a.d;
	}
};
bool vis[maxn];
void dij(int x,int st)
{
	memset(dis[x],0x3f,sizeof(dis[x]));
	memset(vis,0,sizeof(vis));
	dis[x][st]=0;
	priority_queue<D> q;
	q.push({st,0});
	while(!q.empty())
	{
		auto u=q.top();
		q.pop();
		if(vis[u.u]) continue;
		vis[u.u]=1;
		for(auto e:G[x][u.u])
		{
			int v=e.to;
			if(dis[x][v]>u.d+e.w)
			{
				dis[x][v]=u.d+e.w;
				q.push({v,dis[x][v]});
			}
		}
	}
}
int main()
{
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	for(int i=0,u,v;i<m;i++)
	{
		cin>>u>>v>>a[i]>>b[i];
		G[0][u].push_back({v,a[i]});
		G[0][v].push_back({u,a[i]});
		G[1][u].push_back({v,b[i]});
		G[1][v].push_back({u,b[i]});
	}
	dij(0,s);
	dij(1,t);
	ll cur=0x3f3f3f3f3f3f3f3f;
	for(int i=n-1;i>=0;i--)
	{
	//	dbg(i,dis[0][i],dis[1][i]);
		cur=min(cur,dis[0][i+1]+dis[1][i+1]);
		ans[i]=cur;
	}
	ll mx=1e15;
	for(int i=0;i<n;i++)
		cout<<mx-ans[i]<<"\n";
}
