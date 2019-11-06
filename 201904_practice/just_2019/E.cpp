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
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		string s,c;
		int cur[200];
		memset(cur,0,sizeof(cur));
		cin>>s;
		cin>>c;
		map<char,vector<int> > cost;
		for(int i=0;i<n;i++)
			cost[s[i]].push_back(c[i]-'0');
		for(char i='a';i<='z';i++)
			sort(cost[i].begin(),cost[i].end());
		string p;
		cin>>p;
		int ans=0;
		for(int i=0;i<m;i++)
		{
			if(cur[p[i]]==cost[p[i]].size())
			{
				ans=-1;
				break;
			}
			ans+=cost[p[i]][cur[p[i]]];
			cur[p[i]]++;
		}
		cout<<ans<<endl;
	}
}
