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
const int maxn=1050;
char maze[maxn][maxn];
int n,m;
int h[maxn];
int dpl[maxn],dpr[maxn];
typedef pair<int,int> PII;
ll getans()
{
	ll ret=0;
	memset(h,0,sizeof(h));
	h[0]=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			h[j]=(maze[i][j]=='1'?h[j]+1:0);
		for(int j=1;j<=m;j++)
		{
			if(h[j]<=h[j-1]) dpl[j]=dpl[j-1];
        	else dpl[j]=j;
        	while(h[dpl[j]-1]>=h[j]) dpl[j]=dpl[dpl[j]-1];	
		}
		h[m+1]=-1;
		for(int j=m;j>=1;j--)
    	{
        	if(h[j]<=h[j+1]) dpr[j]=dpr[j+1];
        	else dpr[j]=j;
        	while(h[dpr[j]+1]>=h[j]) dpr[j]=dpr[dpr[j]+1];
			ret=max(ret,1LL*(dpr[j]-dpl[j]+1)*h[j]);
    	}
	}
	return ret;
}
void solve()
{
	memset(h,0,sizeof(h));
	h[0]=-1;
	int l,r,hi,base;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			h[j]=(maze[i][j]=='1'?h[j]+1:0);
		for(int j=1;j<=m;j++)
		{
			if(h[j]<=h[j-1]) dpl[j]=dpl[j-1];
        	else dpl[j]=j;
        	while(h[dpl[j]-1]>=h[j]) dpl[j]=dpl[dpl[j]-1];	
		}
		h[m+1]=-1;
		for(int j=m;j>=1;j--)
    	{
        	if(h[j]<=h[j+1]) dpr[j]=dpr[j+1];
        	else dpr[j]=j;
        	while(h[dpr[j]+1]>=h[j]) dpr[j]=dpr[dpr[j]+1];
			if(ans<(dpr[j]-dpl[j]+1)*h[j])
			{
				r=dpr[j],l=dpl[j],hi=h[j],base=i;;
				ans=(dpr[j]-dpl[j]+1)*h[j];
			}
    	}
	}
	ll ret=0;
	maze[base][l]='0';
	ret=max(ret,getans());
	maze[base][l]='1';
	maze[base][r]='0';
	ret=max(ret,getans());
	maze[base][r]='1';
	maze[base-hi+1][l]='0';
	ret=max(ret,getans());
	maze[base-hi+1][l]='1';
	maze[base-hi+1][r]='0';
	ret=max(ret,getans());
	printf("%lld\n",ret);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",maze[i]+1);
	solve();
}
