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
const int maxn=1e3+7;
bool ok[maxn][maxn];
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	int ans=0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			ok[i][j]=1;
			ans++;
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		for(int i=-1;i<=0;i++)
		{
			for(int j=-1;j<=0;j++)
			{
				ans-=ok[x+i][y+j];
				ok[x+i][y+j]=0;
			}
		}
		cout<<ans<<endl;
	}
}
