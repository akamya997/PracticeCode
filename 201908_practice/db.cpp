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
const int maxn=5e6+7;
int sg[maxn];
vector<int> all;
bool getsg(int x)
{
	if(sg[x]!=-1) return sg[x];
	bool win=0;
	for(auto u:all)
	{
		if(u>x) break;
		if(!getsg(x-u))
		{
			win=1;
			break;
		}
	}
	return sg[x]=win;
}
int main()
{
	int n;
		ll tar;
		cin>>n>>tar;
		all.clear();
		memset(sg,-1,sizeof(sg));
		ll cur=1;
		for(int i=1;cur<=tar;i++)
		{
			if(i>1&&cur==1) break;
			all.push_back(cur);
			cur*=n;
		}
		getsg(tar);
		if(sg[tar])
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
}
