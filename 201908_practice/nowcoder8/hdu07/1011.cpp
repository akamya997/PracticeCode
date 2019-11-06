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
#define reads(n) FastIO::read(n)
namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], obuf[SIZE], str[60];
    int bi = SIZE, bn = SIZE, opt;
    int read(char *s) {
        while (bn) {
            for (; bi < bn && buf[bi] <= ' '; bi++);
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        int sn = 0;
        while (bn) {
            for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        s[sn] = 0;
        return sn;
    }
	template<typename T>
    bool read(T& x) {
        int n = read(str), bf;
        if (!n) return 0;
        int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
        for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
        if (bf < 0) x = -x;
        return 1;
    }
};
const int maxn=5e5+7;
struct upd{
	ll r,s,nxt,cost;
}a[maxn];
ll pre[maxn];
ll dp[maxn];
int n,q;
void db()
{
	for(int i=1;i<=n;i++)
	{
		ll p=a[i].r*inv(a[i].s)%mod;
		dp[i]=a[i].cost+(1-p+mod)%mod*((pre[i-1]-pre[a[i].nxt-1]+mod)%mod)%mod;
		dp[i]%=mod;
		dp[i]=dp[i]*inv(p)%mod;
		pre[i]=(pre[i-1]+dp[i])%mod;
	}
}
int main()
{
	int T;
	reads(T);
	while(T--)
	{
		reads(n);reads(q);
		for(int i=1;i<=n;i++)
		{
			reads(a[i].r);reads(a[i].s);
			reads(a[i].nxt);reads(a[i].cost);
		}
		db();
		while(q--)
		{
			int l,r;
			reads(l);reads(r);
			printf("%lld\n",(pre[r-1]-pre[l-1]+mod)%mod);
		}
	}
}
