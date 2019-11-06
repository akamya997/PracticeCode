#include <iostream>
#include <cstring>
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
int cnt[1005];
int main()
{
	int n;
	while(cin>>n&&n)
	{
		memset(cnt,0,sizeof(cnt));
		int sum=0;
		for(int i=0,tmp;i<n;i++)
		{
			cin>>tmp;
			cnt[tmp]++;
		}
		for(int i=0;i<1005;i++) if(cnt[i]&1) sum++;
		if(sum) cout<<1<<endl;
		else cout<<0<<endl;
	}
}
