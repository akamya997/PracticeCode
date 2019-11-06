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
const int maxn=1e5+7;
ll wn[maxn << 2], rev[maxn << 2];
int G=3;//998244353
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
int f[maxn];
int prime[maxn],phi[maxn];
const ll sqr=116195171;
bool vis[maxn];
int tot;
void db()
{
	phi[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!vis[i])
		{
			prime[tot++]=i;
			phi[i]=i-1;
		}
		for(int j=0;j<tot;j++)
		{
			if(prime[j]*i>=maxn) break;
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				vis[i*prime[j]]=1;
				break;
			}
			vis[i*prime[j]]=1;
			phi[i*prime[j]]=phi[i]*phi[prime[j]];
		}
	}
}
ll A[maxn<<2],B[maxn<<2];
int main()
{
	int T;
	scanf("%d",&T);
	db();
	while(T--)
	{
		int n;
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++) f[phi[i]]++;
		int len=1;
		while(len<(2*n+2)) len*=2;
		NTT_init(len);
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		ll invs=inv(sqr);
		for(int j=0;j<=n;j++) A[j]=1LL*j*f[j]%mod*quick(sqr,1LL*j*j)%mod;
		for(int j=0;j<=n;j++) B[j]=quick(invs,1LL*j*j);
		NTT(A,len,1);
		NTT(B,len,1);
		for(int i=0;i<len;i++) A[i]=A[i]*B[i]%mod;
		NTT(A,len,-1);
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ll cur=1LL*2*i*f[i]%mod*quick(sqr,1LL*i*i)%mod*A[i]%mod;
			ans=(ans+cur)%mod;
			ans=(ans-1LL*i*i%mod*f[i]%mod*f[i]%mod*quick(2,1LL*i*i)%mod+mod)%mod;
		}
		printf("%lld\n",ans);
	}
}
