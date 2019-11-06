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
const int maxn=5e3+7;
int sg[maxn];
bool vis[maxn];
void db()
{
	sg[0]=0;
	sg[1]=0;
	sg[2]=1;
	for(int i=3;i<maxn;i++)
	{
		int res=i-2;
		memset(vis,0,sizeof(vis));
		for(int j=0;j<=res;j++)
			vis[sg[j]^sg[res-j]]=1;
		for(int j=0;j<maxn;j++)
			if(!vis[j])
			{
				sg[i]=j;
				break;
			}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	db();
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		if(sg[n]) cout<<"First"<<endl;
		else cout<<"Second"<<endl;
	}
}
