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
const int maxn=2e5+7;
struct Node{
	Node *l,*r;
	int id;
	Node(int _id):id(_id),l(NULL),r(NULL){}
};
Node* rt[maxn];
int cur;
int tot;
struct Edge{
	int to,nxt;
}edge[maxn*10];
int cnt;
int arr[maxn*10];
int head[maxn*10];
void init()
{
	cnt=0;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v)
{
	edge[cnt]={v,head[u]};
	head[u]=cnt++;
}
int ins[maxn];
#define Lson L,mid,o->l
#define Rson mid+1,R,o->r
void build(int L,int R,Node* &o)
{
	o=new Node(tot++);
	if(L==R)
	{
		addedge(o->id,L);
		return;
	}
	int mid=L+R>>1;
	build(Lson);
	build(Rson);
	addedge(o->id,o->l->id);addedge(o->id,o->r->id);
}
void update(int p,int l,int r,int L,int R,Node *o)
{
	if(l<=L&&r>=R)
	{
		addedge(ins[p],o->id);
		return;
	}
	int mid=L+R>>1;
	if(l<=mid) update(p,l,r,Lson);
	if(r>mid) update(p,l,r,Rson);
}
void add(int pos,int L,int R,Node* &o,Node* pre)
{
	o=new Node(tot++);
	if(L==R)
	{
		addedge(o->id,ins[pos]);
		return;
	}
	int mid=L+R>>1;
	if(pos<=mid) 
	{
		add(pos,Lson,pre->l);
		o->r=pre->r;
	}
	else 
	{
		add(pos,Rson,pre->r);
		o->l=pre->l;
	}
	addedge(o->id,o->l->id);addedge(o->id,o->r->id);
}
int dfn[maxn*10],low[maxn*10],bel[maxn*10],ti,scc;
stack<int> st;
void dfs(int u)
{
	dfn[u]=low[u]=++ti;
	st.push(u);
	for(int i=head[u];i!=-1;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(!dfn[v])
		{
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!bel[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		scc++;
		while(1)
		{
			int t=st.top();st.pop();
			bel[t]=scc;
			if(t==u) break;
		}
	}
}
ll ans[maxn*10];
ll solve()
{
	for(int i=1;i<=n+cur;i++)
		if(!dfn[i]) dfs(i);
	for(int i=1;i<=n+cur;i++)
		ans[bel[i]]+=arr[i];
	vector<int> deg(scc+1,0);
	for(int i=1;i<tot;i++)
	{
		for(int j=head[i];j!=-1;j=edge[j].nxt)
		{
			int v=edge[j].to;
            if(bel[i]!=bel[v])
				deg[bel[i]]++;
		}
	}
	ll ret=1LL<<60;
	for(int i=1;i<=n+cur;i++)
	{
		if(!deg[bel[i]])
			ret=min(ret,ans[bel[i]]);
	}
	return ret;
}
int main()
{
	init();
	scanf("%d",&n);
	tot=maxn+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		ins[i]=i;
	}
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
			update(x,l,r,1,n,rt[cur]);
		}
		else{
			int val,pos;
			scanf("%d%d",&pos,&val);
			cur++;
			arr[n+cur]=val;
			ins[pos]=n+cur;
			add(pos,1,n,rt[cur],rt[cur-1]);
		}
	}
	printf("%lld\n",solve());

}

