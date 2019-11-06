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
const int maxn=1e4+7;
int num[maxn];
int arr[maxn];
int cur[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		memset(num,0,sizeof(num));
		memset(cur,0,sizeof(cur));
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
			num[arr[i]]++;
		}
		int ans=0;
		for(int i=1;i<=n/2;i++)
		{
			cur[arr[i]]++;
			if(cur[arr[i]]<=num[arr[i]]/k)
				ans++;
		}
		cout<<ans<<endl;

	}
}
