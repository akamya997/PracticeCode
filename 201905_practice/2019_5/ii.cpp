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
const int maxn=1e7+11;
vector<int> prime;
bool vis[maxn];
int ans[maxn];
int n,k;
int t[maxn];
const int mod=1e9+7;
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
void db()
{
	ans[1]=1;
	for(int i=2;i<n+10;i++)
	{
		if(!vis[i])
		{
			t[i]=i;
			prime.push_back(i);
			vis[i]=1;
			ans[i]=(quick(i,k)+1)%mod;
		}
		for(auto &p:prime)
		{
			if(i*p>=n+10) break;
			vis[i*p]=1;
			if(i%p==0)
			{
				t[i*p]=t[i]*p;
				if(t[i]==i) ans[i*p]=(1LL*(ans[p]-1)*ans[i]+1)%mod;
				else ans[i*p]=1LL*ans[i/t[i]]*ans[t[i]*p]%mod;
				break;
			}
			t[i*p]=p;
			ans[i*p]=1LL*ans[i]*ans[p]%mod;
		}
	}
}
int main()
{
	cin>>n>>k;
	db();
	ll op=0;
	for(int i=1;i<=n;i++) op=(op+ans[i])%mod;
	cout<<op<<endl;
}
