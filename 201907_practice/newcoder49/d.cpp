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
const int mod=1e9+7;
const int maxn=1e5+7;
struct OP{
	int tp,l,r;
}op[maxn];
ll cnt[maxn];
ll arr[maxn];
ll t[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&op[i].tp,&op[i].l,&op[i].r);
		if(op[i].tp==2)
		{
			op[i].l--;
			op[i].r--;
		}
	}
	ll cur=1;
	for(int i=m-1;i>=0;i--)
	{
		cur=(cur+cnt[i])%mod;
		t[i]=cur;
		if(op[i].tp==2)
		{
			cnt[op[i].r]=(cnt[op[i].r]+cur)%mod;
			cnt[op[i].l-1]=(cnt[op[i].l-1]-cur+mod)%mod;
		}
	}
	for(int i=0;i<m;i++)
	{
		if(op[i].tp==1)
		{
			arr[op[i].l]=(arr[op[i].l]+t[i])%mod;
			arr[op[i].r+1]=(arr[op[i].r+1]-t[i]+mod)%mod;
		}
	}
	cur=0;
	for(int i=1;i<=n;i++)
	{
		cur=(cur+arr[i])%mod;
		printf("%lld ",cur);
	}
	puts("");

}
