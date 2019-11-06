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
int f[]={1,0,0,1,0,1,0},r[]={0,1,0,0,0,0,1},ch[]={0,0,1,0,1,0,0};
int pf[20],pr[20],pch[20];
int main()
{
	ll a,b,c;
	for(int i=0;i<14;i++)
	{
		if(i)
		{
			pf[i]=pf[i-1];
			pr[i]=pr[i-1];
			pch[i]=pch[i-1];
		}
		pf[i]+=f[i%7];
		pr[i]+=r[i%7];
		pch[i]+=ch[i%7];
	}
	cin>>a>>b>>c;
	ll ans=0;
	ll week=min(a/3,min(b/2,c/2));
	ans=week*7;
	a-=week*3;b-=week*2;c-=week*2;
	int ads=0;
	for(int i=0;i<14;i++)
	{
		for(int j=0;j<14;j++)
		{
			int useda=pf[j],usedb=pr[j],usedc=pch[j];
			if(i)
			{
				useda-=pf[i-1];usedb-=pr[i-1];usedc-=pch[i-1];
			}
			if(useda>a||usedb>b||usedc>c)
			{
				ads=max(ads,j-i);
			}
		}
	}
	cout<<ans+ads<<endl;
}
