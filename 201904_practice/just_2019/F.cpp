#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		string s;
		cin>>s;
		bool ok=1;
		if(s[0]>='A'&&s[0]<='Z') ok=0;
		else{
			int cnt=1;
			for(int i=0;i<s.length();i++)
			{
				if(s[i]>='A'&&s[i]<='Z') cnt++;
			}
			if(cnt>7) ok=0;
		}
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
