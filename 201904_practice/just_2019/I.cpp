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
int arr[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int n,k;
		cin>>n>>k;
		int ans=0;
		for(int i=0;i<n;i++) 
		{
			cin>>arr[i];
			ans+=arr[i];
		}
		sort(arr,arr+n);
		for(int i=0;i<n;i++)
		{
			if(arr[i]>=0||!k) break;
			k--;
			ans+=-2*arr[i];
			arr[i]*=-1;
		}
		dbg(ans);
		if(k)
		{
			sort(arr,arr+n);
			if(k%2==1) ans-=2*arr[0];
		}
		cout<<ans<<endl;
	}
}
