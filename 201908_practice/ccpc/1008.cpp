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
const ll INF=0x3f3f3f3f3f3f3f3f;
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
int need[maxn];
struct Fish{
	int rm,tot,id;
	bool operator<(const Fish &a)const{
		return rm>a.rm;
	}
}fish[maxn];
int n,k;
ll pre[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		ll tar=n-1;
		ll ans=k;
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&need[i]);
			tar-=need[i]/k;
			fish[i].rm=need[i]%k;
			fish[i].tot=need[i];
			fish[i].id=i;
			ans+=need[i];
		}
		sort(fish+1,fish+n+1);
		for(int i=1;i<=n;i++)
			pre[i]=pre[i-1]+fish[i].rm;
		ll waste=INF;
		for(int i=1;i<=n;i++)
		{
			ll cur=0;
			tar+=fish[i].tot/k;
			if(tar>0)
			{
				if(tar<i)
					cur+=tar*k-pre[tar];
				else cur+=tar*k-(pre[tar+1]-fish[i].rm);
			}
			tar-=fish[i].tot/k;
			waste=min(waste,cur);
		}
		printf("%lld\n",ans+waste);
	}
}
