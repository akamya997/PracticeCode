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
int lcm(int a,int b)
{
	return a/__gcd(a,b)*b;
}
int main()
{
	int n;
	ll m;
	while(cin>>n>>m)
	{
		vector<int> a(n);
		int tar;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(!i) tar=a[i];
			else tar=lcm(tar,a[i]);
		}
		//dbg(tar);
		vector<ll> ans;
		ll tot=0;
		for(int i=0;i<n;i++) tot+=tar/a[i];
		if(m%tot!=0) puts("No");
		else{
			puts("Yes");
			vector<ll> ans(n);
			for(int i=0;i<n;i++)
			{
				ans[i]=tar/a[i]*m/tot;
				cout<<ans[i];
				if(i==n-1) cout<<endl;
				else cout<<" ";
			}
		}
	}
}
