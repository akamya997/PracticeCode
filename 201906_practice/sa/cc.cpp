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
const int maxn=5e5+7;
struct num{
	int id,dis;
	bool operator<(const num &a)const{
		return dis>a.dis;
	}
};
priority_queue<num> q;
int pre[maxn];
int arr[maxn],cab[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(int i=0;i<m;i++)
		scanf("%d",&cab[i]);
	sort(cab,cab+m);
	for(int i=1;i<n;i++)
	{
		q.push(num{i,arr[i]-arr[i-1]});
		pre[i]=i-1;
	}
	bool ok=1;
	for(int i=0;i<m;i++)
	{
		int cur=cab[i];
		if(q.empty()||cur<q.top().dis)
		{
			ok=0;break;
		}
		else{
			num tt=q.top();
			q.pop();
			if(pre[tt.id]>0)
			{
				pre[tt.id]--;
				q.push(num{tt.id,arr[tt.id]-arr[pre[tt.id]]});
			}
		}
	}
	if(ok) puts("yes");
	else puts("no");

}
