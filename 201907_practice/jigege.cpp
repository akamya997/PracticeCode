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
const int mod=1e9+7;
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
const int maxn=2e3+7;
bool vis[maxn][maxn];
int dp[maxn][maxn];
inline void ADD(int &a,int b)
{
	a=a+b;
	if(a>=mod) a-=mod;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,e,k;
	cin>>n>>e>>k;
	int cnt=e;
	e=e*2+1;
	while(k--)
	{
		int u,v;
		cin>>u>>v;
		vis[u][v]=1;
	}
	int tot=(1<<e)-1;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(1<<e);j++)
		{
			if(!dp[i-1][j]) continue;
			int cur=tot&(j<<1);
			for(int tt=0;tt<e;tt++)
			{
				int curpos=i+cnt-tt;
				if(curpos<1||curpos>n||vis[i][curpos]) continue;
				if(!(cur>>tt&1))
				{
					ADD(dp[i][cur|(1<<tt)],dp[i-1][j]);
		//			dbg(i,j,cur,cur|(1<<tt));
				}
			}
		}
	}
	int endst=0;
	//int ans=0;
	for(int i=0;i<=cnt;i++)
		endst|=1<<(i+cnt);
	//for(int i=0;i<(1<<e);i++)
		//ADD(ans,dp[n][i]);
	cout<<dp[n][endst]<<endl;
	
}

