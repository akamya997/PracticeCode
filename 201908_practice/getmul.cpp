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
const int maxn=105;
vector<string> ans;
int tot;
int prime[maxn];
bool vis[maxn];
int mu[maxn],phi[maxn];
void db()
{
	vis[1]=1;
	mu[1]=1,phi[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!vis[i])
		{
			prime[tot++]=i;
			mu[i]=-1;
			phi[i]=i-1;
		}
		for(int j=0;j<tot;j++)
		{
			if(i*prime[j]>=maxn) break;
			if(i%prime[j]==0)
			{
				mu[i*prime[j]]=0;
				phi[i*prime[j]]=phi[i]*prime[j];
				vis[i*prime[j]]=1;
				break;
			}
			vis[i*prime[j]]=1;
			mu[i*prime[j]]=mu[i]*mu[prime[j]];
			phi[i*prime[j]]=phi[i]*phi[prime[j]];
		}
	}
}
int main()
{
	db();
	const int var=50;
	for(int i=1;i<=var;i++)
	{
		string tmp="";
		tmp+=to_string(i);
		if(!vis[i]) tmp+='*';
		tmp+=" |";
		tmp+=to_string(mu[i]);
		tmp+=" |";
		tmp+=to_string(phi[i]);
		cout<<tmp<<endl;
	}

}
