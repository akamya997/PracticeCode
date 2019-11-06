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
	int T;
	int kas=0;
	cin>>T;
	while(T--)
	{
		map<char,int> cnt;
		map<char,char> type;
		string s,t;
		cin>>s>>t;
		for(int i=0;i<26;i++)
			type[i+'a']=t[i];
		for(int i=0;i<s.length();i++)
			cnt[type[s[i]]]++;
		cout<<"Case #"<<++kas<<": ";
		if(cnt['h']*4>=s.length())
			cout<<"Harmful\n";
		else if(cnt['h']*10<=s.length())
			cout<<"Recyclable\n";
		else{
			if(cnt['d']>=cnt['w']*2)
				cout<<"Dry\n";
			else cout<<"Wet\n";
		}

	}
}
