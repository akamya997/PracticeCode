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
const int maxn=5e5+7;
struct Trie{
	int sz;
	Trie* ch[2];
	Trie(){sz=0,ch[0]=NULL,ch[1]=NULL;}
};
int szof(Trie* cur){return cur?cur->sz:0;}
Trie *pre,*las;
ll ans;
ll ry[60][2];
void Insert(int cur,Trie* rt,int flag)
{
	Trie* p=rt,*pp=las;
	for(int i=31;i>=0;i--)
	{
		int val=(cur>>i)&1;
		if(flag)
		{
		//	dbg(i,val,szof(pp->ch[val^1]));
			ry[i][val]+=szof(pp->ch[val^1]);
		}
		p->sz++;
		if(!(p->ch[val]))
			p->ch[val]=new Trie();
		p=p->ch[val];
		if(flag)
			pp=pp->ch[val];
	}
	p->sz++;
}
void del(int cur,Trie* pp,Trie* rt)
{
	Trie* p=rt;
	for(int i=31;i>=0;i--)
	{
		int val=(cur>>i)&1;
		if(pp)
			ry[i][val^1]-=szof(pp->ch[val^1]);
		p->sz--;
		p=p->ch[val];
		if(pp)
			pp=pp->ch[val];
	}
	p->sz--;
}
int arr[maxn];
void solve(int cur)
{
	Trie *l=pre,*r=las;
	for(int i=31;i>=0;i--)
	{
		int val=(cur>>i)&1;
		ans+=ry[i][val];
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(ry,0,sizeof(ry));
		pre=new Trie();
		las=new Trie();
		int n;
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			Insert(arr[i],las,0);
		}
		for(int i=0;i<n-1;i++)
		{
			del(arr[i],pre,las);
			solve(arr[i]);
	//		dbg("del");
	//	for(int i=0;i<5;i++)
	//		dbg(i,ry[i][0],ry[i][1]);
			Insert(arr[i],pre,1);
	//		dbg("Ins");
	//	for(int i=0;i<5;i++)
	//		dbg(i,ry[i][0],ry[i][1]);
		}
		printf("%lld\n",ans);

	}
}
