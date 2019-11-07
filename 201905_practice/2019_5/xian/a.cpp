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
const int maxn=105;
int arr[maxn];
int main()
{
	int n,t;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	sort(arr+1,arr+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(t>=arr[i])
			ans++;
		else break;
		t-=arr[i];
	}
	cout<<ans<<endl;
}
