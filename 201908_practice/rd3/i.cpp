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
const int maxn=5e5+7;
struct Seg{
	int l,r;
}seg[maxn];
vector<int> all;
inline int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
int mx[maxn<<2];
int lz[maxn<<2];
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
inline void pushdown(int o)
{
	if(lz[o])
	{
		lz[lson]+=lz[o];
		lz[rson]+=lz[o];
		mx[lson]+=lz[o];
		mx[rson]+=lz[o];
		lz[o]=0;
	}
}
void update(int l,int r,int val,int L=1,int R=all.size(),int o=1)
{
	if(l<=L&&r>=R)
	{
		mx[o]+=val;
		lz[o]+=val;
		return;
	}
	pushdown(o);
	int mid=L+R>>1;
	if(l<=mid) update(l,r,val,Lson);
	if(r>mid) update(l,r,val,Rson);
	mx[o]=max(mx[lson],mx[rson]);
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>seg[i].l>>seg[i].r;
		seg[i].l++;
		all.push_back(seg[i].l);
		all.push_back(seg[i].r);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=0;i<n;i++)
	{
		seg[i].l=getid(seg[i].l);
		seg[i].r=getid(seg[i].r);
	}
	for(int i=0;i<n;i++)
		update(seg[i].l,seg[i].r,1);
	cout<<mx[1]<<endl;
}
