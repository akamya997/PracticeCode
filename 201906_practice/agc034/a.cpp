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
	int n;
	int a,b,c,d;
	string s;
	cin>>n>>a>>b>>c>>d;
	cin>>s;
	bool ok=1;
	for(int i=b;i<=d-1;i++)
	{
		if(s[i]=='#'&&s[i-1]=='#') 
		{
			ok=0;
			break;
		}
	}
	for(int i=a;i<=c-1;i++)
	{
		if(s[i]=='#'&&s[i-1]=='#')
		{
			ok=0;break;
		}
	}
	if(c>d){
		bool cango=0;
		for(int i=max(1,b-1);i<d;i++)
		{
			if(s[i]=='.'&&s[i-1]=='.'&&s[i+1]=='.') cango=1;
		}
		if(!cango) ok=0;
	}
	if(ok) puts("Yes");
	else puts("No");
}
