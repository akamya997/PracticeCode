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
typedef unsigned int uint;
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
template<typename T,int D>
struct Base{
	T a[D];
    int m;
	Base(){m = 0, memset(a, 0, sizeof(a));}
	void clear(){m = 0, memset(a, 0, sizeof(a));}
	inline void ful()
	{
		m=D;
		for(int i=0;i<D;i++)
			a[i]=1ll<<i;
	}
	inline bool ins(T x)
	{
		for(int i = D - 1; ~i; --i)
			if(x >> i & 1)
			{
				if(a[i]) x ^= a[i];
				else{
					m++;
					a[i] = x;return 1;
				}
			}
		return 0;
	}
};
inline Base<uint,32> Merge(Base<uint,32> A,Base<uint,32> B)
{
	if(A.m==32) return B;
	if(B.m==32) return A;
	Base<uint,32> All,C,D;
	All=A;
	D.ful();
	for(int i=31;i>=0;i--)
	{
		if(B.a[i]){
			uint v=B.a[i],k=0;
			bool can=1;
			for(int j=31;j>=0;j--)
			{
				if(v&(1ll<<j))
				{
					if(All.a[j])
					{
						v^=All.a[j];
						k^=D.a[j];
					}
					else{
						can=0;
						All.a[j]=v;
						D.a[j]=k;
						break;
					}
				}
			}
			if(can)
			{
				uint v=0;
				for(int j=31;j>=0;j--)
				{
					if(k>>j&1)
						v^=A.a[j];
				}
				C.ins(v);
			}
		}
	}
	return C;
}
const int maxn=50005;
Base<uint,32> arr[maxn];
Base<uint,32> sum[maxn<<4];
int n,m;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
inline void pushup(int o)
{
	sum[o]=Merge(sum[lson],sum[rson]);
}
void build(int L=1,int R=n,int o=1)
{
	if(L==R)
	{
		sum[o]=arr[L];
		return;
	}
	int mid=L+R>>1;
	build(Lson);
	build(Rson);
	pushup(o);
}
bool query(int l,int r,uint x,int L=1,int R=n,int o=1)
{
	if(l<=L&&r>=R)
	{
		for(int i=31;i>=0;i--)
			if((x^sum[o].a[i])<x) x^=sum[o].a[i];
		return x==0;
	}
	int mid=L+R>>1;
	bool ret=1;
	if(l<=mid) ret&=query(l,r,x,Lson);
	if(r>mid) ret&=query(l,r,x,Rson);
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		uint tmp;
		int k;
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d",&tmp);
			arr[i].ins(tmp);
		}
	}
	build();
	while(m--)
	{
		int l,r;
		uint x;
		scanf("%d%d%u",&l,&r,&x);
		if(query(l,r,x)) puts("YES");
		else puts("NO");
	}
}

