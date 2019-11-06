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
const int maxn=1e5+7;
namespace sgt{
#define Lson L,mid,lson[o]
#define Rson mid+1,R,rson[o]
	int rt[maxn];
	int cnt[maxn<<8],lson[maxn<<8],rson[maxn<<8];
	int tot;
	void update(int p,int L,int R,int& o)
	{
		if(!o) o=++tot;
		if(L==R)
		{
			cnt[o]++;
			return;
		}
		int mid=L+R>>1;
		if(p<=mid) update(p,Lson);
		else update(p,Rson);
		cnt[o]=cnt[lson[o]]+cnt[rson[o]];
	}
	int query(int l,int r,int L,int R,int o)
	{
		if(!o) return 0;
		if(l<=L&&r>=R)
			return cnt[o];
		int mid=L+R>>1;
		int ret=0;
		if(l<=mid) ret+=query(l,r,Lson);
		if(r>mid) ret+=query(l,r,Rson);
		return ret;
	}
};
void add(int x,int y)
{
	while(x<maxn)
	{
		sgt::update(y,1,maxn-1,sgt::rt[x]);
		x+=x&-x;
	}
}
int query(int x,int y1,int y2)
{
	int ret=0;
	while(x>0)
	{
		ret+=sgt::query(y1,y2,1,maxn-1,sgt::rt[x]);
		x-=x&-x;
	}
	return ret;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	while(m--)
	{
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%d\n",query(x2,y1,y2)-query(x1-1,y1,y2));
	}

}
