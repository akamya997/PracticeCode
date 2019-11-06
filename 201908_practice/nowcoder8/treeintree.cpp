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
int tot;
const int maxn=1e5+7;
#define Lson L,mid,lson[o]
#define Rson mid+1,R,rson[o]
namespace SGT{
	int cnt[maxn<<6];
	int rt[maxn];
	int lson[maxn<<6],rson[maxn<<6];
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
		if(l<=r&&r>=R)
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
		SGT::update(y,1,maxn-1,SGT::rt[x]);
		x+=x&-x;
	}
}
int query(int x,int y)
{
	int ret=0;
	while(x>0)
	{
		ret+=SGT::query(1,y,1,maxn-1,SGT::rt[x]);
		x-=x&-x;
	}
	return ret;
}
struct Point{
	int x,y;
}p[maxn];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		add(p[i].x,p[i].y);
	}
	while(q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int ans=query(x2,y2)+query(x1-1,y1-1)-query(x1-1,y2)-query(x2,y1-1);
		printf("%d\n",ans);
	}
}
