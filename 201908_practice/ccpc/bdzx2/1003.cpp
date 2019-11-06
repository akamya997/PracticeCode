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
const int maxn=1e6+7;
vector<int> prime;
bool vis[maxn];
int mu[maxn];
ll S[maxn];
void db()
{
	mu[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!vis[i])
		{
			prime.push_back(i);
			mu[i]=-1;
		}
		for(auto p:prime)
		{
			if(i*p>=maxn) break;
			if(i%p==0)
			{
				vis[i*p]=1;
				mu[i*p]=0;
				break;
			}
			vis[i*p]=1;
			mu[i*p]=mu[i]*mu[p];
		}
	}
	for(int i=1;i<maxn;i++)
	{
		for(int j=i;j<maxn;j+=i)
			S[j]+=mu[i]*mu[j/i];
	}
}
ll inv(ll a){return quick(a,mod-2);}
int main()
{
	int t;
	db();
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		ll ans=0;
		for(int T=1;T<=min(n,m);T++)
		{
			ll totn=0,totm=0;
			for(int i=1;i<=n/T;i++)
				totn+=mu[i*T];
			for(int i=1;i<=m/T;i++)
				totm+=mu[i*T];
			ans+=totn*totm*S[T];
		}
		cout<<ans<<endl;
	}

}
