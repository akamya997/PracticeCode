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
double dp[105][105][105][2];
int val[105];
double dfs(int u,int fa,int q,int net,bool hung)
{
	if(q<0) return 0;
	double& ret=dp[u][q][net+2][hung];
	if(ret!=-1) return ret;
	ret=hung?val[u]:(val[u]/(double)(net+1));
	ret=max(ret,0.0);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa) continue;
		double ma=0;
		ma=max(ma,max(dfs(v,u,q-1,0,1),dfs(v,u,q,net<0?-2:net+1,0)));
		ret+=ma;
	}
}
int main()
{
	int n;
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for(int i=1,u;i<=n-1;i++)
	{
		scanf("%d",&u);
		G[u].push_back(i+1);
		G[i+1].push_back(u);
	}
	int p,q;
	scanf("%d%d",&p,&q);
	for(int i=0;i<p;i++)
	{
		int id;
		scanf("%d",&id);
		scanf("%d",&val[id]);
	}
	printf("%.6f\n",max(dfs(1,-1,q,0,0),dfs(1,-1,q,-2,1)));

}
