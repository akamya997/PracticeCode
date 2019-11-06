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
const int maxn=1e4+7;
int arr[maxn];
ll pre[maxn],p[maxn];
int dq[maxn];
ll dp[55][maxn];
inline ll getup(int i,int k,int j)
{
	return dp[i][j]+p[j]-dp[i][k]-p[k];
}
inline ll getdown(int k,int j)
{
	return pre[j]-pre[k];
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k,m;
		vector<ll> tot;
		ll ans=0;
		scanf("%d%d%d",&n,&k,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
			pre[i]=pre[i-1]+arr[i];
			p[i]=p[i-1]+1LL*arr[i]*i;
			tot.push_back(1LL*arr[i]*(n-i+1));
		}
		sort(tot.begin(),tot.end(),greater<ll>());
		for(int i=0;i<m;i++) ans+=tot[i];
		memset(dp,0x3f,sizeof(dp));
		dp[0][0]=0;
		for(int i=1;i<=k+1;i++)
		{
			int head=0,tail=0;
			dq[tail++]=0;
			for(int j=1;j<=n;j++)
			{
				while(tail-head>=2&&getup(i-1,dq[head],dq[head+1])<=(j+1)*getdown(dq[head],dq[head+1])) head++;
				int id=dq[head];
				dp[i][j]=dp[i-1][id]+(j+1)*(pre[j]-pre[id])-(p[j]-p[id]);
				while(tail-head>=2&&getup(i-1,dq[tail-1],j)*getdown(dq[tail-2],dq[tail-1])<=getdown(dq[tail-1],j)*getup(i-1,dq[tail-2],dq[tail-1]))
					tail--;
				dq[tail++]=j;
			}
		}
		ans-=dp[k+1][n];
		printf("%lld\n",ans);
	}
}
