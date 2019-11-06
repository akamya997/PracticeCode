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
	string s;
	cin>>s;
	string t="";
	ll ans=0;
	ll cnt=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='A')
			t+='A';
		else if(s[i]=='B')
		{
			if(i+1<s.length()&&s[i+1]=='C')
			{
				t+='B';
				i++;
			}
			else t+=' ';
		}
		else{
			t+=' ';
		}
	}
	for(int i=0;i<t.length();i++)
	{
		if(t[i]=='A') cnt++;
		else if(t[i]=='B') ans+=cnt;
		else cnt=0;
	}
	cout<<ans<<endl;
}
