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
int main()
{
	int n;
	string s;
	string tar="ytpca";
	cin>>n;
	int ans=0;
	while(n--)
	{
		cin>>s;
		bool ok=0;
		for(int i=s.length()-1;i>=0;i--)
		{
			int cur=s.length()-i-1;
			if(s[i]!=tar[cur]) break;
			if(tar[cur]=='a')
			{
				ok=1;break;
			}
		}
		if(ok) ans++;
	}
	cout<<ans<<endl;
}
