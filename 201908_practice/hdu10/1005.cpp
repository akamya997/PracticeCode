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
const ll INF=0x3f3f3f3f3f3f3f3f;
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
const int maxn=1e5+6;
struct node{
	ll a,b;
	bool operator<(const node &x)const{
		return a>x.a;
	}
}stu[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%lld%lld",&stu[i].a,&stu[i].b);
		sort(stu,stu+n);
		multiset<ll> left,right;
		left.insert(-INF);
		for(int i=0;i<n;i++)
			right.insert(stu[i].b);
		right.insert(INF);
		ll ans=INF;
		for(int i=0;i<n;i++)
		{
			ll cur=*(--left.end());
			ll curans=abs(cur-stu[i].a);
			right.erase(right.find(stu[i].b));
			if(cur<stu[i].a)
			{
				auto it=right.lower_bound(stu[i].a);
				curans=min(curans,(*it)-stu[i].a);
				--it;
				if(it!=right.begin()&&*it>cur)
					curans=min(curans,stu[i].a-(*it));
			}
			left.insert(stu[i].b);
			ans=min(ans,curans);
		}
		printf("%lld\n",ans);
	}
}
