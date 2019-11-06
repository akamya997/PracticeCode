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
ll sz[200];
int main()
{
	ll n;
	cin>>n;
	int v;
	cin>>v;
	for(int i=0;i<v;i++)
	{
		int l,r;
		cin>>l>>r;
		assert(l<i&&l>=-1&&r>=-1&&r<i);
		if(l==-1&&r==-1)
			sz[i]=1;
		else{
			ll szl=0,szr=0;
			if(l!=-1)
				szl=sz[l];
			if(r!=-1)
				szr=sz[r];
			assert(szl==szr||szl==szr+1);
			sz[i]=szl+szr;
		}
	}
	int ans;
	cin>>ans;
	cout<<ans<<":"<<sz[ans]<<endl;
	assert(sz[ans]==n);
	puts("accepted!");
}
