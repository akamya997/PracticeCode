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
inline ll C2(ll n)
{
	if(n<2) return 0;
	return n*(n-1)/2;
}
inline ll C3(ll n)
{
	if(n<3) return 0;
	return n*(n-1)/2*(n-2)/3;
}
inline ll C4(ll n)
{
	if(n<4) return 0;
	return (__int128)n*(n-1)/2*(n-2)/3*(n-3)/4;
}
const int maxn=1e5+6;
int fa[maxn];
ll sum;
ll cnt[maxn];
int n,m;
__int128 ans;
__int128 tt;
void init()
{
	ans=0;
	tt=0;
	for(int i=0;i<=n;i++) fa[i]=i,cnt[i]=1;
	sum=0;
}
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x);y=Find(y);
	if(x!=y)
	{
		ans-=tt/2;
		sum-=C2(cnt[x]);
		tt-=(__int128)sum*C2(cnt[x])*2;
		sum-=(__int128)C2(cnt[y]);
		tt-=(__int128)sum*C2(cnt[y])*2;
		ans+=(__int128)C3(cnt[y])*(n-cnt[y]);
		ans+=(__int128)C3(cnt[x])*(n-cnt[x]);//3
		ans+=(__int128)C2(cnt[y])*C2(n-cnt[y]);
		ans+=(__int128)C2(cnt[x])*C2(n-cnt[x]);//2x
		ans+=C4(cnt[x]);
		ans+=C4(cnt[y]);
		cnt[x]+=cnt[y];
		fa[y]=x;
		ans-=(__int128)C3(cnt[x])*(n-cnt[x]);
		ans-=(__int128)C2(cnt[x])*C2(n-cnt[x]);
		ans-=C4(cnt[x]);
		tt+=(__int128)sum*C2(cnt[x])*2;
		ans+=tt/2;
		sum+=(__int128)C2(cnt[x]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	init();
	ans=C4(n);
	printf("%lld\n",(ll)ans);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Union(x,y);
		printf("%lld\n",(ll)ans);
	}
}
