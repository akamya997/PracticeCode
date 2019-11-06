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
const int maxn=105;
int arr[maxn],brr[maxn];
int dp[maxn][maxn][maxn];
bool exta[maxn],extb[maxn];
inline void ADD(int &a,int b)
{
	a+=b;
	if(a>=mod) a-=mod;
}
inline int mul(int a,int b)
{
	return 1LL*a*b%mod;
}
int n;
int solve(int rt,int l,int r)
{
	if(dp[rt][l][r]!=-1) return dp[rt][l][r];
	if(l>r) return 1;
	int pos=-1;
	for(int i=l;i<=r;i++)
	{
		if(exta[arr[rt]]&&extb[arr[rt]]&&brr[i]==arr[rt])
		{
			pos=i;
			break;
		}
	}
	int& ret=dp[rt][l][r];
	ret=0;
	if(exta[arr[rt]]&&extb[arr[rt]]&&pos==-1) ret=0;
	else{
		if(arr[rt]==0)
		{
			for(int i=l;i<=r;i++)
			{
				if(exta[brr[i]]) continue;
				ADD(ret,mul(solve(rt+1,l,i-1),solve(rt+i-l+1,i+1,r)));
			}
		}
		else{
			if(!extb[arr[rt]])
			{
				for(int i=l;i<=r;i++)
				{
					if(brr[i]==0)
						ADD(ret,mul(solve(rt+1,l,i-1),solve(rt+i-l+1,i+1,r)));
				}
			}
			else{
				ADD(ret,mul(solve(rt+1,l,pos-1),solve(rt+pos-l+1,pos+1,r)));
			}
		}
	}
	return ret;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,-1,sizeof(dp));
		memset(exta,0,sizeof(exta));
		memset(extb,0,sizeof(extb));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
			if(arr[i])
				exta[arr[i]]=1;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&brr[i]);
			if(brr[i])
				extb[brr[i]]=1;
		}
		int ans=solve(1,1,n);
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(!exta[i]&&!extb[i]) cnt++;
		for(int i=1;i<=cnt;i++)
			ans=mul(ans,i);
		printf("%d\n",ans);
	}
}
