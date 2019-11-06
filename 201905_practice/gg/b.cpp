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
const int mod=192600817;
ll f[maxn];
int getid(int x,int y)
{
	return x*4+y;
}
ll pre[maxn];
void db()
{
	f[0]=1;
	f[1]=1;
	for(int i=2;i<maxn;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	pre[0]=1,pre[1]=2;
	for(int i=2;i<maxn;i++)
	{
		pre[i]=(pre[i-1]+f[i]*f[i]%mod)%mod;
	}
}
int main()
{
	db();
	int q;while(~scanf("%d",&q))
	{
		while(q--)
		{
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
			int l=getid(y1,y2),r=getid(x1,x2);
			if(l>r) swap(l,r);
			printf("%lld\n",(pre[r]-(l==0?0:pre[l-1])+mod)%mod);
		}
	}
}
