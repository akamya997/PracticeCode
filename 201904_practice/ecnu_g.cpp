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
void ask(int u1,int v1,int u2,int v2)
{
	cout<<u1<<" "<<v1<<" "<<u2<<" "<<v2<<endl;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int cnt=4;
		ask(1,2,1,3);
		int r1,r2;
		cin>>r1;
		ask(4,2,4,3);
		cin>>r2;
		if(r1!=r2)
		{
			ask(1,4,2,3);
			cin>>r1;
		}
		else{
			cnt++;
			int r3;
			ask(5,1,5,3);
			cin>>r3;

		}
		for(int i=cnt+1;i<=n;i++)
		{
			ask(i,1,i,4);
			cin>>r1;
		}
	}
}
