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
typedef pair<int,int> PII;
const int maxn=1e5+7;
int arr[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&arr[i]);
		set<int> ans;
		int cur[31];
		memset(cur,0,sizeof(cur));
		for(int i=1;i<=n;i++)
		{
			vector<PII> pp;
			for(int j=0;j<31;j++)
			{
				pp.push_back(make_pair(cur[j],j));
				if(arr[i]&(1<<j)) cur[j]=i;
			}
			sort(pp.begin(),pp.end());
			reverse(pp.begin(),pp.end());
			int num=arr[i];
			ans.insert(num);
			for(int j=0;j<pp.size();j++)
			{
				if(pp[j].first==0) break;
				if(j!=pp.size()-1&&pp[j].first==pp[j+1].first) num|=(1<<pp[j].second);
				else{
					num|=(1<<pp[j].second);
					ans.insert(num);
				}
			}
		}
		printf("%d\n",(int)ans.size());

	}
}
