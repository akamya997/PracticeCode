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
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string s,t;
		cin>>s>>t;
		bool ok=1;
		int cnt=0;
		for(int i=0;i<t.length();i++)
		{
			while(s[i+cnt]!=t[i])
			{
				cnt++;
				if(cnt>2)
				{
					ok=0;break;
				}
			}
		}
		if(s.length()-2!=t.length()) ok=0;
		cout<<ok<<endl;
	}
}
