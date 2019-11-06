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
inline int rnd()
{
	static int seed=2333;
	return seed=(int)seed*482711LL%2147483647;
}
struct Treap{
	Treap *l,*r;
	int id,val,prior;
	Treap(int _id,int _val):id(_id),val(_val),l(NULL),r(NULL),prior(rnd()){}
};
typedef Treap* pt;
void split(pt o,int k,pt &l,pt &r)
{
	if(!o) l=r=NULL;
	else if(o->val>=k) split(o->l,k,l,o->l),r=o;
	else split(o->r,k,o->r,r),l=o;
}
void merge(pt &o,pt l,pt r)
{
	if(!l||!r) o=l?l:r;
	else if(l->prior>r->prior) merge(l->r,l->r,r),o=l;
	else merge(r->l,l,r->l),o=r;
}
pt root;
int Insert(int id,int val)
{
	pt l,r;
	split(root,val,l,r);
	pt lp=l,rp=r;
	int ret=0;
	if(lp&&rp)
	{
		while(lp->r) lp=lp->r;
		while(rp->l) rp=rp->l;
		if(abs(lp->val-val)<=abs(rp->val-val)) ret=lp->id;
		else ret=rp->id;
	}
	else{
		if(!lp)
		{
			while(rp->l) rp=rp->l;
			ret=rp->id;
		}
		if(!rp)
		{
			while(lp->r) lp=lp->r;
			ret=lp->id;
		}
	}
	merge(l,l,new Treap(id,val));
	merge(root,l,r);
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin>>n&&n)
	{
		root=new Treap(1,1000000000);
		for(int i=0;i<n;i++)
		{
			int id,val;
			cin>>id>>val;
			cout<<id<<" "<<Insert(id,val)<<endl;
		}
	}
}
