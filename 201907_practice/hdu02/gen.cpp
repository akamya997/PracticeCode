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
const int INF=0x3f3f3f3f;
const int mod=1e9;
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
ll fib[50];
const int maxn=1e5+7;
ll arr[maxn];
int main()
{
	srand(time(NULL));
	int T=4;
	fib[0]=fib[1]=1;
	for(int i=2;i<50;i++) fib[i]=fib[i-1]+fib[i-2];
	for(int i=1;i<51;i++) arr[i]=fib[i-1]%mod;
	for(int i=51;i<maxn;i++) arr[i]=rand();
	while(T--)
	{
		int n=1e5,q=1e5;
		cout<<n<<" "<<q<<endl;
		for(int i=1;i<=n;i++)
			cout<<rand()+1<<" ";
		cout<<endl;
		while(q--)
		{
			int l=rand()%n+1,r=rand()%n+1;
			if(l>r) swap(l,r);
			cout<<l<<" "<<r<<endl;
		}
	}
	
}
