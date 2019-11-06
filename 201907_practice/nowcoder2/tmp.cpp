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
const int N=3005;
ll len;
ll ans,a[N],h[N],b[N],c[N],tmp[N];

void mul(ll *A,ll *B)
{
    for(int i=0;i<=len;i++)tmp[i]=0;
    for(int i=0;i<=k;i++)
        for(int j=0;j<=k;j++)
            tmp[i+j]=(tmp[i+j]+A[i]*B[j])%mod;
    for(int i=len;i>=k;i--)
    {
        for(int j=0;j<k;j++)
            tmp[i-k+j]=(tmp[i-k+j]+tmp[i]*a[k-j])%mod;
        tmp[i]=0;
    }
    for(int i=0;i<=len;i++)A[i]=tmp[i];
}

void Pow(ll *A,ll B,ll *res)
{
    res[0]=1;
    for(;B;B>>=1,mul(A,A))
        if(B&1)mul(res,A);
}
void init()
{
	memset(a,0,sizeof(a));
	memset(h,0,sizeof(h));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(tmp,0,sizeof(tmp));
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		init();
		cin>>k>>n;
		len=k<<1;
		if(n==-1)
		{
			if(k&1) cout<<inv((k+1)/2)<<endl;
			else cout<<2LL*inv(k+1)%mod<<endl;
			continue;
		}
		ll invk=inv(k);
		for(int i=1;i<=k;i++) a[i]=invk;
		h[0]=1;
		for(int i=1;i<k;i++)
			for(int j=1;i-j>=0;j++)
				h[i]=(h[i]+h[i-j]*invk%mod)%mod;
		if(n<k) cout<<h[n]<<endl;
		else{
			ans=0;
			c[1]=1;Pow(c,n,b);
			for(int i=0;i<k;i++)ans=(ans+b[i]*h[i])%mod;
			cout<<ans<<endl;
		}
	}
}

