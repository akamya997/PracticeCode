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
const int mod=1e9+7;
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
const int maxn=1e5+7;
int l[maxn],r[maxn];
int dir[maxn];
int ans[maxn];
int rt;
int sz[maxn];
int fa[maxn];
int fi[maxn];
int db(int cur)
{
	if(!cur) return INF;
	int ret1=db(l[cur]);
	int ret2=db(r[cur]);
	sz[cur]=sz[l[cur]]+sz[r[cur]]+1;
	return fi[cur]=min({cur,ret1,ret2});
}
void solve(int cur,int son)
{
	if(cur==-1||dir[cur]!=-1) return;
	if(l[cur]==son)
		dir[cur]=0;
	else dir[cur]=1;
	solve(fa[cur],cur);
}
int tot;
void dfs(int cur)
{
	if(!cur) return;
	if(dir[cur]==0)
	{
		dfs(l[cur]);
		ans[cur]=++tot;
		dfs(r[cur]);
	}
	else{
		dfs(r[cur]);
		ans[cur]=++tot;
		dfs(l[cur]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		tot=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) sz[i]=0,fa[i]=-1,dir[i]=-1;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i]>>r[i];
			fa[l[i]]=fa[r[i]]=i;
		}
		for(int i=1;i<=n;i++)
			if(fa[i]==-1)
			{
				rt=i;
				break;
			}
		db(rt);
		for(int i=1;i<=n;i++)
		{
			if(dir[i]==-1)
			{
				if(sz[l[i]]<sz[r[i]])
					dir[i]=0;
				else if(sz[l[i]]>sz[r[i]]) dir[i]=1;
				else{
					if(fi[l[i]]<fi[r[i]]) dir[i]=0;
					else dir[i]=1;
				}
				solve(fa[i],i);
			}
		}
		dfs(rt);
		ll op=0;
		ll factor=1;
		for(int i=1;i<=n;i++)
		{
			factor=factor*233%mod;
			op=(op+(ans[i]^i)*factor%mod)%mod;
		}
		cout<<op<<endl;
	}
}
