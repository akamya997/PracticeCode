#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int INF=0x3f3f3f3f;
multiset<int> st[maxn];
vector<PII> add[maxn],del[maxn];
int main()
{
	int n,w;
	scanf("%d%d",&n,&w);
	for(int i=0;i<n;i++)
	{
		int v;
		scanf("%d",&v);
		for(int j=1,tmp;j<=v;j++) 
		{
			scanf("%d",&tmp);
			add[j].push_back(make_pair(tmp,i));
			del[w-v+j].push_back(make_pair(tmp,i));
		}
		if(v!=w)
		{
			add[1].push_back(make_pair(0,i));
			del[w-v].push_back(make_pair(0,i));
			add[v+1].push_back(make_pair(0,i));
			del[w].push_back(make_pair(0,i));
		}
	}
	ll ans=0;
	for(int i=1;i<=w;i++)
	{
		for(auto u:add[i])
		{
			int index=u.second;
			int val=u.first;
			ans-=(st[index].size()?*st[index].rbegin():0);
			st[index].insert(val);
			ans+=*st[index].rbegin();
		}
		printf("%lld ",ans);
		for(auto u:del[i])
		{
			int index=u.second;
			int val=u.first;
			ans-=*st[index].rbegin();
			st[index].erase(st[index].find(val));
			ans+=(st[index].size()?*st[index].rbegin():0);
		}
	}
	puts("");
}
