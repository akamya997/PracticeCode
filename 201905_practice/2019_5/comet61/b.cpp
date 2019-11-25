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
int arr[16];
int n;
bool check(int cur)
{
	vector<int> all;
	for(int i=0;i<n;i++)
	{
		if(cur&(1<<i))
		{
			all.push_back(arr[i]);
		}
	}
	for(int i=0;i<all.size();i++)
	{
		for(int j=0;j<i;j++)
		{
			if(__gcd(all[i],all[j])!=1)
				return false;
		}
	}
	return true;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int ans=0;
		for(int i=0;i<(1<<n);i++)
		{
			if(check(i))
				ans=max(ans,__builtin_popcount(i));
		}
		cout<<ans<<endl;
	}
}
