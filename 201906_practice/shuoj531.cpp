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
const int maxn=1e5+7;
vector<int> G[maxn];
struct Trie{
	Trie* ch[2];
	int sz;
	Trie():sz(0){memset(ch,0,sizeof(ch));}
};
int szof(Trie* cur){return cur?cur->sz:0;}
Trie* o;
Trie* rt[maxn];
int tot,dfn[maxn<<2],st[maxn];
void Insert(int cur,Trie* &p,Trie* pre)
{
	if(!p) p=new Trie();
	Trie *tmp=p;
	for(int i=31;i>=0;i--)
	{
		int v=(cur>>i)&1;
		tmp->ch[v]=new Trie();
		if(!pre->ch[v^1]) pre->ch[v^1]=new Trie();
		tmp->ch[v^1]=pre->ch[v^1];
		tmp->sz=szof(tmp->ch[0])+szof(tmp->ch[1])+1;
		tmp=tmp->ch[v];
		if(!pre->ch[v]) pre->ch[v]=new Trie();
		pre=pre->ch[v];
	}
	tmp->sz=szof(pre)+1;
}
int val[maxn];
int dep[maxn];
int far[maxn];
void dfs(int u,int fa=-1)
{
	Insert(val[u],rt[u],fa==-1?o:rt[fa]);
	far[u]=fa;
	dep[u]=(fa==-1?1:dep[fa]+1);
	st[u]=++tot;
	dfn[tot]=u;
	for(auto &v:G[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		dfn[++tot]=u;
	}
}
int dp[maxn][32];
void rmq()
{
	for (int i = 1; i <= tot; i++)
        dp[i][0] = dfn[i];

    for (int j = 1; (1 << j) <= tot; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= tot; i++)
        {
			if(dep[dp[i][j-1]]<dep[dp[i+(1<<(j-1))][j-1]])
				dp[i][j]=dp[i][j-1];
			else dp[i][j]=dp[i+(1<<(j-1))][j-1];
		}
    }
}
int LCA(int u,int v)
{
	u=st[u],v=st[v];
	if(u>v) swap(u,v);
	int k=31-__builtin_clz(v-u+1);
	if(dep[dp[u][k]]<dep[dp[v-(1<<k)+1][k]])
		return dp[u][k];
	return dp[v-(1<<k)+1][k];
}
int solve(int u,int v,int x)
{
	int lca=LCA(u,v);
	int ret=0;
	Trie *p=rt[u],*q=rt[v],*r=rt[lca],*l=(far[lca]==-1?o:rt[far[lca]]);
	for(int i=31;i>=0;i--)
	{
		int cur=(x>>i)&1;
		int cnt=szof(p?p->ch[cur^1]:p)+szof(q?q->ch[cur^1]:q)-szof(r?r->ch[cur^1]:r)-szof(l?l->ch[cur^1]:l);
		dbg(i,cnt);
		if(cnt)
		{
			ret+=(cur^1)*(1<<i);
			if(p)
				p=p->ch[cur^1];
			if(q)
				q=q->ch[cur^1];
			if(r)
				r=r->ch[cur^1];
			if(l)
				l=l->ch[cur^1];
		}
		else{
			ret+=cur*(1<<i);
			if(p)
				p=p->ch[cur];
			if(q)
				q=q->ch[cur];
			if(r)
				r=r->ch[cur];
			if(l)
				l=l->ch[cur];
		}
	}
	return ret;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		tot=0;
		memset(rt,0,sizeof(rt));
		int n,q;
		o=new Trie();
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&val[i]);
		for(int i=1,u,v;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1);
		rmq();
		while(q--)
		{
			int u,v,x;
			scanf("%d%d%d",&u,&v,&x);
			printf("%d\n",solve(u,v,x));
		}
	}
}
