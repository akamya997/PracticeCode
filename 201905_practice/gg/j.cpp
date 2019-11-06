#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int mod=123456789;
struct Matrix{
	ll a[6][6];
	void init()
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<6;i++) a[i][i]=1;
	}
	Matrix operator*(const Matrix &b) const{
		Matrix ret;
		memset(ret.a,0,sizeof(ret.a));
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<6;j++)
			{
				for(int k=0;k<6;k++)
				{
					ret.a[i][j]=(ret.a[i][j]+a[i][k]*b.a[k][j]%mod)%mod;
				}
			}
		}
		return ret;
	}
};
const Matrix base={1,2,1,0,0,0,
			1,0,0,0,0,0,
			0,0,1,3,3,1,
			0,0,0,1,2,1,
			0,0,0,0,1,1,
			0,0,0,0,0,1};
Matrix quick(Matrix a,ll b)
{
	Matrix ret;
	ret.init();
	while(b)
	{
		if(b&1) ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ll n;
		scanf("%lld",&n);
		if(n<=2) printf("%lld\n",n);
		else{
			Matrix cur=quick(base,n-2);
			ll ans=2*cur.a[0][0]%mod+cur.a[0][1]+27*cur.a[0][2]%mod+9*cur.a[0][3]%mod+3*cur.a[0][4]%mod+cur.a[0][5];
			ans%=mod;
			printf("%lld\n",ans);
		}
	}
}
