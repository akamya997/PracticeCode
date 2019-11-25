#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
ll quick(ll a,ll b,ll mod)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a,ll mod){return quick(a,mod-2,mod);}
int main()
{
	ll n;
	cin>>n;
	ll tot=(n*2+1)*2*n/2;
	if(tot%2==0) 
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	vector<int> ans(2*n+1);
	int fi=1,last=n*2;
	for(int i=0;i<n;i++)
	{
		if(i&1)
		{
			ans[i]=last;
			ans[i+n]=last-1;
			last-=2;
		}
		else {
			ans[i]=fi;
			ans[i+n]=fi+1;
			fi+=2;
		}
	}
	for(int i=0;i<2*n;i++) 
		cout<<ans[i]<<" ";
	cout<<endl;
}
