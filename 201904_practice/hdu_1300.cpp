#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
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
struct P{
	int need,cost;
}p[105];
const int maxn=1e5+7;
int dp[2][maxn];
int deq[maxn];
int pre[105];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		memset(dp,0x3f,sizeof(dp));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].need>>p[i].cost;
			pre[i]=pre[i-1]+p[i].need;
		}
		int cur=0;
		dp[0][0]=dp[1][0]=0;
		for(int i=1;i<=n;i++)
		{
			int head=0,tail=0;
			deq[++tail]=0;
			for(int j=1;j<=pre[i];j++)
			{
				while(head+1<tail&&dp[cur][deq[head+2]]-dp[cur][deq[head+1]]<=p[i].cost*(deq[head+2]-deq[head+1])) head++;
				dp[cur^1][j]=min(dp[cur][deq[head+1]]+(j-deq[head+1]+10)*p[i].cost,dp[cur][j]);
				if(dp[cur][j]!=INF)
				{
					while(head+1<tail&&(dp[cur][j]-dp[cur][deq[tail]])*(deq[tail]-deq[tail-1])<=(j-deq[tail])*(dp[cur][deq[tail]]-dp[cur][deq[tail-1]])) tail--;
					deq[++tail]=j;
				}
			}
			cur^=1;
		}
		cout<<dp[cur][pre[n]]<<endl;
	}
}
