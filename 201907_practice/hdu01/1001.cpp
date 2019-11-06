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
struct Seg{
	int l,r,x;
	bool operator<(const Seg a)const{
		return r<a.r;
	}
}seg[maxn];
int dp[2][maxn][maxn][maxn];
inline bool check(Seg a,int p1,int p2,int p3,int p4)
{
	int cnt=0;
	if(p1>=a.l) cnt++;
	if(p2>=a.l) cnt++;
	if(p3>=a.l) cnt++;
	if(p4>=a.l) cnt++;
	return cnt==a.x;
}
inline void ADD(int& a,int& b)
{
	a=a+b;
	if(a>=mod) a-=mod;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp[0],0,sizeof(dp[0]));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++) scanf("%d%d%d",&seg[i].l,&seg[i].r,&seg[i].x);
		sort(seg,seg+m);
		int cur=0;
		dp[0][0][0][0]=1;
		int pos=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
				for(int k=0;k<=j;k++)
					for(int l=0;l<=k;l++)
						dp[cur^1][j][k][l]=0;
			for(int j=0;j==0||j<i;j++)
			{
				for(int k=0;k==0||k<j;k++)
				{
					for(int l=0;l==0||l<k;l++)
					{
						bool ok1=1,ok2=1,ok3=1,ok4=1;
						for(int tt=pos;seg[tt].r==i+1;tt++)
						{
							if(!check(seg[tt],i+1,j,k,l)) ok1=0;
							if(!check(seg[tt],i+1,i,k,l)) ok2=0;
							if(!check(seg[tt],i+1,i,j,l)) ok3=0;
							if(!check(seg[tt],i+1,i,j,k)) ok4=0;
						}
	//					dbg(ok1,ok2,ok3,ok4,i+1,j,k,l);
						if(ok1) ADD(dp[cur^1][j][k][l],dp[cur][j][k][l]);
						if(ok2) ADD(dp[cur^1][i][k][l],dp[cur][j][k][l]);
						if(ok3) ADD(dp[cur^1][i][j][l],dp[cur][j][k][l]);
						if(ok4) ADD(dp[cur^1][i][j][k],dp[cur][j][k][l]);
					}
				}
			}
			while(seg[pos].r==i+1) pos++;
			cur^=1;
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				for(int k=0;k<=j;k++)
					ADD(ans,dp[cur][i][j][k]);
			}
		}
		printf("%d\n",ans);
	}
}
