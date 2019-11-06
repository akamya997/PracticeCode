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
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	while(cin>>n>>m)
	{
		vector<int> arr(n);
		vector<int> ans(n);
		bool ok=0;
		for(int i=0;i<n;i++) cin>>arr[i];
		for(int tar=1;tar<=m*10;tar++)
		{
			int tot=0;
			for(int i=0;i<n;i++)
			{
				if(tar%arr[i]!=0) break;
				tot+=tar/arr[i];
				ans[i]=tar/arr[i];
				if(tot>m) break;
				if(i==n-1&&tot==m) ok=1;
			}
			if(ok) break;
		}
		if(ok)
		{
			puts("Yes");
			for(int i=0;i<n;i++)
			{
				cout<<ans[i];
				if(i==n-1) cout<<endl;
				else cout<<" ";
			}
		}
		else puts("No");
	}
}
