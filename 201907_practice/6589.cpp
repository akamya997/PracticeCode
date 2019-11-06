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
const int maxn=1e6+7;
ll wn[maxn << 2], rev[maxn << 2];
int G=3;
int NTT_init(int n_) {
    int step = 0; int n = 1;
    for ( ; n < n_; n <<= 1) ++step;
	for(int i=1;i<n;i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (step - 1));
    int g = quick(G, (mod - 1) / n);
    wn[0] = 1;
    for (int i = 1; i <= n; ++i)
        wn[i] = wn[i - 1] * g % mod;
    return n;
}

void NTT(ll a[], int n, int f) {
	for(int i=0;i<n;i++) if (i < rev[i])
        std::swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += (k << 1)) {
            int t = n / (k << 1);
			for(int j=0;j<k;j++){
                ll w = f == 1 ? wn[t * j] : wn[n - t * j];
                ll x = a[i + j];
                ll y = a[i + j + k] * w % mod;
                a[i + j] = (x + y) % mod;
                a[i + j + k] = (x - y + mod) % mod;
            }
        }
    }
    if (f == -1) {
        ll ninv = inv(n);
		for(int i=0;i<n;i++)
            a[i] = a[i] * ninv % mod;
    }
}
ll A[maxn<<2],C[maxn<<2];
ll fac[maxn];
void init()
{
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
}
int main()
{
	int T;
	init();
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int len=1;
		while(len<n*8) len*=2;
		NTT_init(len);
		for(int i=0;i<len;i++) A[i]=0;
		for(int i=0;i<n;i++)
			scanf("%lld",&A[i]);
		int cnt[4];
		memset(cnt,0,sizeof(cnt));
		while(m--)
		{
			int tmp;
			scanf("%d",&tmp);
			cnt[tmp]++;
		}
		NTT(A,len,1);
		for(int i=1;i<=3;i++)
		{
			if(!cnt[i]) continue;
			for(int j=0;j<len;j++) C[j]=0;
			for(int j=0;j<n;j+=i) C[j]=fac[cnt[i]+j/i-1]*inv(fac[cnt[i]-1])%mod*inv(fac[j/i])%mod;
			NTT(C,len,1);
			for(int j=0;j<len;j++)
				A[j]=A[j]*C[j]%mod;
		}
		NTT(A,len,-1);
		ll ans=0;
		for(int i=0;i<n;i++) ans^=((i+1)*A[i]);
		printf("%lld\n",ans);
	}
}
