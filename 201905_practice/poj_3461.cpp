#include<iostream>
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
string s,t;
const int maxn=1e4+7;
int fail[maxn];
void getfail()
{
	int j=0,k=fail[0]=-1;
	while(j<t.length())
	{
		while(k!=-1&&t[k]!=t[j]) k=fail[k];
		fail[++j]=++k;
	}
}
int kmp()
{
	getfail();
	int ret=0;
	int i=0,j=0;
	while(i<s.length())
	{
		while(j!=-1&&s[i]!=t[j]) j=fail[j];
		i++,j++;
		if(j==t.length()) ret++,j=fail[j];
	}
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>t>>s;
		cout<<kmp()<<endl;
	}
}
