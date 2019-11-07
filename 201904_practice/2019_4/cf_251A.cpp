#include<bits/stdc++.h>
using namespace std;
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
const int maxn=1e5+7;
long long arr[maxn];
int main()
{
	int n;
	long long d;
	cin>>n;
	cin>>d;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int l=0,r=0;
	long long le=arr[0],ri=0;
	long long cur=ri-le;
	long long ans=0;
	while(r<n-1)
	{
		r++;
		ri=arr[r];
		cur=ri-le;
		while(l<r-1&&cur>d)
		{
			l++;
			le=arr[l];
			cur=ri-le;
		}
		if(cur<=d)
			ans+=1LL*(r-l)*(r-l-1)/2;
	}
	cout<<ans<<endl;

}
