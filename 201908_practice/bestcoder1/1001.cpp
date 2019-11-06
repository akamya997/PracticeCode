#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<int> a,b;
		for(int i=0,tmp;i<n;i++)
		{
			cin>>tmp;
			a.push_back(tmp);
		}
		for(int i=0,tmp;i<n;i++)
		{
			cin>>tmp;
			b.push_back(tmp);
		}
		int afi=-1,bfi=-1;
		for(int i=n-1;i>=0;i--)
			if(a[i])
			{
				afi=i;
				break;
			}
		for(int i=n-1;i>=0;i--)
		{
			if(b[i])
			{
				bfi=i;break;
			}
		}
		if(afi>bfi)
			cout<<"1/0\n";
		else if(bfi>afi)
			cout<<"0/1\n";
		else{
			int aa=a[afi],bb=b[bfi];
			int gcd=__gcd(aa,bb);
			cout<<aa/gcd<<"/"<<bb/gcd<<endl;
		}

	}
}
