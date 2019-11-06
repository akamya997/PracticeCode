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
string s;
const int maxn=1e4+7;
int dp[maxn][12][12];
int dfs(int pos,int a,int b)
{
	int ret=0;
	if(pos==s.length())
		return 0;
	if(dp[pos][a][b]!=-1) return dp[pos][a][b];
	if(s[pos]=='A')
	{
		int na=a+1;
		if(na==10&&b==10)
			ret=dfs(pos+1,9,9);
		else{
			if(na==11)
				ret=dfs(pos+1,0,0)+1;
			else ret=dfs(pos+1,na,b);
		}
	}
	else if(s[pos]=='B')
	{
		int nb=b+1;
		if(nb==10&&a==10) ret=dfs(pos+1,9,9);
		else{
			if(nb==11)
				ret=dfs(pos+1,0,0)+1;
			else ret=dfs(pos+1,a,nb);
		}
	}
	else{
		int na=a+1,nb=b+1;
		int ret1=0;
		if(na==10&&b==10)
			ret1=dfs(pos+1,9,9);
		else{
			if(na==11)
				ret1=dfs(pos+1,0,0)+1;
			else ret1=dfs(pos+1,na,b);
		}
		int ret2=0;
		if(nb==10&&a==10) ret2=dfs(pos+1,9,9);
		else{
			if(nb==11)
				ret2=dfs(pos+1,0,0)+1;
			else ret2=dfs(pos+1,a,nb);
		}
		ret=max(ret1,ret2);
	}
	return dp[pos][a][b]=ret;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(dp,-1,sizeof(dp));
		cin>>s;
		cout<<dfs(0,0,0)<<endl;
	}
}
