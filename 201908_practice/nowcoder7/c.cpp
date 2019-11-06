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
ll cost[205];
const int maxn=1e5+7;
struct tree{
	int h,c,cnt;
	bool operator<(const tree &a)const{
		return h>a.h;
	}
}tr[maxn];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(cost,0,sizeof(cost));
		ll tot=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&tr[i].h,&tr[i].c,&tr[i].cnt);
			tot+=tr[i].cnt;
			cost[tr[i].c]+=tr[i].cnt;
		}
		ll ans=0x3f3f3f3f3f3f3f3f;
		sort(tr,tr+n);
		ll haveused=0;
		for(int i=0;i<n;i++)
		{
			tree cur=tr[i];
			ll curcnt=0;
			ll allused=0;
			while(i<n&&tr[i].h==cur.h)
			{
				tot-=tr[i].cnt;
				curcnt+=tr[i].cnt;
				allused+=1LL*tr[i].cnt*tr[i].c;
				cost[tr[i].c]-=tr[i].cnt;
				i++;
			}
			i--;
			ll cutdown=0;ll used=haveused;
			for(int j=1;j<=200;j++)
			{
				if(curcnt*2>curcnt+tot-cutdown) break;
				if(curcnt*2>curcnt+tot-cutdown-cost[j])
				{
					ll ccc=(curcnt+tot-cutdown)-curcnt*2+1;
					cutdown+=ccc;
					used+=ccc*j;
					break;
				}
				else{
					cutdown+=cost[j];
					used+=1LL*cost[j]*j;
				}
			}
			ans=min(ans,used);
			haveused+=allused;
		}
		printf("%lld\n",ans);
	}

}
