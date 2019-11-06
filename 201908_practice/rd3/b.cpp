#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
const int maxn=2e5+7;
int arr[maxn];
int ans[maxn];
bool vis[maxn];
struct Q{
	int val,id,page;
	bool operator<(const Q &a)const{
		if(val==a.val) return id<a.id;
		return val<a.val;
	}
}query[maxn*2];
int main()
{
	int cnt=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		query[cnt++]={arr[i],-1,i};
	}
	vis[0]=vis[n+1]=1;
	int q;
	scanf("%d",&q);
	for(int i=0,x;i<q;i++)
	{
		scanf("%d",&x);
		query[cnt++]={x,i,-1};
	}
	int cur=1;
	sort(query,query+cnt);
	for(int i=0;i<cnt;i++)
	{
		if(query[i].id==-1)
		{
			int p=query[i].page;
			vis[p]=1;
			if(!vis[p-1]&&!vis[p+1])
				cur++;
			if(vis[p-1]&&vis[p+1]) cur--;
		}
		else ans[query[i].id]=cur;
	}//
	for(int i=0;i<q;i++)
		printf("%d\n",ans[i]);
}
