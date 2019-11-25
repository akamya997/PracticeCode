#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
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
const int maxn=1e4+7;
vector<int> opponent[maxn];
int mp[maxn],gp[maxn],bye[maxn],match[maxn],game[maxn];
int a[20];
bool vis[maxn];
int n,m;
inline int getmp(int x)
{
	return mp[x]+bye[x]*3;
}
inline int getgp(int x)
{
	return gp[x]+bye[x]*6;
}
inline void check(PII &ret)
{
	if(3*ret.first<ret.second) ret=make_pair(1,3);
	ll g=__gcd(ret.first,ret.second);
	ret.first/=g;
	ret.second/=g;
}
inline PII getmw(int x)
{
	PII ret=make_pair(getmp(x),3*(match[x]+bye[x]));
	check(ret);
	return ret;
}
inline PII getgw(int x)
{
	PII ret=make_pair(getgp(x),3*(game[x]+bye[x]*2));
	check(ret);
	return ret;
}
void add(PII &a,PII b)
{
	PII tmp;
	ll g=__gcd(a.second,b.second);
	tmp.second=a.second/g*b.second;
	tmp.first=a.first*(b.second/g)+b.first*(a.second/g);
	g=__gcd(tmp.first,tmp.second);
	tmp.first/=g;
	tmp.second/=g;
	a=tmp;
}
inline PII getomw(int x)
{
	if(!match[x]) return make_pair(1,3);
	PII ret=make_pair(0,1);
	for(auto u:opponent[x])
		add(ret,getmw(u));
	int sz=opponent[x].size();
	ret.second*=sz;
	check(ret);
	return ret;
}
inline PII getogw(int x)
{
	if(!match[x]) return make_pair(1,3);
	PII ret=make_pair(0,1);
	for(auto u:opponent[x])
		add(ret,getgw(u));
	int sz=opponent[x].size();
	ret.second*=sz;
	check(ret);
	return ret;
}
void calc()
{
	for(int i=1;i<=n;i++)
	{
		printf("%d ",getmp(i));
		PII omw=getomw(i);
		assert(omw.first>=0&&omw.second>=0);
		printf("%lld/%lld ",omw.first,omw.second);
		PII gw=getgw(i);
		assert(gw.first>=0&&gw.second>=0);
		printf("%lld/%lld ",gw.first,gw.second);
		PII ogw=getogw(i);
		assert(ogw.first>=0&&ogw.second>=0);
		printf("%lld/%lld\n",ogw.first,ogw.second);
	}
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++) 
	{
		opponent[i].clear();
		mp[i]=0;
		gp[i]=0;
		match[i]=0;
		game[i]=0;
		bye[i]=0;
	}
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int j=1;j<=a[i];j++)
		{
			int p1,p2,w1,w2,d;
			scanf("%d%d%d%d%d",&p1,&p2,&w1,&w2,&d);
			opponent[p1].push_back(p2);
			opponent[p2].push_back(p1);
			match[p1]++;
			match[p2]++;
			game[p1]+=w1+w2+d;
			game[p2]+=w1+w2+d;
			vis[p1]=vis[p2]=1;
			gp[p1]+=d;
			gp[p2]+=d;
			gp[p1]+=w1*3;
			gp[p2]+=w2*3;
			if(w1>w2)
				mp[p1]+=3;
			else if(w2>w1)
				mp[p2]+=3;
			else{
				mp[p1]++;
				mp[p2]++;
			}
		}
		for(int i=1;i<=n;i++)
			if(!vis[i])
				bye[i]++;
		printf("Round %d\n",i);
		calc();

	}

}
int main()
{
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
}
