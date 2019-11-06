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
const int maxn=2e5+7;
int sz;
int fa[maxn];
void init()
{
	for(int i=0;i<maxn;i++) fa[i]=i;
}
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	fa[y]=x;
}
struct Seg{
	int l,r;
	bool operator<(const Seg a)const{
		if(r==a.r) return l<a.l;
		return r<a.r;
	}
}seg[maxn];
int pos[maxn];
int p[maxn],q[maxn];
char ans[maxn];
int main()
{
	init();
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1,tmp;i<=n;i++)
	{
		scanf("%d",&tmp);
		pos[i]=tmp;
		p[tmp]=i;
	}
	for(int i=1,tmp;i<=n;i++)
	{
		scanf("%d",&tmp);
		q[tmp]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int l=min(p[i],q[i]),r=max(p[i],q[i]);
		seg[i]={l,r};
	}
	sort(seg+1,seg+n+1);
	int l=1,r=0;
	for(int i=1;i<=n;i++)
	{
		if(seg[i].l>r)
		{
			for(int j=l+1;j<=r;j++)
				Union(j,j-1);
			l=seg[i].l,r=seg[i].r;
		}
		else
			r=seg[i].r;
	}
	for(int j=l+1;j<=r;j++)
		Union(j,j-1);
	char cur='a'-1;
	for(int i=1;i<=n;i++)
	{
		dbg(i,pos[i],Find(i));
		if(Find(i)!=Find(i-1))
		{
			cur++;
			if(cur>'z') cur='z';
		}
		ans[pos[i]]=cur;
	}
	if(cur-'a'+1<k)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%c",ans[i]);
	puts("");
}
