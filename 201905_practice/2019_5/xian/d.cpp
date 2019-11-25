#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn=205;
const int maxv=5e2+7;
int val[maxn];
typedef pair<int,int> PII;
vector<int> G[maxn];
int col[maxn];
PII dfs(int u,int c=0)
{
	PII ret={0,0};
	col[u]=c;
	if(col[u]==0) ret.first+=val[u];
	else ret.second+=val[u];
	for(auto& v:G[u])
	{
		if(col[v]==-1)
		{
			PII nxt=dfs(v,c^1);
			ret.first+=nxt.first;
			ret.second+=nxt.second;
		}
	}
	return ret;
}
int dp[maxn][maxv*maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		int tot=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
			scanf("%d",&val[i]);
			val[i]/=100;
			tot+=val[i];
		}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=tot;j++)
				dp[i][j]=0;
		for(int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		memset(col,-1,sizeof(col));
		vector<PII> all;
		for(int i=1;i<=n;i++)
			if(col[i]==-1) all.push_back(dfs(i));
		dp[0][0]=1;
		for(int i=1;i<=all.size();i++)
		{
			int cur=i-1;
			if(all[cur].first>all[cur].second) swap(all[cur].first,all[cur].second);
			for(int j=tot;j>=all[cur].second;j--)
				dp[i][j]=(dp[i-1][j-all[cur].first]|dp[i-1][j-all[cur].second]);
			for(int j=all[cur].second-1;j>=all[cur].first;j--)
				dp[i][j]=dp[i-1][j-all[cur].first];
		}
		int ans=0;
		for(int i=(tot+1)/2;i<=tot;i++)
		{
			if(dp[all.size()][i])
			{
				ans=i;break;
			}
		}
		printf("%d\n",ans*100);
		
	}
}
