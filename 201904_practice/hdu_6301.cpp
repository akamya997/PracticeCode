#include<bits/stdc++.h>
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

using namespace std;
const int maxn=1e5+7;
struct Seg{
	int l,r;
	bool operator <(const Seg &a)const{
		if(l==a.l) return r<a.r;
		return l<a.l;
	}
}seg[maxn*2];
int ans[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
			scanf("%d%d",&seg[i].l,&seg[i].r);
		for(int i=1;i<=n;i++)
			seg[i+m-1].l=seg[i+m-1].r=i;
		sort(seg,seg+m);
		int L=1,R=0;
		priority_queue<int,vector<int>,greater<int> > q;
		for(int i=1;i<=n;i++) q.push(i);
		for(int i=0;i<m+n;i++)
		{
			while(L<seg[i].l) {q.push(ans[L]);L++;}
			while(R<seg[i].r)
			{
				R++;
				ans[R]=q.top();
				q.pop();
			}
		}
		printf("%d",ans[1]);
		for(int i=2;i<=n;i++)
			printf(" %d",ans[i]);
		printf("\n");
	}
}
