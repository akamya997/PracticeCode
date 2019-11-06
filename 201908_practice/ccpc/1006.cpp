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
int lev[maxn];
int id[maxn];
bool cmp(int i,int j)
{
	return lev[i]>lev[j];
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int cur=300000;
	int vv=cur+1;
	for(int i=1,tmp;i<=n;i++)
	{
		scanf("%d",&tmp);
		lev[tmp]=cur--;
		id[i]=i;
	}
	for(int i=0,tmp;i<m;i++)
	{
		scanf("%d",&tmp);
		lev[tmp]=vv++;
	}
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;i++)
		printf("%d ",id[i]);
}
