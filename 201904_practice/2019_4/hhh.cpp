#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int mod=1e9+7;
struct Matrix{
	ll a[3][3];
	Matrix operator *(const Matrix b)const{
		Matrix ret;
		memset(ret.a,0,sizeof(ret.a));
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
					ret.a[i][j]=(a[i][k]*b.a[k][j]%mod+ret.a[i][j])%mod;
			}
		}
		return ret;
	}
};
Matrix quick(Matrix a,long long b)
{
	Matrix ret;
	memset(ret.a,0,sizeof(ret.a));
	ret.a[0][0]=ret.a[1][1]=ret.a[2][2]=1;
	while(b)
	{
		if(b&1) ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}
Matrix base={1,0,1,
			1,0,0,
			0,1,0};
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		ll n;
		cin>>n;
		if(n<=3)
		{
			if(n==2) cout<<3<<endl;
			else cout<<4<<endl;
			continue;
		}
		Matrix ans=base;
		ans=quick(ans,n-3);
		ll op=0;
		op=ans.a[0][0]*4+ans.a[0][1]*3+ans.a[0][2]*2;
		op%=mod;
		cout<<op<<endl;
	}
}
