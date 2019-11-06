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
const int maxn=100;
int vis[maxn];
int main()
{
	srand(time(NULL));
	int T=100000;
	int n;
	cin>>n;
	int cnt=0;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		vector<int> all;
		for(int i=1;i<=n;i++) all.push_back(i);
		random_shuffle(all.begin(),all.end());
		for(int i=1;i<=n;i++)
		{
			if(all[i-1]==1||vis[all[i-1]])
			{
				int pos=rand()%(n-i+1)+1;
				for(int j=1;;j++)
				{
					if(!vis[j]) pos--;
					if(!pos)
					{
						vis[j]=all[i-1];
						break;
					}
				}
			}
			else vis[all[i-1]]=all[i-1];
		}
		if(vis[all[n-1]]==all[n-1]) cnt++;
	}
	printf("%.6f\n",1.0*cnt/100000);
}
