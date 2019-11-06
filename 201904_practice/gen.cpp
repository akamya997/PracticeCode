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
mt19937 rnd(time(NULL));
const int maxn=1000;
int main()
{
	int n=100000,m=5000;
	cout<<n<<" "<<m<<endl;
	int len=5000;
	for(int i=0;i<n;i++)
		cout<<rnd()%maxn<<" ";
	cout<<endl;
	//for(int i=2;i<=n;i++) cout<<1<<" "<<i<<endl;
	for(int i=1;i<=len;i++) cout<<i<<" "<<i+1<<endl;
	for(int i=len+2;i<=n;i++) cout<<i<<" "<<rnd()%(i-1)+1<<endl;
	while(m--)
	{
		int op=rnd()%3;
		int l=rnd()%n+1,r=rnd()%n+1,val=rnd()%maxn;
		if(!op) cout<<'Q'<<" "<<l<<" "<<r<<endl;
		else cout<<'C'<<" "<<l<<" "<<r<<" "<<val<<endl;
	}
}
