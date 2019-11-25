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
int main()
{
	srand(time(NULL));
	int n=10000,m=10000-1,d=3;
	cout<<n<<" "<<m<<" "<<d<<endl;
	for(int i=0;i<m;i++)
		cout<<i+1<<" "<<i+2<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<d;j++)
			cout<<rand()%2;
		cout<<endl;
	}
}
