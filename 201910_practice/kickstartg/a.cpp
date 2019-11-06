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
const int maxn=1e5+7;
int ans[maxn];
int main()
{
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,q;
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++) ans[i]=n/i;
		for(int i=0,tmp;i<m;i++)
		{
			scanf("%d",&tmp);
			for(int j=1;j*j<=tmp;j++)
			{
				if(tmp%j==0)
				{
					ans[j]--;
					if(j*j!=tmp) ans[tmp/j]--;
				}
			}
		}
		ll op=0;
		while(q--)
		{
			int r;
			scanf("%d",&r);
			op+=ans[r];
		}
		printf("Case #%d: %lld\n",++kas,op);
	}
}
