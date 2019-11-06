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
int main()
{
	srand(time(NULL));
	int n=200;
	cout<<n<<endl;
	for(int i=0;i<4;i++)
		cout<<1<<" "<<0<<endl;
	for(int i=0;i<4;i++)
		cout<<0<<" "<<1<<endl;
	for(int i=0;i<n-8;i++)
		cout<<0<<" "<<0<<endl;
	
	cout<<5000<<endl;
	int m=5000;
	for(int i=0;i<m;i++)
	{
		cout<<rand()%n+1<<" "<<rand()%n+1<<" "<<rand()%1000000+1<<endl;
	}
}
