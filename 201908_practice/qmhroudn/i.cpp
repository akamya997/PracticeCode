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
ll l,r,k;
vector<ll> d;
ll solve(ll n)
{
	if(n<=0) return 0;
	ll ans=0;
	for(int i=0;i<(1<<d.size());i++)
	{
		int cnt=__builtin_popcount(i);
		ll cur=1;
		for(int j=0;j<d.size();j++)
		{
			if(i>>j&1)
				cur*=d[j];
		}
		if(!(cnt&1)) ans+=n/cur;
		else ans-=n/cur;
	}
	return ans;
}
int main()
{
	cin>>l>>r>>k;
	k<<=1;
	r-=k;
	if(l>r) 
	{
		cout<<0<<endl;
		return 0;
	}
	for(ll i=2;i*i<=k;i++)
	{
		if(k%i==0) d.push_back(i);
		while(k%i==0)
			k/=i;
	}
	if(k!=1) d.push_back(k);
	sort(d.begin(),d.end());
	cout<<solve(r)-solve(l-1)<<endl;
}
