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
const int maxn=1e5+7;
ll dp[maxn][2];
ll l[maxn],r[maxn];
vector<int> G[maxn];
void dfs(int u,int fa=-1)
{
	for(auto v:G[u])if(v!=fa)
	{
		dfs(v,u);
		dp[u][0]=max({dp[v][0]+abs(l[u]-l[v]),dp[v][1]+abs(l[u]-r[v])})+dp[u][0];
		dp[u][1]=max({dp[v][0]+abs(r[u]-l[v]),dp[v][1]+abs(r[u]-r[v])})+dp[u][1];
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=0;i<=n;i++)
		{
			dp[i][0]=dp[i][1]=0;
			G[i].clear();
		}
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
		dfs(1);
		cout<<max(dp[1][0],dp[1][1])<<'\n';
	}
}
