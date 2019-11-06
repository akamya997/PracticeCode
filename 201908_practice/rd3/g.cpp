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
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!='0')
		{
			int cur=0;
			for(int j=i;j<s.length();j++)
			{
				cur=cur*10+s[j]-'0';
				cur%=110;
				if(cur==0) ans++;
			}
		}
	}
	cout<<ans<<endl;
}
