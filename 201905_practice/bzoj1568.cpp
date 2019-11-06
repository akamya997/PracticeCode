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
typedef double ld;
const ld eps=1e-8;
const int maxn=5e4+7;
const int n=5e4;
struct Line{
	ld b,p;
	bool isl;
}seg[maxn*4];
ld getval(Line a,int d)
{
	if(!a.isl) return 0;
	return (d-1)*a.p+a.b;
}
ld intersec(Line a,Line b)
{
	return (a.b-b.b)/(b.p-a.p);
}
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
void update(Line a,int L=1,int R=n,int o=1)
{
	if(!seg[o].isl)
	{
		seg[o]=a;
		return;
	}
	if(getval(a,L)>getval(seg[o],L)&&getval(a,R)>getval(seg[o],R))
	{
		seg[o]=a;
		return;
	}
	if(getval(a,L)<getval(seg[o],L)&&getval(a,R)<getval(seg[o],R))
		return;
	ld pos=intersec(a,seg[o]);
	int mid=L+R>>1;
	if(pos<mid)
	{
		if(getval(a,R)>getval(seg[o],R))
		{
			update(seg[o],Lson);
			seg[o]=a;
		}
		else{
			update(a,Lson);
		}
	}
	else{
		if(getval(a,L)>getval(seg[o],L))
		{
			update(seg[o],Rson);
			seg[o]=a;
		}
		else{
			update(a,Rson);
		}
	}
}
ld query(int x,int L=1,int R=n,int o=1)
{
	if(L==R)
		return getval(seg[o],L);
	int mid=L+R>>1;
	if(x<=mid) return max(getval(seg[o],x),query(x,Lson));
	else return max(getval(seg[o],x),query(x,Rson));
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		char op[10];
		scanf("%s",op);
		if(op[0]=='P')
		{
			Line cur;
			cur.isl=1;
			scanf("%lf%lf",&cur.b,&cur.p);
			update(cur);
		}
		else{
			int x;
			scanf("%d",&x);
			printf("%d\n",(int)(query(x)/100+eps));
		}
	}
}
