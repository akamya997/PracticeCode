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
const int mod=1e9+7;
const int maxn=18;
struct Poly{
	ll a[maxn];
	void init()
	{
		memset(a,0,sizeof(a));
	}
	Poly operator+(const Poly b)const
	{
		Poly ret;
		ret.init();
		for(int i=0;i<maxn;i++)
			ret.a[i]=(a[i]+b.a[i])%mod;
		return ret;
	}
	Poly operator-(const Poly b)const
	{
		Poly ret;
		ret.init();
		for(int i=0;i<maxn;i++)
			ret.a[i]=(a[i]-b.a[i]+mod)%mod;
		return ret;
	}
	Poly operator*(const Poly b)
	{
		Poly ret;
		ret.init();
		for(int i=0;i<maxn;i++)
		{
			for(int j=0;i+j<maxn;j++)
				ret.a[i+j]=(ret.a[i+j]+a[i]*b.a[j]%mod)%mod;
		}
		return ret;
	}
};
template<typename T>
void fwt(Poly a[], int n, T f) {
    for (int d = 1; d < n; d *= 2)
        for (int i = 0, t = d * 2; i < n; i += t)
			for(int j=0;j<d;j++)
                f(a[i + j], a[i + j + d]);
}

void AND(Poly& a, Poly& b) { a =a+ b; }
void OR(Poly& a, Poly& b) { b =b+ a; }
void rOR(Poly& a, Poly& b) { b =b- a; }
void rAND(Poly& a, Poly& b) { a =a- b; }
const int maxm=1e5+7;
Poly A[maxm<<2],B[maxm<<2];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int len=1;
		while(len<=n*2) len*=2;
		for(int i=0;i<=len;i++)
		{
			A[i].init();
			B[i].init();
		}
		for(int i=0,tmp;i<n;i++)
		{
			scanf("%d",&tmp);
			A[i].a[__builtin_popcount(i)]=tmp;
		}
		for(int i=0,tmp;i<n;i++)
		{
			scanf("%d",&tmp);
			B[i].a[__builtin_popcount(i)]=tmp;
		}
		fwt(A,len,OR);
		fwt(B,len,OR);
		for(int i=0;i<=len;i++)
			A[i]=A[i]*B[i];
		fwt(A,len,rOR);
		for(int i=0;i<n;i++)
		{
			printf("%lld%c",A[i].a[__builtin_popcount(i)]%mod,i==n-1?'\n':' ');
		}
	}
}
