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
const int maxn=5e5+7;
long long dp[maxn];
long long pre[maxn];
int deq[maxn];
int n,m;
long long calc(int k)
{
	return dp[k]+pre[k]*pre[k];
}
void upd(int i,int j)
{
	dp[i]=dp[j]+(pre[i]-pre[j])*(pre[i]-pre[j])+m;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1,temp;i<=n;i++)
		{
			scanf("%d",&temp);
			pre[i]=pre[i-1]+temp;
		}
		int head=0,tail=0;
		deq[++tail]=0;
		for(int i=1;i<=n;i++)
		{
			while(head+1<tail&&(calc(deq[head+2])-calc(deq[head+1]))<=2*pre[i]*(pre[deq[head+2]]-pre[deq[head+1]])) head++;
			upd(i,deq[head+1]);
			while(head+1<tail&&(calc(i)-calc(deq[tail]))*(pre[deq[tail]]-pre[deq[tail-1]])<=(calc(deq[tail])-calc(deq[tail-1]))*(pre[i]-pre[deq[tail]])) tail--;
			deq[++tail]=i;
		}
		printf("%lld\n",dp[n]);
	}
}
