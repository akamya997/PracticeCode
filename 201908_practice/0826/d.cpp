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
const int maxn=3e5+7;
struct node{
	int l,r,id;
	bool operator<(const node& a)const{
		if(l==a.l) return r<a.r;
		return l<a.l;
	}
}p[maxn];
vector<int> G[maxn];
int ans[maxn];
int deg[maxn];
int n,m;
int topo[maxn];
bool toposort()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(!deg[i])
			q.push(i);
	}
	int cur=0;
	while(!q.empty())
	{
		auto u=q.front();
		q.pop();
		topo[cur++]=u;
		for(auto v:G[u])
		{
			deg[v]--;
			if(!deg[v]) q.push(v);
		}
	}
	return cur==n;
}
struct st{
	int id,val;
	bool operator<(const st& a)const{
		return val<a.val;
	}
};
multiset<st> s;
void dfs(int u)
{
	for(auto v:G[u])
	{
		p[v].l=max(p[v].l,p[u].l+1);
		dfs(v);
		p[u].r=min(p[v].r-1,p[u].r);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].l,&p[i].r);
		p[i].id=i;
	}
	for(int i=0,u,v;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		deg[v]++;
	}
	if(!toposort())
		puts("-1");
	else{
		for(int i=n-1;i>=0;i--)
		{
			int c=topo[i];
			for(auto v:G[c])
				p[c].r=min(p[c].r,p[v].r-1);
		}
		sort(p+1,p+1+n);
		bool ok=1;
		int pos=1;
		for(int i=1;i<=n;i++)
		{
			while(pos<=n&&p[pos].l<=i)
			{
				s.insert(st{p[pos].id,p[pos].r});
				pos++;
			}
			if(s.empty()||(*s.begin()).val<i)
			{
				ok=0;break;
			}
			ans[i]=(*s.begin()).id;
			s.erase(s.begin());
		}
		if(!ok) puts("-1");
		else {
			for(int i=1;i<=n;i++)
				printf("%d\n",ans[i]);
		}
	}
}
