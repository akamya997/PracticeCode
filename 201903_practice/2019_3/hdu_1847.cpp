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
int sg[1010];
int two[20];
void db()
{
	two[0]=1;
	sg[0]=0;
	for(int i=1;i<20;i++) two[i]=two[i-1]*2;
	for(int i=1;i<1005;i++)
	{
		set<int> s;
		s.insert(sg[i-1]);
		for(int j=0;j<20;j++)
		{
			int to=i-(1<<j);
			if(to<0) break;
			s.insert(sg[to]);
		}
		int cur=0;
		while(s.count(cur)) cur++;
		sg[i]=cur;
	}
	for(int i=1;i<=70;i++) if(!sg[i]) cout<<i<<endl;
}
int main()
{
	int n;
//	db();
	while(cin>>n)
	{
		if(n%3==0) cout<<"Cici"<<endl;
		else cout<<"Kiki"<<endl;
	}
}
