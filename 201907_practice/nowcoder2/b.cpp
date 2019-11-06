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
int k;ll n;
const int N=2200;
ll c[N],b[N],h[N],f[N],tmp[N];
inline void qmul(ll *x,ll *y)
{
	for(int i=0;i<k*2;++i)tmp[i]=0;
	for(int i=0;i<k;++i)
	for(int j=0;j<k;++j)
	tmp[i+j]=(tmp[i+j]+1ll*x[i]*y[j]%mod)%mod;
	for(int i=k*2-2;i>=k;--i)
	for(int j=1;j<=k;++j)
	tmp[i-j]=(tmp[i-j]+1ll*tmp[i]*f[j]%mod)%mod;
	for(int i=0;i<k;++i)x[i]=tmp[i];
	return;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		memset(h,0,sizeof(h));
		c[1]=b[0]=1;
		cin>>k>>n;
		if(n==-1)
		{
			cout<<2LL*inv(k+1)%mod<<endl;
			continue;
		}
		ll invk=inv(k);
		for(int i=1;i<=k;i++) f[i]=invk;
		h[0]=1;
		for(int i=1;i<k;i++)
			for(int j=0;i-j>0;j++)
				h[i]=(h[i]+h[j]*invk%mod)%mod;
		if(n<k) cout<<h[n]<<endl;
		else{
			while(n)
			{
				if(n&1) qmul(b,c);
				qmul(c,c);n>>=1;
			}
			ll ans=0;
			for(int i=0;i<k;i++) ans=(ans+h[i]*b[i]%mod)%mod;
			cout<<ans<<endl;
		}
	}
}
