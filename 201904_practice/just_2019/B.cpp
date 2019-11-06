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
pair<int,int> ans[maxn];
bool occupy[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,q;
		scanf("%d%d%d",&n,&m,&q);
		for(int i=0;i<=m;i++) 
		{
			ans[i].first=ans[i].second=-1;
			occupy[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			for(int i=l;i<=r;i++) occupy[i]=1;
		}
		int cur=0;
		for(int i=m;i>=1;i--)
		{
			if(!occupy[i]) 
			{
				cur++;
				if(ans[cur].first==-1)
				{
					ans[cur].first=i;
					ans[cur].second=i+cur-1;
				}
			}
			else{
				cur=0;
			}
		}
		while(q--)
		{
			int s;
			scanf("%d",&s);
			printf("%d %d\n",ans[s].first,ans[s].second);
		}
	}
}
