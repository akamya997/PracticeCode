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
vector<PII> ans;
map<ll,int> sz;
int solve(ll cur)
{
	if(sz.count(cur)) return sz[cur];
	if(cur==1)
	{
		ans.push_back(make_pair(-1,-1));
		sz[1]=ans.size()-1;
		return sz[1];
	}
	int son1,son2;
	son2=solve(cur/2);
	son1=solve((cur+1)/2);
	ans.push_back(make_pair(son1,son2));
	return sz[cur]=ans.size()-1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		sz.clear();
		ans.clear();
		ll n;
		scanf("%lld",&n);
		int op=solve(n);
		printf("%d\n",(int)ans.size());
		for(auto &u:ans)
			printf("%d %d\n",u.first,u.second);
		printf("%d\n",op);
	}
}
