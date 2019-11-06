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
const int maxn=1e3+7;
ll a[maxn];
/*struct Trie{
	int cnt;
	int ch[2];
}tree[maxn*200];
ll dp[maxn*200];
int tot=0;
inline int newnode()
{
	tot++;
	tree[tot].ch[0]=tree[tot].ch[1]=0;
	return tot;
}
int rt;
void Insert(ll x)
{
	int cur=rt;
	for(int i=60;i>=0;i--)
	{
		tree[cur].cnt++;
		int val=(x>>i&1);
		if(!tree[cur].ch[val])
			tree[cur].ch[val]=newnode();
	}
	tree[cur].cnt++;
}*/
int cnt[65][2];
ll dp[65];
const int var=52;
int main()
{
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		int n;ll m;
		scanf("%d%lld",&n,&m);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++) 
		{
			scanf("%lld",&a[i]);
			for(int j=var;j>=0;j--)
				cnt[j][a[i]>>j&1]++;
		}
		ll val=1;
		dp[0]=min(cnt[0][0],cnt[0][1])*val;
		for(int j=1;j<=var;j++)
		{
			val*=2;
			dp[j]=dp[j-1]+min(cnt[j][0],cnt[j][1])*val;
		}
		if(dp[var]>m) printf("Case #%d: -1\n",++kas);
		else{
			ll ans=0,cur=0;
			for(int i=var;i>=0;i--)
			{
				if(i!=0)
				{
					if((1LL<<i)*cnt[i][0]+dp[i-1]+cur<=m)
					{
						cur+=(1LL<<i)*cnt[i][0];
						ans+=1LL<<i;
					}
					else{
						cur+=(1LL<<i)*cnt[i][1];
					}
				}
				else{
					if(cnt[i][0]+cur<=m)
					{
						cur+=(1LL<<i)*cnt[i][0];
						ans++;
					}
				}
			}
			printf("Case #%d: %lld\n",++kas,ans);
		}
	}
}
