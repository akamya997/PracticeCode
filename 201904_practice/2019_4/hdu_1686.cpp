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
string t,s;
const int maxn=1e4+7;
int f[maxn];
void getfail()
{
	f[0]=-1;
	t+='0';
	int j=0,k=-1;
	while(j<t.length()-1)
	{
		if(k==-1||t[j]==t[k])
			f[++j]=++k;
		else k=f[k];
	}
}
int kmp()
{
	getfail();
	int i=0,j=0;
	int cnt=0;
	while(i<s.length())
	{
		if(j==-1||s[i]==t[j])
		{
			i++;j++;
		}
		else j=f[j];
		if(j==t.length()-1)
			cnt++;
	}
	return cnt;
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
