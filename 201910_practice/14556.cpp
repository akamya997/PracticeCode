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
struct Seg{
	int l,r,id,v;
	bool operator<(const Seg& a)const{
		if(l==a.l) return r>a.r;
		return l<a.l;
	}
}seg[maxn];
int val[maxn];
int cur=0;
vector<int> G[maxn];
int n;
void build(int R,int fa)
{
	cur++;
	while(seg[cur].r<=R&&cur<=n)
	{
		G[fa].push_back(seg[cur].id);
		build(seg[cur].r,seg[cur].id);
	}
}
vector<ll> t1,t2;
inline void Merge(multiset<ll> &a,multiset<ll> &b)
{
	t1.clear();t2.clear();
	int cnt=b.size();
	int cc=cnt;
	while(cc--)
	{
		ll v1=*a.rbegin(),v2=*b.rbegin();
		t1.push_back(v1);
		t2.push_back(v2);
		a.erase(a.find(v1));
		b.erase(b.find(v2));
	}
	for(int i=0;i<cnt;i++)
		a.insert(t1[i]+t2[i]);
}
multiset<ll> ret[maxn];
int dfs(int u)
{
	int nn=u;
	for(auto v:G[u])
	{
		int rr=dfs(v);
		if(ret[rr].size()>ret[nn].size())
		{
			Merge(ret[rr],ret[nn]);
			nn=rr;
		}
		else{
			Merge(ret[nn],ret[rr]);
		}
	}
	ret[nn].insert(val[u]);
	return nn;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&seg[i].l,&seg[i].r,&seg[i].v);
		val[i]=seg[i].v;
		seg[i].id=i;
	}
	seg[0]={0,1000001,0,0};
	sort(seg+1,seg+1+n);
	build(1000001,0);
	int aaaa=dfs(0);
	multiset<ll> ans=ret[aaaa];
	ll cans=0;
	vector<ll> op;
	while(ans.size())
	{
		ll tmp=*ans.rbegin();
		cans+=tmp;
		op.push_back(cans);
		ans.erase(ans.find(tmp));
	}
	while(op.size()<n) op.push_back(op.back());
	for(int i=1;i<=n;i++)
		printf("%lld%c",op[i-1],i==n?'\n':' ');
}
