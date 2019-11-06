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
int n;
typedef pair<int,int> PII;
const int maxn=1e5+7;
int arr[maxn];
int ans[maxn];
int cnt[maxn],cc[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		set<PII> s,s2;
		scanf("%d",&n);
		for(int i=0;i<=n;i++) cnt[i]=cc[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
			cnt[arr[i]]++;
			cc[arr[i]]+=2;
		}
		for(int i=1;i<=n;i++)
		{
			if(cnt[i])
			{
				s.insert(make_pair(cc[i],i));
				s2.insert(make_pair(i,cnt[i]));
			}
		}
		if((--s.end())->first>n)
		{
			puts("Impossible");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			s.erase(make_pair(cc[arr[i]],arr[i]));
			s.insert(make_pair(--cc[arr[i]],arr[i]));
			PII cur=*(--s.end());
			if(cur.first==n-i+1)
				ans[i]=cur.second;
			else{
				if(arr[i]==(s2.begin())->first)
					ans[i]=(++s2.begin())->first;
				else ans[i]=(s2.begin())->first;
			}
			s2.erase(make_pair(ans[i],cnt[ans[i]]));
			if(--cnt[ans[i]]) s2.insert(make_pair(ans[i],cnt[ans[i]]));
			s.erase(make_pair(cc[ans[i]], ans[i]));
			if(--cc[ans[i]]) s.insert(make_pair(cc[ans[i]], ans[i]));
		}
		for(int i=1;i<=n;i++)
			printf("%d%c",ans[i],i==n?'\n':' ');

	}
}
