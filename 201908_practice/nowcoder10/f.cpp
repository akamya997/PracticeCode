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
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
const int maxn=1e5+7;
vector<int> row[maxn];
int cnt[maxn];
int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	multiset<int> st;
	for(int i=0,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		row[x].push_back(y);
		cnt[y]++;
		if(y>=r) cnt[y-r]++;
		if(y>=2*r) cnt[y-2*r]++;
	}
	int ans=0;
	for(int i=0;i<=100000;i++)
		st.insert(cnt[i]);
	for(int i=0;i+2*r<=100000;i++)
	{
		int cur=0;
		for(auto u:row[i])
		{
			cur++;
			st.erase(st.find(cnt[u]));
			cnt[u]--;
			st.insert(cnt[u]);
			if(u>=r){
				st.erase(st.find(cnt[u-r]));
				cnt[u-r]--;
				st.insert(cnt[u-r]);
			}
			if(u>=2*r)
			{
				st.erase(st.find(cnt[u-2*r]));
				cnt[u-2*r]--;
				st.insert(cnt[u-2*r]);
			}
		}
		for(auto u:row[i+r])
		{
			cur++;
			st.erase(st.find(cnt[u]));
			cnt[u]--;
			st.insert(cnt[u]);
			if(u>=r){
				st.erase(st.find(cnt[u-r]));
				cnt[u-r]--;
				st.insert(cnt[u-r]);
			}
			if(u>=2*r)
			{
				st.erase(st.find(cnt[u-2*r]));
				cnt[u-2*r]--;
				st.insert(cnt[u-2*r]);
			}
		}
		for(auto u:row[i+2*r])
		{
			cur++;
			st.erase(st.find(cnt[u]));
			cnt[u]--;
			st.insert(cnt[u]);
			if(u>=r){
				st.erase(st.find(cnt[u-r]));
				cnt[u-r]--;
				st.insert(cnt[u-r]);
			}
			if(u>=2*r)
			{
				st.erase(st.find(cnt[u-2*r]));
				cnt[u-2*r]--;
				st.insert(cnt[u-2*r]);
			}
		}
		cur+=*(--st.end());
		ans=max(cur,ans);
		for(auto u:row[i])
		{
			cur++;
			st.erase(st.find(cnt[u]));
			cnt[u]++;
			st.insert(cnt[u]);
			if(u>=r){
				st.erase(st.find(cnt[u-r]));
				cnt[u-r]++;
				st.insert(cnt[u-r]);
			}
			if(u>=2*r)
			{
				st.erase(st.find(cnt[u-2*r]));
				cnt[u-2*r]++;
				st.insert(cnt[u-2*r]);
			}
		}
		for(auto u:row[i+r])
		{
			cur++;
			st.erase(st.find(cnt[u]));
			cnt[u]++;
			st.insert(cnt[u]);
			if(u>=r){
				st.erase(st.find(cnt[u-r]));
				cnt[u-r]++;
				st.insert(cnt[u-r]);
			}
			if(u>=2*r)
			{
				st.erase(st.find(cnt[u-2*r]));
				cnt[u-2*r]++;
				st.insert(cnt[u-2*r]);
			}
		}
		for(auto u:row[i+2*r])
		{
			cur++;
			st.erase(st.find(cnt[u]));
			cnt[u]++;
			st.insert(cnt[u]);
			if(u>=r){
				st.erase(st.find(cnt[u-r]));
				cnt[u-r]++;
				st.insert(cnt[u-r]);
			}
			if(u>=2*r)
			{
				st.erase(st.find(cnt[u-2*r]));
				cnt[u-2*r]++;
				st.insert(cnt[u-2*r]);
			}
		}
	}
	printf("%d\n",ans);
}
