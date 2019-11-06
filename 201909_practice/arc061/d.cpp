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
map<PII,int> ext;
vector<PII> all;
ll ans[10];
int getcnt(PII cur)
{
	//if(cur.first-2<=0||cur.second-2<=0) return -1;
	int ret=0;
	for(int i=-2;i<=0;i++)
	{
		for(int j=-2;j<=0;j++)
		{
			if(ext.count(make_pair(cur.first+i,cur.second+j)))
				ret++;
		}
	}
	//dbg(cur.first,cur.second,ret);
	return ret;
}
int main()
{
	int h,w,n;
	scanf("%d%d%d",&h,&w,&n);
	ll tot=1LL*(h-2)*(w-2);
	for(int i=0,a,b;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		ext[make_pair(a,b)]=1;
		for(int dx=-2;dx<=2;dx++)
		{
			for(int dy=-2;dy<=2;dy++)
			{
				int x=a+dx,y=b+dy;
				if(x>h||x<=2||y>w||y<=2) continue;
				all.push_back(make_pair(x,y));
			}
		}
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	ll cnt=0;
	for(auto u:all)
	{
		int cc=getcnt(u);
		if(cc==0) continue;
		ans[cc]++;
		cnt++;
	}
	ans[0]=tot-cnt;
	for(int i=0;i<=9;i++)
		printf("%lld\n",ans[i]);
}
