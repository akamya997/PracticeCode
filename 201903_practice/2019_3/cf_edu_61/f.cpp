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
int dp[505][505];
vector<int> arr;
int main()
{
	memset(dp,0x3f,sizeof(dp));
	int n;
	cin>>n;
	string s;
	cin>>s;
	arr.push_back(s[0]-'a');
	for(int i=0;i<n;i++)
		if(s[i]-'a'!=arr.back()) arr.push_back(s[i]-'a');
	for(int i=0;i<arr.size();i++) dp[i][i]=1;
	dbg(arr);
	for(int len=2;len<=arr.size();len++)
	{
		for(int l=0,r=len-1;r<arr.size();l++,r++)
		{
			for(int k=l;k<r;k++)
			{
				dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]-(arr[l]==arr[r]));
			}
			dbg(l);dbg(r);dbg(dp[l][r]);
		}
	}
	cout<<dp[0][arr.size()-1]<<endl;
}
