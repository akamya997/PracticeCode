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
string s1="0COFFEE",s2="0CHICKEN";
ll len[100];
char solve(int n,ll k)
{
	if(n==1)
		return s1[k];
	else if(n==2) return s2[k];
	ll l1=len[n-2],l2=len[n-1];
	assert(k<=l1+l2);
	if(k<=l1) return solve(n-2,k);
	else return solve(n-1,k-l1);
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	len[1]=6,len[2]=7;
	for(int i=3;i<70;i++)
		len[i]=len[i-1]+len[i-2];
	cin>>T;
	while(T--)
	{
		int n;
		ll k;
		cin>>n>>k;
		n=min(n,69);
		for(ll i=k;i<=min(k+9,len[n]);i++)
			cout<<solve(n,i);
		cout<<'\n';
	}
}
