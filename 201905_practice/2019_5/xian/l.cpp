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
map<vector<int>,int> cnt;
int ans;
int dfs(vector<int> cur)
{
	if(cnt.count(cur)) return 0;
	cnt[cur]=1;
	ans++;
	int sz=cur.size();
	vector<int> nxt=cur;
	if(sz%2==0)
	{
		for(int i=0;i<sz/2;i++)
			swap(nxt[i],nxt[i+sz/2]);
	}
	else{
		for(int i=0;i<sz/2;i++)
			swap(nxt[i],nxt[i+sz/2+1]);
	}
	vector<int> nxt2=cur;
	for(int i=1;i<sz;i+=2)
	{
		swap(nxt2[i],nxt2[i-1]);
	}
	dfs(nxt);
	dfs(nxt2);
}
int solve(vector<int> cur)
{
	dfs(cur);
	return ans;
}
int main()
{
	vector<int> all;
	int n=100;
	for(int i=1;i<=n;i++)
	{
		ans=0;
		all.clear();
		cnt.clear();
		for(int j=1;j<=i;j++)
			all.push_back(j);
		cout<<i<<" "<<solve(all)<<endl;
	}
}
