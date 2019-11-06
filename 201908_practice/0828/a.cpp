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
int n,p,q,m;
typedef unsigned int uint;
uint SA,SB,SC;
inline uint rng()
{
	SA^=SA<<16;
	SA^=SA>>5;
	SA^=SA<<1;
	uint t=SA;
	SA=SB;
	SB=SC;
	SC^=t^SA;
	return SC;
}
const int maxn=5e6+7;
uint mx[maxn];
uint st[maxn];
int top;
inline ll PUSH(uint x)
{
	st[++top]=x;
	mx[top]=max(mx[top-1],x);
	return mx[top];
}
inline ll POP()
{
	if(!top) return 0;
	top--;
	return mx[top];
}
void solve()
{
	top=0;
	scanf("%d%d%d%d%u%u%u",&n,&p,&q,&m,&SA,&SB,&SC);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(rng()%(p+q)<p)
			ans^=(PUSH(rng()%m+1))*i;
		else ans^=POP()*i;
	}
	printf("%lld\n",ans);
}
int main()
{
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",++kas);
		solve();
	}
}
