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
int prime[]={2,3,5,7,11,13};
bool check(int num,int state)
{
	for(int i=0;i<6;i++)
	{
		int len=prime[i];
		for(int j=0;j<num;j++)
		{
			if(j+len-1>=num) break;
			int rd=0,blue=0;
			for(int k=0;k<len;k++)
			{
				if(state&(1<<(j+k))) rd++;
				else blue++;
			}
			//dbg(num,state,rd,blue);
			if(rd<blue) return false;
		}
	}
	return true;
}
int main()
{
	for(int i=2;i<=100;i++)
	{
		cout<<i<<":";
		int ans=0;
		for(int j=0;j<(1<<i);j++)
		{
			if(check(i,j)) ans++;
		}
		cout<<ans<<endl;
	}
}
