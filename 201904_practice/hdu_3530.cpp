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
const int maxn=1e5+7;
int arr[maxn];
int main()
{
	int n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		deque<int> ma,mi;
		for(int i=0;i<n;i++) scanf("%d",&arr[i]);
		int ans=0;
		int lamax=-1,lamin=-1;
		for(int i=0;i<n;i++)
		{
			while(!ma.empty()&&arr[ma.back()]<=arr[i]) ma.pop_back();
			ma.push_back(i);
			while(!mi.empty()&&arr[mi.back()]>=arr[i]) mi.pop_back();
			mi.push_back(i);
			while(arr[ma.front()]-arr[mi.front()]>k)
			{
				if(ma.front()<mi.front()) {lamax=ma.front();ma.pop_front();}
				else {lamin=mi.front();mi.pop_front();}
			}
			if(arr[ma.front()]-arr[mi.front()]>=m) ans=max(ans,i-max(lamin,lamax));
		}
		printf("%d\n",ans);
	}
}
