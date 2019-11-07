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
const int maxn=1e6+7;
long long arr[maxn];
struct qnode{
	int pos;
	int val;
	bool operator<(const qnode &a) const{
		if(a.val==val) return pos<a.pos;
		return val<a.val;
	}
}qrr[maxn];
int main()
{
	int T,kas=0;
	cin>>T;
	while(T--)
	{
		int n,p,k;
		cin>>n>>p>>k;
		for(int i=1;i<=n;i++) 
		{
			cin>>arr[i];
			arr[i]+=arr[i-1];
			qrr[i].val=arr[i]%p;
			qrr[i].pos=i;
		}
		sort(qrr+1,qrr+1+n);
		deque<qnode> q;
		q.push_back(qnode {0,0});
		long long ans=-1;
		for(int i=1;i<=n;i++)
		{
			while(!q.empty()&&q.back().pos>=qrr[i].pos)
			{
				q.pop_back();
			}
			q.push_back(qrr[i]);
			while(qrr[i].val-q.front().val>k) q.pop_front();
			if(q.size()!=1)
				ans=max(ans,(arr[qrr[i].pos]-arr[q.front().pos])/p);
		}
		cout<<"Case "<<++kas<<": "<<ans<<endl;

	}
}
