#include<bits/stdc++.h>
using namespace std;
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
typedef unsigned long long ull;
const int maxn=1e6+7;
const ull p=;
ull powp[maxn];
ull pre[maxn];
string s,t;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>t>>s;
		ull tar=0;
		int ans=0;
		for(int i=0;i<t.length();i++) tar=tar*p+t[i]-'A';
		for(int i=0;i<s.length();i++)
		{
			if(i)
				powp[i]=powp[i-1]*p;
			else powp[i]=1;
			if(i)
				pre[i]=pre[i-1]*p+s[i]-'A';
			else pre[i]=s[i]-'A';
		}
		for(int i=t.length()-1;i<s.length();i++)
		{
			if(i==t.length()-1)
			{
				if(pre[i]==tar) ans++;
			}
			else{
				if(pre[i]-pre[i-t.length()]*powp[t.length()]==tar) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
