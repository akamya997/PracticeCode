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
const int maxn=2e5+7;
int arr[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	int ans=0;
	bool down=1;
	int cur=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(int i=1;i<=n;i++)
	{
		if(!down)
		{
			if(arr[i]>cur)
				cur=arr[i];
			else cur=arr[i],down=1;
		}
		else{
			if(arr[i]>=cur)
			{
				ans++;
				down=0;
				cur=arr[i];
			}
			else cur=arr[i];
		}
	}
	printf("%d\n",ans);
}
