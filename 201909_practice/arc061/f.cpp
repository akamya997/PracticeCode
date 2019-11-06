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
const int maxn=1e6+7;
struct Edge{
	int to,w;
};
map<int,set<int> > col[200005];
vector<Edge> G[maxn];
map<PII,int> num;
int curn=0;
inline int getid(int u,int col)
{
	if(!num.count(make_pair(u,col)))
		num[make_pair(u,col)]=curn++;
	return num[make_pair(u,col)];
}
int n,m;
struct Heap{
	int u,dis;
	bool operator<(const Heap& a)const{
		return dis>a.dis;
	}
};
int d[maxn];
bool vis[maxn];
int dij()
{
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	priority_queue<Heap> q;
	q.push({1,0});
	while(!q.empty())
	{
		auto u=q.top();
		q.pop();
		if(vis[u.u]) continue;
		vis[u.u]=1;
		for(auto e:G[u.u])
		{
			int v=e.to;
			if(d[v]>d[u.u]+e.w)
			{
				d[v]=d[u.u]+e.w;
				q.push({v,d[v]});
			}
		}
	}
	return d[n];
}
int main()
{
	scanf("%d%d",&n,&m);
	curn=n+1;
	for(int i=0,u,v,c;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&c);
		col[u][c].insert(v);
		col[v][c].insert(u);
	}
	for(int i=1;i<=n;i++)
	{
		for(auto u:col[i])
		{
			int cc=u.first;
			for(auto v:u.second)
			{
				G[getid(i,cc)].push_back({getid(v,cc),0});
				G[getid(v,cc)].push_back({getid(i,cc),0});
			}
			G[i].push_back(Edge{getid(i,cc),1});
			G[getid(i,cc)].push_back(Edge{i,0});
		}
	}
	int ans=dij();
	if(ans==0x3f3f3f3f) ans=-1;
	printf("%d\n",ans);
}
