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
	getline(cin,s);
	while(T--)
	{
		getline(cin,s);
		int minute=(s[s.length()-5]-'0')*10+(s[s.length()-4]-'0');
		int sec=(s[s.length()-2]-'0')*10+(s[s.length()-1]-'0');
		int tot=minute*60+sec;
		int year=0;
		for(int i=0;i<4;i++)
		{
			year=year*10+s[i]-'0';
		}
		if(year>=2050)
			cout<<tot%100<<endl;
		else cout<<((-tot)%100+100)%100<<endl;
	}
}
