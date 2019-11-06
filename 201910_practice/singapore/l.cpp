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
const int maxn=2e6+7;
int pc[maxn];
int dp[maxn];
int prime[maxn];
int tot;
bool vis[maxn];
int tt[maxn];
void db()
{
	for(int i=2;i<maxn;i++)
	{
		if(!vis[i])
		{
			tt[i]=1;
			dp[i]=2;
			prime[tot++]=i;
			pc[i]=1;
		}
		for(int j=0;j<tot;j++)
		{
			if(prime[j]*i>=maxn) break;
			if(i%prime[j]==0)
			{
				dp[i*prime[j]]=dp[i]/(tt[i]+1)*(tt[i]+2);
				vis[i*prime[j]]=1;
				tt[i*prime[j]]=tt[i]+1;
				pc[i*prime[j]]=pc[i];
				break;
			}
			pc[i*prime[j]]=pc[i]+1;
			vis[i*prime[j]]=1;
			tt[i*prime[j]]=1;
			dp[i*prime[j]]=dp[i]*2;
		}
	//	if(i<20) dbg(i,pc[i],dp[i]);
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	db();
	int q;
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		cout<<dp[x]-pc[x]<<'\n';
	}
}
