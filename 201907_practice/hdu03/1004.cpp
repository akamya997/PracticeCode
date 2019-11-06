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
const int maxn=2e5+7;
int n,k;
int tree[maxn];
int arr[maxn];
ll pre[maxn];
int preid[maxn];
vector<ll> all;
int getid(ll x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
void add(int x,int val)
{
	while(x>0)
	{
		tree[x]=max(tree[x],val);
		x-=x&-x;
	}
}
int query(int x)
{
	int ret=-0x3f3f3f3f;
	while(x<maxn)
	{
		ret=max(ret,tree[x]);
		x+=x&-x;
	}
	return ret;
}
bool check(ll cur)
{
	memset(tree,-0x3f,sizeof(tree));
	add(getid(0),0);
	for(int i=1;i<=n;i++)
	{
		ll tar=pre[i]-cur;
		int id=getid(tar);
		int tt=query(id)+1;
		if(tt>=k) return true;
		if(tt<0)
			tt=-0x3f3f3f3f;
		add(preid[i],tt);
	}
	return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		all.clear();
		ll mx=1e9;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
			pre[i]=pre[i-1]+arr[i];
			all.push_back(pre[i]);
		}
		all.push_back(0);
		all.push_back(mx*mx);
		sort(all.begin(),all.end());
		all.erase(unique(all.begin(),all.end()),all.end());
		for(int i=1;i<=n;i++) preid[i]=getid(pre[i]);
		ll l=-n*mx,r=n*mx,ans=-998244353;
		while(l<=r)
		{
			ll mid=l+r>>1;
			if(check(mid))
			{
				r=mid-1;
				ans=mid;
			}
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
}
