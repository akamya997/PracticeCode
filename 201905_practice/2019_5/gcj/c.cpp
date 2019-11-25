#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=15;
int a[maxn],b[maxn];
int n;
bool ok(int x,int y)
{
	int pre=0;
	for(int i=0;i<n;i++)
	{
		int cur=a[i]*x+b[i]*y;
		if(cur<=pre) return false;
		pre=cur;
	}
	return true;
}
int main()
{
	int T,kas=0;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i]>>b[i];
		int ans1=-1,ans2=0;
		for(int i=0;i<=2000;i++)
		{
			for(int j=0;j<=2000;j++)
			{
				if(ok(i,j))
				{
					ans1=i,ans2=j;
					break;
				}
			}
			if(ans1!=-1) break;
		}
		cout<<"Case #"<<++kas<<": ";
		if(ans1==-1)
			cout<<"IMPOSSIBLE"<<endl;
		else cout<<ans1<<" "<<ans2<<endl;
	}
}
