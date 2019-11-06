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
ll calc(ll n,ll m)
{
	ll ans1=0;
	ll cnt=m/3;
	if(m%3==2) cnt++;
	ans1=cnt*(n/2);
	if(n&1&&n>3)
		ans1=max(ans1,1LL*cnt*(n-3)/2+(m+1)/2);
	ll ans2=0;
	cnt=(m+1)/2;
	ans2=(n/3+(n%3==2))*cnt;
	if(n%3==1)
	{
		ans2+=(m/3+(m%3==2));
	}
	return max(ans1,ans2);
}
int main()
{
	ll n,m;
	cin>>n>>m;
	cout<<max(calc(n,m),calc(m,n))<<endl;
}
