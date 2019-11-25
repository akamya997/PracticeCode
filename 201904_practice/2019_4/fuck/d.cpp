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
const int maxn=1e5+7;
int pre[maxn][100];
int num[100];
bool ext[maxn];
bool vis[maxn];
int main()
{
	string s;
	cin>>s;
	for(int i=s.length()-1;i>=0;i--)
	{
		int id=s[i]-34;
		for(int j=0;j<100;j++)
			pre[i][j]=pre[i+1][j];
		if(!ext[id])
		{
			ext[id]=1;
			pre[i][id]++;
		}
	}
	for(int i=98;i>=0;i--)
		num[i]=num[i+1]+ext[i];
	for(int i=0;i<s.length();i++)
	{
		int cnt=0;
		int id=s[i]-34;
		for(int j=id;j<100;j++) cnt+=pre[i+1][j];
		dbg(cnt);dbg(num[id]);
		if(cnt==num[id]) vis[i]=1;
	}
	for(int i=0;i<s.length();i++)
	{
		if(!vis[i]) cout<<s[i];
	}
	cout<<endl;
}
