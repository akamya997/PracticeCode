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
const int maxn=1e3+7;
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
		map<int,int> row[maxn];
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int temp;
				cin>>temp;
				row[i][temp]++;
			}
			if(i==0) continue;
			for(auto p:row[i])
			{
				ans+=min(row[i-1][p.first],p.second);
			}
		}
		cout<<ans<<endl;
	}
}
