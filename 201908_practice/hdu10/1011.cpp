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
const int maxn=3e5+7;
int arr[maxn];
int pre[maxn];
int lmost[maxn],rmost[maxn];
int fa[maxn],lc[maxn],rc[maxn];
int n,k;
ll solve(int L,int R,int rt)
{
	if(rt==-1||L>R) return 0;
	ll ret=0;
	if(rt-L>R-rt)
	{
		for(int i=R;i>=rt;i--)
		{
			int l=lmost[i];
			l=max(l,L);
			if(l>rt) continue;
			ret+=max(0,min(k+i+1-arr[rt],rt)-l+1);
		}
	}
	else {
		for(int i=L;i<=rt;i++)
		{
			int r=rmost[i];
			r=min(r,R);
			if(r<rt) continue;
			ret+=max(0,r-max(i-1+arr[rt]-k,rt)+1);
		}
	}
	ret+=solve(L,rt-1,lc[rt]);
	ret+=solve(rt+1,R,rc[rt]);
	return ret;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			fa[i]=-1;
			lc[i]=rc[i]=-1;
			scanf("%d",&arr[i]);
			pre[i]=0;
		}
		int cur=0;
		for(int i=1;i<=n;i++)
		{
			cur=max(cur,pre[arr[i]]);
			lmost[i]=cur+1;
			pre[arr[i]]=i;
		}
		for(int i=1;i<=n;i++) pre[i]=n+1;
		cur=n+1;
		for(int i=n;i>=1;i--)
		{
			cur=min(cur,pre[arr[i]]);
			rmost[i]=cur-1;
			pre[arr[i]]=i;
		}
		stack<int> st;
		for (int i = 1; i <= n; i++)
		{
			int last = -1;
			while (!st.empty() && arr[i] > arr[st.top()])
				last = st.top(), st.pop();
			if (!st.empty())
				rc[st.top()] = i, fa[i] = st.top();
			lc[i] = last;
			if (~last)
				fa[last] = i;
			st.push(i);
		}
		int root = -1;
		for (int i = 1; i <= n; i++)
			if (!~fa[i])
				root = i;
		printf("%lld\n",solve(1,n,root));
	}
}
