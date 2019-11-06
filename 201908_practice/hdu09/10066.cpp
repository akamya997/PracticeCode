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
int val[105];
int check(int cur,int i,int j,int k)
{
	vector<int> all;
	for(int n=1;n<=i;n++) all.push_back(10);
	for(int n=1;n<=j;n++) all.push_back(20);
	for(int n=1;n<=k;n++) all.push_back(50);
	int ret=INF;
	for(int t=0;t<(1<<all.size());t++)
	{
		int tmp=cur;
		for(int p=0;p<all.size();p++)
			if(t>>p&1) tmp-=all[p];
		if(tmp>=0&&tmp%100==0)
			ret=min(ret,tmp/100);
	}
	if(ret==INF) return -1;
	return ret;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		bool vv=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&val[i]);
			if(val[i]%10!=0) vv=0;
		}
		if(!vv){
			puts("-1");
			continue;
		}
		int ans=INF;
		for(int i=0;i<=1;i++)
		{
			for(int j=0;j<=4;j++)
			{
				for(int k=0;k<=1;k++)
				{
					int cur=i+j+k;
					int mx=0;
					bool ok=1;
					for(int ii=1;ii<=n;ii++)
					{
						int cnt=check(val[ii],i,j,k);
						if(cnt==-1)
						{
							ok=0;break;
						}
						mx=max(mx,cnt);
					}
					if(ok) ans=min(ans,mx+cur);
				}
			}
		}
		printf("%d\n",ans);
	}
}
