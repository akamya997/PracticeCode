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
template<typename T>
void fwt(ll a[], int n, T f) {
    for (int d = 1; d < n; d *= 2)
        for (int i = 0, t = d * 2; i < n; i += t)
			for(int j=0;j<d;j++)
                f(a[i + j], a[i + j + d]);
}

inline void XOR (ll& a, ll& b) {
    ll x = a, y = b;
    a = (x + y) % mod;
    b = (x - y + mod) % mod;
}
int n,m,k;
const int maxn=1<<20;
int all[14];
ll f[maxn];
void dfs(int u,int Xor,int s)
{
	if(u==m)
	{
		f[Xor]+=s;
		return;
	}
	dfs(u+1,Xor^all[u],s*-1);
	dfs(u+1,Xor,s);
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin>>n>>m>>k)
	{
		for(int i=0;i<(1<<k);i++) f[i]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++) cin>>all[j];
			dfs(0,0,1);
		}
		fwt(f,1<<k,XOR);
		ll inv2=inv(quick(2,m));
		ll ans=0;
		ll th=1;
		for(int i=0;i<(1<<k);i++)
		{
			ans^=th*f[i]%mod*inv2%mod;
			th=th*3LL%mod;
		}
		cout<<ans<<endl;

	}
}
