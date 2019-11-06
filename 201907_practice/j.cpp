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
const int maxn=505;
vector<int> G[maxn];
int pp[maxn];
bool vis[maxn];
bool dfs(int u)
{
	for(auto v:G[u])
	{
		if(vis[v]) continue;
		vis[v]=1;
		if(!pp[v]||dfs(pp[v]))
		{
			pp[v]=u;
			pp[u]=v;
			return true;
		}
	}
	return false;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,k;
		memset(pp,0,sizeof(pp));
		cin>>n>>k;
		for(int i=0;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++)
		{
			int tmp;
			cin>>tmp;
			G[i+1].push_back(tmp);
			G[tmp].push_back(i+1);
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(!pp[i])
			{
				memset(vis,0,sizeof(vis));
				if(dfs(i))
					cnt++;
			}
		}
		if(n%2==0&&k>=(n-1-n/2)&&cnt==n/2)
			puts("Bob");
		else puts("Alice");
	}
}
