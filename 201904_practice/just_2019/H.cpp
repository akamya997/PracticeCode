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
	int T;
	cin>>T;
	string s;
	while(T--)
	{
		cin>>s;
		bool ok=1;
		for(int i=1;i<s.length();i++)
		{
			if(s[i-1]=='z'&&s[i]=='a') continue;
			else if(s[i]<='z'&&s[i]>='b'&&s[i]-s[i-1]==1) continue;
			else{
				ok=0;break;
			}
		}
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
