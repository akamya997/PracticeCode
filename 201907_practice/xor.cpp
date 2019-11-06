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
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
const int maxn=1e5+7;
struct Base{
	ll a[63],m;
	Base(){m=0,memset(a,0,sizeof(a));}
	void init(){m=0,memset(a,0,sizeof(a));}
	bool ins(ll x)
	{
		for(int i=62;~i;--i)
			if(x>>i&1)
			{
				if(a[i]) x^=a[i];
				else{
					m++;
					a[i]=x;return 1;
				}
			}
		return 0;
	}
}las[maxn];
ll arr[maxn];
bool ok[maxn];
ll two[maxn];
int main()
{
	int n;
	two[0]=1;
	for(int i=1;i<maxn;i++) two[i]=two[i-1]*2%mod;
	while(scanf("%d",&n))
	{
		Base pre;
		for(int i=0;i<=n;i++) las[i].init(),ok[i]=0;
		for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
		for(int i=n-1;i>=0;i--)
		{
			las[i]=las[i+1];
			las[i].ins(arr[i]);
		}
		ll ans=0;
		Base cur;
		for(int i=0;i<n;i++)
			ok[i]=cur.ins(arr[i]);
		for(int i=0;i<n;i++)
		{
			if(!ok[i]) ans=(ans+two[n-1-cur.m])%mod;
			else{
				Base tmp=las[i+1];
				for(int j=0;j<63;j++)
					tmp.ins(pre.a[j]);
				if(!tmp.ins(arr[i])) ans=(ans+two[n-1-tmp.m])%mod;
			}
			pre.ins(arr[i]);
		}
		printf("%lld\n",ans);
		
	}

}
