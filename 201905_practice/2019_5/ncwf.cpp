#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int mod=1e9+7;
const int maxn=2550;
struct node{
	int val,x,y;
	bool operator<(const node& a)const{
		if(val==a.val)
		{
			if(x==a.x) return y<a.y;
			return x<a.x;
		}
		return val<a.val;
	}
}all[maxn*maxn];
int p[maxn];
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
int main()
{
	int n;
	scanf("%d",&n);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0,tmp;j<n;j++)
		{
			scanf("%d",&tmp);
			all[cnt++]={tmp,i,j};
		}
	}
	sort(all,all+cnt);
	ll ans=0;
	ll res=1;
	int cur=0;
	for(int i=0;i<cnt;i++)
	{
		if(!p[all[i].x]) cur++;
		if(p[all[i].x]) res=res*inv(p[all[i].x])%mod*(p[all[i].x]+1)%mod;
		p[all[i].x]++;
		if(cur==n)
			ans=(ans+1LL*all[i].val*res%mod*inv(p[all[i].x])%mod)%mod;
	}
	ans=ans*inv(quick(n,n))%mod;
	printf("%lld\n",ans);
}
