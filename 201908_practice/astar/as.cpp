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
const int maxn=4e5+7;
ll A[maxn<<1],B[maxn<<1];
template<typename T>
void fwt(ll a[], int n, T f) {
    for (int d = 1; d < n; d *= 2)
        for (int i = 0, t = d * 2; i < n; i += t)
            for(int j = 0; j < d; j++)
                f(a[i + j], a[i + j + d]);
}

void OR(ll& a, ll& b) { b += a; }
void rOR(ll& a, ll& b) { b -= a; }
vector<ll> all;
inline int getid(ll x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin();
}
struct Query{
	ll l,r;
}q[maxn];
int val[maxn<<1];
vector<ll> vv,pos;
int N;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
int mx[maxn<<2];
void build(int L=0,int R=N,int o=1)
{
	if(L==R)
	{
		mx[o]=val[L];
		return;
	}
	int mid=L+R>>1;
	build(Lson);
	build(Rson);
	mx[o]=max(mx[lson],mx[rson]);
}
void update(int l,int r,int L=0,int R=N,int o=1)
{
	if(mx[o]==1) return;
	if(L==R)
	{
		mx[o]=sqrt(mx[o]);
		return;
	}
	int mid=L+R>>1;
	if(l<=mid) update(l,r,Lson);
	if(r>mid) update(l,r,Rson);
	mx[o]=max(mx[lson],mx[rson]);
}
int query(int p,int L=0,int R=N,int o=1)
{
	if(L==R)
		return mx[o];
	int mid=L+R>>1;
	if(p<=mid) return query(p,Lson);
	else return query(p,Rson);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1,tmp;i<=n;i++)
	{
		scanf("%d",&tmp);
		A[tmp]++;
	}
	for(int i=1,tmp;i<=n;i++)
	{
		scanf("%d",&tmp);
		B[tmp]++;
	}
	int len=1;
	while(len<=100000) len*=2;
	fwt(A,len,OR);
	fwt(B,len,OR);
	for(int i=0;i<len;i++) A[i]=A[i]*B[i];
	fwt(A,len,rOR);
	ll cur=0;
	for(int i=0;i<len;i++)
	{
		if(!A[i]) continue;
		all.push_back(cur+1);
		all.push_back(cur+A[i]);
		cur+=A[i];
		vv.push_back(i);
		pos.push_back(cur);
	}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		q[i]={l,r};
		all.push_back(r);
		if(l!=0) all.push_back(l);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=0;i<all.size();i++)
		val[i]=vv[lower_bound(pos.begin(),pos.end(),all[i])-pos.begin()];
	N=all.size()-1;
	build();
	for(int i=1;i<=m;i++)
	{
		if(q[i].l==0)
			printf("%d\n",query(getid(q[i].r)));
		else
			update(getid(q[i].l),getid(q[i].r));
	}
}
