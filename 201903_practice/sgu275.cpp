#include<bits/stdc++.h>
using namespace std;
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
const int maxbase=5;
long long b[maxbase+7];
int main()
{
	int n;
	cin>>n;
	long long cur;
	for(int i=0;i<n;i++)
	{
		cin>>cur;
		for(int j=maxbase;j>=0;j--)
		{
			if(cur>>j&1)
			{
				if(b[j]) cur^=b[j];
				else{
					b[j]=cur;
					for(int k=j+1;k<=maxbase;k++) if(b[k]&&(b[j]>>k&1)) b[k]^=b[j];
					for(int k=j-1;k>=0;k--) if(b[k]&&(b[j]>>k&1)) b[k]^=b[j];
					break;
				}
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=maxbase;i++)
	{
		if(b[i]) ans^=b[i];
	}
	cout<<ans<<endl;
}
