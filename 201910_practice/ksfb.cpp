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
const int maxn=5e4+7;
int c[maxn];
vector<int> sk[maxn];
ll st[maxn];
map<ll,int> cnt;
map<ll,int> vis;
int main()
{
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		cnt.clear();
		vis.clear();
		int n,s;
		scanf("%d%d",&n,&s);
		for(int i=0;i<n;i++)
		{
			st[i]=0;
			sk[i].clear();
			scanf("%d",&c[i]);
			for(int j=0,tmp;j<c[i];j++)
			{
				scanf("%d",&tmp);
				sk[i].push_back(tmp);
			}
			sort(sk[i].begin(),sk[i].end());
			ll val=1;
			for(int j=0;j<c[i];j++)
			{
				st[i]+=val*sk[i][j];
				val*=1007;
			}
			cnt[st[i]]++;
		}
		ll ans=0,sam=0;
		for(int i=0;i<n;i++)
		{
			if(!vis.count(st[i]))
			{
				int ccc=cnt[st[i]];
				sam+=(1LL*ccc*(ccc-1))/2;
				vis[st[i]]=1;
			}
			for(int j=0;j<(1<<c[i])-1;j++)
			{
				ll curval=0;
				ll val=1;
				for(int k=0;k<c[i];k++)
				{
					if(j>>k&1)
					{
						curval+=val*sk[i][k];
						val*=1007;
					}
				}
				if(cnt.count(curval))
					ans+=cnt[curval];
			}
		}
		ans=ans+((1LL*n*(n-1))/2-ans-sam)*2;
		printf("Case #%d: %lld\n",++kas,ans);
	}
}
