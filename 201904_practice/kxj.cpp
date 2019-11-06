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
int n;
const int maxn=1e5+7;
struct Node{
	Node *l,*r;
	int id;
	Node():id(0),l(NULL),r(NULL){}
};
Node* rt[maxn];
int cur;
int tot;
struct Edge{
	int to,nxt;
}edge[maxn*10];
int cnt;
int arr[maxn*2];
int head[maxn*2];
void init()
{
	cnt=0;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v)
{
	edge[cnt]={v,head[u]};
	head[u]=cnt++;
	assert(cnt<maxn*4);
}
#define Lson L,mid,o->l
#define Rson mid+1,R,o->r
void build(int L,int R,Node* o)
{
	o->id=tot++;
	if(L==R)
	{
		addedge(o->id,L);
		return;
	}
	int mid=L+R>>1;
	o->l=new Node();
	build(Lson);
	o->r=new Node();
	build(Rson);
	addedge(o->id,o->l->id);addedge(o->id,o->r->id);
}
void update(int p,int l,int r,int L,int R,Node *o)
{
	if(l<=L&&r>=R)
	{
		addedge(p,o->id);
		return;
	}
	int mid=L+R>>1;
	if(l<=mid) update(p,l,r,Lson);
	if(r>mid) update(p,l,r,Rson);
}
void add(int pos,int L,int R,Node* &o,Node *pre)
{
	o->id=++tot;
	o=new Node(++tot);
	if(L==R) 
	{
		addedge(o->id,n+cur);
		return;
	}
	int mid=L+R>>1;
	if(pos<=mid) 
	{
		o->l=new Node();
		add(pos,Lson,pre->l);
		o->r=pre->r;
	}
	else 
	{
		add(pos,Rson,pre->r);
		o->l=pre->l;
	}
}
int main()
{
	init();
	scanf("%d",&n);
	tot=maxn+1;
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	rt[0]=new Node();
	build(1,n,rt[0]);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int op;
		scanf("%d",&op);
		if(op)
		{
			int x,l,r;
			scanf("%d%d%d",&x,&l,&r);
			update(p,l,r,1,n,rt[cur]);
		}
		else{
			int val,pos;
			scanf("%d%d",&pos,&val);
			rt[++cur]=new Node();
			arr[n+cur]=val;
			add(pos,1,n,rt[cur],rt[cur-1]);
		}
	}

}
