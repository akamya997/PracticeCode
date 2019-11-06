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
const int maxn=1e5+7;
int arr[maxn];
const int MAXN=1e7+7;
bool vis[MAXN];
int mu[MAXN];
int tot;
int prime[MAXN];
void db()
{
	mu[1]=1;
	for(int i=2;i<MAXN;i++)
	{
		if(!vis[i])
		{
			prime[tot++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<tot;j++)
		{
			if(i*prime[j]>=MAXN) break;
			if(i%prime[j]==0)
			{
				mu[i*prime[j]]=0;
				vis[i*prime[j]]=1;
				break;
			}
			vis[i*prime[j]]=1;
			mu[i*prime[j]]=mu[i]*mu[prime[j]];
		}
	}
}
int main()
{
	db();
	int T;
	cin>>T;
	while(T--)
	{
		int n,q;
		const int mx=100;
		cin>>n>>q;
		for(int i=1;i<=n;i++)
			cin>>arr[i];
		for(int i=1;i<=q;i++)
		{
			int l,r;
			cin>>l>>r;
			map<int,int> cnt;
			for(int j=l;j<=r;j++)
				cnt[arr[j]]++;
			ll ans=0;
			for(int T=1;T<=mx;T++)
			{
				ll cur=mu[T]*T;
				ll suma=0;
				for(int j=1;j<=mx/T;j++)
					suma+=j*cnt[j*T];
				ans+=cur*suma*suma;
			}
			cout<<ans<<endl;
		}
	}
}
