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
const int maxn=1e5+7;
int arr[maxn];
vector<int> all;
int tree[maxn];
int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
void add(int x)
{
	while(x<maxn)
	{
		tree[x]++;
		x+=x&-x;
	}
}
ll query(int x)
{
	ll ret=0;
	while(x>0)
	{
		ret+=tree[x];
		x-=x&-x;
	}
	return ret;
}
int main()
{
	int n,x,y;
	while(~scanf("%d%d%d",&n,&x,&y))
	{
		all.clear();
		for(int i=0;i<n;i++)
		{
			tree[i+1]=0;
			scanf("%d",&arr[i]);
			all.push_back(arr[i]);
		}
		sort(all.begin(),all.end());
		all.erase(unique(all.begin(),all.end()),all.end());
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			ans+=i-query(getid(arr[i]));
			add(getid(arr[i]));
		}
		printf("%lld\n",ans*min(x,y));
	}
}
