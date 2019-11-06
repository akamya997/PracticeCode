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
const int maxn=5e5+7;
vector<int> G[maxn];
bool vis[maxn];
int col[maxn];
bool ok=1;
void dfs(int u,int c)
{
	if(vis[u]) return;
	vis[u]=1;
	col[u]=c;
	for(auto v:G[u])
	{
		if(col[v]!=-1&&col[u]==col[v]) ok=0;
		dfs(v,c^1);
	}
}
int main()
{
	memset(col,-1,sizeof(col));
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0,u,v;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i,0);
			cnt++;
		}
	}
	if(ok) cout<<cnt<<endl;
	else cout<<cnt-1<<endl;
}
