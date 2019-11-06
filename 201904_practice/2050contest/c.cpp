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
const ll INF=0x3f3f3f3f3f3f3f3f;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,k,a,b,c;
		cin>>n>>m>>k>>a>>b>>c;
		ll ans=INF;
		for(int i=k;i>=0;i--)
		{
			int man=n+k-i;
			int girl=m+k-i;
			ll mc=INF,gc=INF;
			for(int j=(man+1)/2;j>=0;j--)
				mc=min(mc,1LL*j*a+1LL*(man-j*2+2)/3*b);
			for(int j=(girl+1)/2;j>=0;j--) gc=min(gc,1LL*j*a+1LL*(girl-j*2+2)/3*b);
			ans=min(ans,mc+gc+1LL*i*c);
		}
		cout<<ans<<endl;
	}
}
