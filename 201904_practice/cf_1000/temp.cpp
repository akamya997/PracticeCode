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
struct Seg{
	int l,r;
};
vector<Seg> G[maxn];
int cur,scc_cnt;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int op;
		scanf("%d",&op);
		if(!op)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			G[x].clear();
			arr[x]=y;
		}
		else{
			int x,l,r;
			scanf("%d%d%d",&x,&l,&r);
			G[x].push_back(Seg{l,r});
		}
	}
	SCC();
}
