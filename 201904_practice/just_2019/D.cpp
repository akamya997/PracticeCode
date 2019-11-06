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
int dp[11][11][11][11];
int up[5];
int two[11];
int dfs(int pos,int a,int b,int c)
{
	if(pos==-1) 
	{
		if(a!=up[0]||b!=up[1]||c!=up[2]) return -0x3f3f3f3f;
		return 0;
	}
	if(dp[pos][a][b][c]!=-1) return dp[pos][a][b][c];
	int ret=-0x3f3f3f3f;
	for(int i=0;i<8;i++)
	{
		int na=a+((i&4)==4),nb=b+((i&2)==2),nc=c+(i&1);
		if(na>up[0]||nb>up[1]||nc>up[2]) continue;
		ret=max(ret,dfs(pos-1,na,nb,nc)+(i==1||i==2||i==4||i==7)*two[pos]);
	}
	return dp[pos][a][b][c]=ret;
}
int main()
{
	int T;
	two[0]=1;
	for(int i=1;i<11;i++)
		two[i]=two[i-1]*2;
	cin>>T;
	while(T--)
	{
		memset(dp,-1,sizeof(dp));
		string a[3];
		for(int i=0;i<3;i++)
			cin>>a[i];
		memset(up,0,sizeof(up));
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<10;j++)
				up[i]+=(a[i][j]=='1');
		}
		int ans=dfs(9,0,0,0);
		string op;
		for(int i=9;i>=0;i--)
		{
			if(ans&(1<<i)) op+='1';
			else op+='0';
		}
		cout<<op<<endl;
	}
}
