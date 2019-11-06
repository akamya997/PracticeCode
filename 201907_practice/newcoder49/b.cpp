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
const int INF=0x3f3f3f3f;
const int maxn=1<<15;
int dp[maxn];
int pre[20];
int val[20];
int n,m;
int tot,ans;
void dfs(int S,vector<int> all)
{
	sort(all.begin(),all.end());
	int cur=-1;
	int res=tot;
	for(auto& u:all)
	{
		cur+=u;
		res-=val[cur];
	}
	ans=min(ans,res);
	for(int nxt=0;nxt<(1<<n);nxt++)
	{
		if((nxt|S)!=nxt) continue;
		if(!dp[nxt^S]) continue;
		vector<int> cur=all;
		cur.push_back(__builtin_popcount(nxt^S));
		dfs(nxt,cur);
	}
}
int main()
{
	ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {scanf("%d",&val[i]);ans+=val[i];}
	sort(val,val+n);
	reverse(val,val+n);
	tot=ans;
	for(int i=0;i<m;i++)
	{
		int st=0;
		int k;
		scanf("%d",&k);
		for(int i=0,tmp;i<k;i++)
		{
			scanf("%d",&tmp);
			tmp--;
			st|=(1<<tmp);
		}
		dp[st]=1;
	}
	vector<int> e;
	dfs(0,e);
	printf("%d\n",ans);

}
