#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int cnt(ll cur)
{
	int ret=0;
	bool vis[15];
	memset(vis,0,sizeof(vis));
	while(cur)
	{
		if(!vis[cur%10]) vis[cur%10]=1,ret++;
		cur/=10;
	}
	return ret;
}
const int maxn=65536;
int main()
{
	int n;
	while(cin>>n&&n)
	{
		ll up=1LL*n*n*1000;
		int mc=100;
		ll ans=n;
		for(ll i=n;i<=up;i+=n)
		{
			int c=cnt(i);
			if(c==1)
			{
				ans=i;
				break;
			}
			if(c<mc)
			{
				ans=i;
				mc=c;
			}
		}
		cout<<ans<<endl;
	}
}
