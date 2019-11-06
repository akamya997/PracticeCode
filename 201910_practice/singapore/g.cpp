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
const int maxn=5005;
ll pown[maxn];
ll R[maxn],C[maxn];
int main()
{
	int n,r,c,k;
	cin>>n>>r>>c>>k;
	pown[0]=1;
	for(int i=0;i<maxn;i++)
		pown[i]=quick(i,n);
	for(int i=1;i<=r;i++)
	{
		for(int j=i;j<=r;j++)
		{
			R[j-i+1]=(R[j-i+1]+(pown[i]-pown[i-1]+mod)%mod*(pown[r-j+1]-pown[r-j]+mod)%mod)%mod;
		}
	}
	for(int i=1;i<=c;i++)
	{
		for(int j=i;j<=c;j++)
		{
			C[j-i+1]=(C[j-i+1]+(pown[i]-pown[i-1]+mod)%mod*(pown[c-j+1]-pown[c-j]+mod)%mod)%mod;
		}
	}
	ll ans=0;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(i*j>=k) 
				ans=(ans+R[i]*C[j]%mod)%mod;
		}
	}
	printf("%lld\n",ans);
}
