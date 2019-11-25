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
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	set<string> st;
	long long ans;
	int var=30;
	if(m>var)
	{
		ans=0;
		for(int i=m;i<=n;i++)
		{
			ans+=n-(i-1);
		}
	}
	else{
		for(int i=0;i<n;i++)
		{
			string cur="";
			for(int j=0;j<var&&i+j<n;j++)
			{
				cur+=s[i+j];
				if(j+1>=m)
					st.insert(cur);
			}
		}
		ans=(long long)st.size();
		for(int i=var+1;i<=n;i++)
		{
			ans+=n-(i-1);
		}
	}
	cout<<ans<<endl;
}
