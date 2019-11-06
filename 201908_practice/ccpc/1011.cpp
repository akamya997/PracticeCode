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
const ll mod=1LL<<32;
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
unsigned int arr[maxn];
int block[maxn];
unsigned int ans[maxn];
struct Query{
	int l,r,id;
	inline bool operator<(const Query& a)const{
		if(block[l]==block[a.l]) return r<a.r;
		return l<a.l;
	}
}query[maxn];
const int MAXN=1e7+7;
bitset<MAXN> vis;
int mu[MAXN];
int tot;
int prime[MAXN/12];
inline void db()
{
	mu[1]=1;
	for(int i=2;i<MAXN;i++)
	{
		if(!vis[i])
		{
			prime[tot++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<tot;j++)
		{
			if(i*prime[j]>=MAXN) break;
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				mu[i*prime[j]]=0;
				break;
			}
			mu[i*prime[j]]=-mu[i];
		}
	}
}
vector<unsigned int> factor[maxn];
unsigned int cur;
unsigned int sum[MAXN];
inline void add(int x)
{
	for(auto &p:factor[x])
	{
		int dt=arr[x]/p;
		cur+=mu[p]*arr[x]*(2*sum[p]+dt);
		sum[p]+=dt;
	}
}
inline void del(int x)
{
	for(auto &p:factor[x])
	{
		int dt=arr[x]/p;
		cur-=mu[p]*arr[x]*(2*sum[p]-dt);
		sum[p]-=dt;
	}
}
int main()
{
	db();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		const int var=sqrt(n);
		for(int i=1;i<=n;i++) block[i]=i/var;
		for(int i=1;i<=n;i++) 
		{
			scanf("%u",&arr[i]);
			factor[i].push_back(1);
			int ttt=arr[i];
			for(int j=0;prime[j]*prime[j]<=ttt;j++)
			{
				if(ttt%prime[j]==0)
				{
					int tmp=factor[i].size();
					for(int tt=0;tt<tmp;tt++)
						factor[i].push_back(factor[i][tt]*prime[j]);
					while(ttt%prime[j]==0) ttt/=prime[j];
				}
			}
			if(ttt!=1)
			{
				int tmp=factor[i].size();
				for(int tt=0;tt<tmp;tt++)
					factor[i].push_back(factor[i][tt]*ttt);
			}
		}
		for(int i=1;i<=q;i++) 
		{
			scanf("%d%d",&query[i].l,&query[i].r);
			query[i].id=i;
		}
		sort(query+1,query+1+q);
		int l=0,r=0;
		cur=0;
		for(int i=1;i<=q;i++)
		{
			while(l>=query[i].l) add(l--);
			while(r<query[i].r) add(++r);
			while(l<query[i].l-1) del(++l);
			while(r>query[i].r) del(r--);
			ans[query[i].id]=cur;
		}
		for(int i=1;i<=q;i++)
			printf("%u\n",ans[i]);
		for(int i=1;i<=n;i++)
		{
			for(auto& p:factor[i])
				sum[p]=0;
			factor[i].clear();
		}
	}
}
