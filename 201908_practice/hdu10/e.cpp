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
const int maxn=100;
int p[maxn];
int arr[maxn];
int ans[maxn];
int n,d;
int dfs(int cur)
{
	if(cur==n)
	{
		if(abs(p[cur]-arr[cur-1])<=d) return 0;
		else return INF;
	}
	int ret=INF;
	for(int i=0;i<=10;i++)
	{
		if(abs(i-arr[cur-1])>d) continue;
		arr[cur]=i;
		ret=min(ret,abs(i-p[cur])+dfs(cur+1));
	}
	return ret;
}
int main()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>p[i];
	arr[1]=p[1];
	cout<<dfs(2)<<endl;

}
