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
const int maxn=1e5+7;
struct Q{
	int u,v;
}query[maxn];
map<int,int> num;
int val[maxn<<5];
ll dp[maxn<<5];
int n,m;
ll calc(int u)
{
	if(num.count(u)) return dp[num[u]];
	ll ret=0;
	while(u<=n)
	{
		ret+=u;
		u=u*2;
		u++;
	}
	return ret;
}
ll getval(int u)
{
	if(num.count(u)) return val[num[u]];
	return u;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(val,0,sizeof(val));
		memset(dp,0,sizeof(dp));
		num.clear();
		int ti=0;
		char op[10];
		int tmp=n;
		do{
			num[tmp]=++ti;
			val[ti]=tmp;
			dp[ti]=dp[ti-1]+tmp;
			tmp/=2;
		}while(tmp);
		for(int i=0;i<m;i++)
		{
			scanf("%s",op);
			if(op[0]=='q')
			{
				query[i].v=-1;
				scanf("%d",&query[i].u);
			}
			else{
				scanf("%d%d",&query[i].u,&query[i].v);
				tmp=query[i].u;
				while(tmp)
				{
					if(!num.count(tmp))
					{
						num[tmp]=++ti;
						val[ti]=tmp;
					}
					dp[num[tmp]]=max(calc(tmp*2),calc(tmp*2+1))+tmp;
	//				dbg(tmp,num[tmp],dp[num[tmp]]);
					tmp/=2;
				}
			}
		}
		for(int i=0;i<m;i++)
		{
			if(query[i].v==-1)
			{
				int u=query[i].u;
				ll ans=0;
				int curval=getval(u);
				if(calc(u)==curval+calc(u*2))
					ans=calc(u)+calc(u*2+1);
				else ans=calc(u)+calc(u*2);
				ll mx=calc(u);
				while(u)
				{
					int fa=u/2;
					ll curans=0;
					if(!fa) break;
					mx+=getval(fa);
					if(u==fa*2)
						curans=mx+calc(fa*2+1);
					else curans=mx+calc(fa*2);
					ans=max(ans,curans);
					u=fa;
				}
				printf("%lld\n",ans);
			}
			else{
				int u=query[i].u;
				int v=query[i].v;
				val[num[u]]=v;
				while(u)
				{
					dp[num[u]]=max(calc(u*2),calc(u*2+1))+val[num[u]];
					u/=2;
				}
			}
		}
	}
}
