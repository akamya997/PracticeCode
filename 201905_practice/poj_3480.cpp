#include <iostream>

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
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int sum=0;
		int one=0;
		for(int i=0,tmp;i<n;i++)
		{
			cin>>tmp;
			if(tmp==1) one++;
			sum^=tmp;
		}
		if(!sum)
		{
			if(one==n) cout<<"John"<<endl;
			else cout<<"Brother"<<endl;
		}
		else{
			if(one==n) cout<<"Brother"<<endl;
			else cout<<"John"<<endl;
		}
	}
}
