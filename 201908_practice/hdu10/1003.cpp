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
const int maxn=15;
double p[maxn];
int main()
{
	srand(time(NULL));
	int n;
	cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>p[i];
		p[i]*=1000000;
	}
	int ans=0;
	for(int S=0;S<(1<<n);S++)
	{

		int cur=0;
		int T=100000;
		while(T--)
		{
			int cnt=0;
			for(int i=0;i<n;i++)
			{
				if(S>>i&1)
				{
					int tmp=rand()%1000001+1;
					if(tmp<=p[i]) cnt++;
				}
			}
			cur+=(cnt==1);
		}
		ans=max(ans,cur);
	}
	printf("%.10f\n",1.0*ans/100000);
}
