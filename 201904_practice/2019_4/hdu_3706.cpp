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
const int maxn=1e7+5;
struct num{
	long long idx,val;
};
int main()
{
	int n,a,b;
	while(~scanf("%d%d%d",&n,&a,&b))
	{
		long long ans=1;
		long long cur=1;
		deque<num> t;
		for(int i=1;i<=n;i++)
		{
			cur=cur*a%b;
			if(t.front().idx<i-a) t.pop_front();
			while(!t.empty()&&t.back().val>=cur) t.pop_back();
			t.push_back(num {i,cur});
			ans=ans*t.front().val%b;
		}
		printf("%lld\n",ans);
	}


}
