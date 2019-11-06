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
int upa[50],upb[50],upc[50];
ll dp[40][2][2][2][2][2][2];
int a,b,c;
ll dfs(int pos,bool limita,bool limitb,bool za,bool zb,bool oka,bool okb)
{
	if(pos==-1)
		return !za&&!zb;
	if(dp[pos][limita][limitb][za][zb][oka][okb]!=-1) return dp[pos][limita][limitb][za][zb][oka][okb];
	ll &ret=dp[pos][limita][limitb][za][zb][oka][okb];
	ret=0;
		int aa=limita?upa[pos]:1,bb=limitb?upb[pos]:1;
		if(upc[pos]==0)
		{
			ret+=dfs(pos-1,limita&&(aa==0),limitb&&(bb==0),za,zb,oka,okb);//00
			if(bb==1)//01
				ret+=dfs(pos-1,limita&&(aa==0),limitb,za,0,oka,1);
			if(aa==1)//10
				ret+=dfs(pos-1,limita,limitb&&(bb==0),0,zb,oka,1);
			if(oka&&aa&&bb)//11
				ret+=dfs(pos-1,limita,limitb,0,0,oka,okb);
		}
		else{
			if(bb==1)//01
				ret+=dfs(pos-1,limita&&(aa==0),limitb,za,0,1,okb);
			if(aa==1)//10
				ret+=dfs(pos-1,limita,limitb&&(bb==0),0,zb,1,okb);
			if(okb)//00
				ret+=dfs(pos-1,limita&&(aa==0),limitb&&(bb==0),za,zb,1,okb);
			if(aa&&bb&&okb)//11
				ret+=dfs(pos-1,limita,limitb,0,0,oka,okb);
		}
	return ret;
}
ll solve()
{
	memset(dp,-1,sizeof(dp));
	memset(upa,0,sizeof(upa));
	memset(upb,0,sizeof(upb));
	memset(upc,0,sizeof(upc));
	int posa=0;
	while(a)
	{
		upa[posa++]=a%2;
		a/=2;
	}
	int posb=0;
	while(b)
	{
		upb[posb++]=b%2;
		b/=2;
	}
	int posc=0;
	while(c)
	{
		upc[posc++]=c%2;
		c/=2;
	}
	return dfs(31,1,1,1,1,0,0);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		printf("%lld\n",1LL*a*b-solve());
	}
}
