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
bool check(string cur)
{
	int l=0,r=0;
	for(int i=0;i<cur.size();i++)
	{
		if(cur[i]=='(') l++;
		else r++;
		if(r>l) return false;
	}
	return true;
}
int main()
{
	string s;
	cin>>s;
	string tmp;
	tmp=s;
	string ans1,ans2;
	while(next_permutation(s.begin(),s.end()))
	{
		if(check(s))
		{
			ans1=s;
			break;
		}
	}
	while(prev_permutation(tmp.begin(),tmp.end()))
	{
		if(check(tmp))
		{
			ans2=tmp;
			break;
		}
	}
	cout<<ans2<<endl;
	cout<<ans1<<endl;
}
