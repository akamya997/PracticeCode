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
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
const int maxn=1e7+7;
int fac[maxn];
set<pair<int,int> > st;
int main()
{
	int a,b;
	scanf("%d%d%d%d",&fac[0],&fac[1],&a,&b);
	st.insert(make_pair(fac[0],fac[1]));
	int cnt=0;
	for(int i=2;i<maxn;i++)
	{
		fac[i]=1LL*fac[i-1]*a%mod+1LL*fac[i-2]*b%mod;
		fac[i]%=mod;
		pair<int,int> cur=make_pair(fac[i],fac[i-1]);
		if(st.find(cur)!=st.end())break;
		cnt++;
		st.insert(cur);
	}
}
