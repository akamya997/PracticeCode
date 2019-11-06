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
const int mod=1e9+7;
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
ll BSGS(ll a, ll b, ll p) // a^x = b (mod p)
{
    a %= p;
    if (!a && !b)
        return 1;
    if (!a)
        return -1;
    static map<ll, ll> mp;
    mp.clear();
    ll m = sqrt(p + 1.5);
    ll v = 1;
    for (int i = 1; i < m + 1; ++i)
    {
        v = v * a % p;
        mp[v * b % p] = i;
    }
    ll vv = v;
    for (int i = 1; i < m + 1; ++i)
    {
        auto it = mp.find(vv);
        if (it != mp.end())
            return i * m - it->second;
        vv = vv * v % p;
    }
    return -1;
}
const int maxn=1e5+7;
int cnt[maxn];
int main()
{
	int g=5;
	int n,b;
	scanf("%d%d",&n,&b);
	g=quick(g,b);
	ll ans=0;
	for(int i=0,tmp;i<n;i++)
	{
		scanf("%d",&tmp);
		cnt[tmp]++;
	}
	vector<int> tot;
	for(int i=0;i<maxn;i++)
	{
		if(cnt[i])
			tot.push_back(i);
	}
	int p=mod-1;
	ans=9;
	ans=quick(g,ans);
	printf("%lld\n",BSGS(5,ans,mod));
}
