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
int x,p,k;
const int maxn=1e6+7;
int mp[maxn],mu[maxn];
vector<int> prime;
void db()
{
	mu[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!mp[i])
		{
			prime.push_back(i);
			mu[i]=-1;
		}
		for(auto& p:prime)
		{
			if(i*p>=maxn) break;
			if(i%p==0)
			{
				mu[i*p]=0;
				mp[i*p]=p;
				break;
			}
			mp[i*p]=p;
			mu[i*p]=mu[i]*mu[p];
			
		}
	}
}
int var;
inline int getcnt(int n)
{
	int ret=0;
	for(int i=1;i*i<=p;i++)
	{
		if(p%i==0)
		{
			ret+=mu[i]*(n/i);
			if(i*i!=p)
				ret+=mu[p/i]*(n/(p/i));
		}
	}
	return ret;
}
inline bool check(int n)
{
	return getcnt(n)-var>=k;
}
int main()
{
	db();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&x,&p,&k);
		var=getcnt(x);
		int l=x+1,r=1e9,ans=-1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid))
				r=mid-1,ans=mid;
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
}
