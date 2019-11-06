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
ll l[maxn],u[maxn],b[maxn];
struct val{
	ll value;
	int id;
	bool operator<(const val &a)const{
		return value>a.value;
	}
}v[maxn];
ll n,x;
ll tot;
bool check(ll cur)
{
	ll cnt=cur/x;
	ll ret=0;
	ll rm=cur%x;
	for(int i=0;i<cnt+(rm!=0);i++)
		ret+=v[i].value;
	ll mx=0;
	if(rm)
	{
		for(int i=0;i<n;i++)
		{
			int id=v[i].id;
			mx=max(mx,ret-(i>=cnt?v[cnt].value:v[i].value)+(rm>b[id]?(rm-b[id])*u[id]+b[id]*l[id]:rm*l[id]));
		}
	}
	else mx=ret;
	return mx>=tot;
}
int main()
{
	scanf("%lld%lld",&n,&x);
	tot=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&b[i],&l[i],&u[i]);
		tot+=l[i]*b[i];
		v[i].value=b[i]*l[i]+(x-b[i])*u[i];
		v[i].id=i;
		//dbg(i,v[i].value);
	}
	sort(v,v+n);
	ll L=0,R=n*x;
	ll ans;
	while(L<=R)
	{
		ll mid=L+R>>1;
		if(check(mid)) R=mid-1,ans=mid;
		else L=mid+1;
	}
	printf("%lld\n",ans);
}
