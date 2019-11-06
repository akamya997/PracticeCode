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
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
const int maxn=1e5+700;
struct Edge{
	int to;
	ll w;
};
template<typename T,int D>
struct Base{
	T a[D];
    int m;
	Base(){m = 0, memset(a, 0, sizeof(a));}
	void clear(){m = 0, memset(a, 0, sizeof(a));}
	bool ins(T x)
	{
		for(int i = D - 1; ~i; --i)
			if(x >> i & 1)
			{
				if(a[i]) x ^= a[i];
				else{
					m++;
					a[i] = x;return 1;
				}
			}
		return 0;
	}
};
vector<Edge> G[maxn];
bool vis[maxn];
ll val[maxn];
Base<ll,63> cur;
void dfs(int u,int fa=-1,ll vv=0)
{
	vis[u]=1;
	val[u]=vv;
	for(auto &e:G[u])
	{
		int v=e.to;
		if(v==fa) continue;
		if(vis[v])
			cur.ins(val[v]^val[u]^e.w);
		else dfs(v,u,vv^e.w);
	}
}
int main()
{
	int T;
	int kas=0;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++) G[i].clear(),vis[i]=val[i]=0;
		cur.clear();
		for(int i=0,u,v;i<m;i++)
		{
			ll w;
			scanf("%d%d%lld",&u,&v,&w);
			G[u].push_back(Edge{v,w});
			G[v].push_back(Edge{u,w});
		}
		dfs(1);
		ll ans=0;
		for(int i=62;i>=0;i--)
			//if(ans^cur.a[i]>ans) ans^=cur.a[i];
			ans=max(ans,ans^cur.a[i]);
		printf("Case #%d: %lld\n",++kas,ans);
	}
}
