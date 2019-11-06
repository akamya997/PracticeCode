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
const int maxn=1e5+7;
const double eps=1e-9;
ll sum[maxn<<6];int cnt[maxn<<6];
int lson[maxn<<6],rson[maxn<<6];
int rt[maxn*2];
int tot;
const int mx=100000;
#define Lson lson[o],L,mid
#define Rson rson[o],mid+1,R
struct node{
	ll a,b;
};
typedef node PII;
void update(int val,int pre,int &o,int L=1,int R=mx)
{
	o=++tot;
	sum[o]=sum[pre]+val,cnt[o]=cnt[pre]+1;
	if(L==R)
		return;
	int mid=L+R>>1;
	if(val<=mid)
	{
		rson[o]=rson[pre];
		update(val,lson[pre],Lson);
	}
	else{
		lson[o]=lson[pre];
		update(val,rson[pre],Rson);
	}
}
PII query(int val,int pre,int o,int L=1,int R=mx)
{
	if(!o) return node{0,0};
	if(val>=R)
		return node{sum[o]-sum[pre],cnt[o]-cnt[pre]};
	int mid=L+R>>1;
	PII ret=query(val,lson[pre],Lson);
	if(val>mid){
		PII tmp=query(val,rson[pre],Rson);
		ret.a+=tmp.a;
		ret.b+=tmp.b;
	}
	return ret;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1,tmp;i<=n;i++)
	{
		scanf("%d",&tmp);
		update(tmp,rt[i-1],rt[i]);
	}
	int l,r,x,y;
	while(q--)
	{
		scanf("%d%d%d%d",&l,&r,&x,&y);
		PII all=query(mx,rt[l-1],rt[r]);
		double eve=1.0*all.a/y;
		double tar=eve*x;
		double L=0,R=mx;
		double ans;
		while(R-L>eps)
		{
			double realmid=(L+R)/2;
			PII cur=query((int)realmid,rt[l-1],rt[r]);
			ll cutcnt=all.b-cur.b;
			cur.a+=cutcnt*(int)(realmid);
			ll cut=all.a-cur.a;
			double curcut=cut-cutcnt*(realmid-(int)realmid);
			if(eps<tar-curcut)
				R=realmid;
			else L=realmid;
		}
		printf("%.15f\n",L);
	}
}
