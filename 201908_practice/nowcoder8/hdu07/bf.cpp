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
int n,m,k;
ll ans=0;
ll getval(int n,int k)
{
	if(k==0) return 0;
	return ((m+n-k)/(n-k)+1)*n;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		ans=INF;
		cin>>n>>m>>k;
		ll temp=0;
		for(int i=k;i<=n;i++)
		{
			temp=getval(i,i-k+1);;
			ans=min(ans,temp);
			cout<<temp<<endl;
	//		dbg(i,ans,i*(m+1),getval(n-i,k-i));
		}
		cout<<ans<<endl;
	}
}
