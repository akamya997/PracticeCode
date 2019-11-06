#include<bits/stdc++.h>
using namespace std;
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
const int maxn=1e6+7;
long long arr[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&arr[i]);
	}
	int l=1,r=n;
	int ans=0;
	while(l<r)
	{
		if(arr[l]==arr[r])
		{
			l++,r--;
		}
		else{
			if(arr[l]<arr[r])
			{
				arr[l+1]+=arr[l];
				l++,ans++;
			}
			else {
				arr[r-1]+=arr[r];
				r--;ans++;
			}
		}
	}
	printf("%d\n",ans);
}
