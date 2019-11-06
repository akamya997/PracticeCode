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
template<typename T>
void fwt(ll a[], int n, T f) {
    for (int d = 1; d < n; d *= 2)
        for (int i = 0, t = d * 2; i < n; i += t)
            for(int j = 0; j < d; j++)
                f(a[i + j], a[i + j + d]);
}

void AND(ll& a, ll& b) { a += b; }
const int maxn=25;
ll a[maxn],b[maxn];
ll cnt[1<<20];
int n;
ll h;
void dfs(int u,int st,ll sum)
{
	if(u==n)
	{
		if(sum>=h) cnt[st]++;
		return;
	}
	dfs(u+1,st|(1<<u),sum+a[u]);
	dfs(u+1,st,sum);
}
int tot;
ll ans;
void solve(int u,int st,ll sum)
{
	if(u==n)
	{
		if(sum>=h)
			ans+=cnt[tot^st];
		return;
	}
	solve(u+1,st|(1<<u),sum+b[u]);
	solve(u+1,st,sum);
}
int main()
{
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%d%lld",&n,&h);
		for(int i=0;i<n;i++) scanf("%lld",&a[i]);
		for(int i=0;i<n;i++) scanf("%lld",&b[i]);
		dfs(0,0,0);
		tot=(1<<n)-1;
		fwt(cnt,1<<n,AND);
		ans=0;
		solve(0,0,0);
		printf("Case #%d: %lld\n",++kas,ans);
	}
}
