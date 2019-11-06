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
const int maxn=65;
ll f[maxn][maxn];
ll C[maxn][maxn];
void db()
{
	for(int i=0;i<maxn;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	for(int i=0;i<maxn;i++)
	{
		for(int j=0;j<maxn;j++)
		{
			for(int ii=0;ii<=i;ii++)
			{
				for(int jj=0;jj<=j;jj++)
				{
					if((ii+2*jj)%3==0)
						f[i][j]=(f[i][j]+C[i][ii]*C[j][jj]%mod)%mod;
				}
			}
		}
	}
}
int main()
{
	db();
	int T;
	cin>>T;
	while(T--)
	{
		ll n,a;
		cin>>n>>a;
		int x=0,y=0;
		for(int i=0;i<maxn-1;i++)
		{
			if(a>>i&1)
			{
				if(i&1) y++;
				else x++;
			}
		}
		ll ans=0;
		for(int i=0;i<=x;i++)
		{
			for(int j=0;j<=y;j++)
			{
				ll cur=0;
				cur=C[x][i]*C[y][j]%mod*quick(f[i][j],n)%mod;
				if((i+j+x+y)%2) cur=mod-cur;
				ans=(ans+cur)%mod;
			}
		}
		cout<<ans<<endl;
	}

}
