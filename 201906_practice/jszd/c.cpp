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
int sg[10005];
void db()
{
	sg[1]=0;
	for(int i=2;i<10005;i++)
	{
		for(int j=1;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				if(sg[i-j]==0||(i!=i/j&&sg[i-i/j]==0))
					sg[i]=1;
			}
		}
		//	dbg(i,sg[i]);
	}
}
int main()
{
	db();
	int ans=0;
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			for(int k=1;k<=10;k++)
				if((sg[i]^sg[j]^sg[k])==1)
					ans++;
		}
	}
	dbg(ans);
}
