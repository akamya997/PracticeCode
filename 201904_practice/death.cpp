#include<bits/stdc++.h>
using namespace std;
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
vector<long long> all;
long long d[15];
const int maxn=1e6+7;
long long id[maxn];
long long t[maxn];
map<int,int> mp,mpt;
struct Point{
	int a[15];
	bool operator<(const Point& b)const{
		for(int i=0;i<15;i++)
		{
			if(a[i]<b.a[i]) return true;
			else if(a[i]>b.a[i]) return false;
		}
		return false;
	}
};
map<Point,int> pp;
int main()
{
	int n;
	scanf("%d",&n);
	int tot=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		tot*=d[i];
	}
	int cnt=0;
	for(int i=0,temp;i<tot;i++)
	{
		Point cur;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&cur.a[j]);
		}
		if(!pp.count(cur))
			pp[cur]=++cnt;
		all.push_back(pp[cur]);
		mp[pp[cur]]=i;
		id[i]=pp[cur];
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&cur.a[j]);
		}
		if(!pp.count(cur))
			pp[cur]=++cnt;
		t[i]=pp[cur];
		mpt[pp[cur]]=i;
	}
	sort(all.begin(),all.end());
	int ans=0;
	int T;
	scanf("%d",&T);
	for(int i=0;i<all.size();i++)
	{
		int cur=all[i];
		int pos=mp[cur];
		if(id[pos]==t[pos]) continue;
		ans++;
		long long nxt=t[pos];
		int idx=mpt[cur];
		swap(t[pos],t[mpt[cur]]);
		mpt[cur]=pos;
		mpt[nxt]=idx;
	}
	dbg(ans);
	if(ans>T) puts("NO");
	else {
		if((T-ans)%2==0) puts("YES");
		else puts("NO");
	}
}
