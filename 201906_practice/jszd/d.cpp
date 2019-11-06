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
vector<int> ch[27];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	int k;
	cin>>k;
	for(int i=0;i<s.length();i++)
		ch[s[i]-'a'].push_back(i);
	for(int i=0;i<27;i++) reverse(ch[i].begin(),ch[i].end());
	int pos=-1;
	string ans;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<26;j++)
		{
			while(ch[j].size()&&ch[j].back()<pos) ch[j].pop_back();
			if(ch[j].size()&&s.length()-ch[j].back()>=k-i)
			{
				pos=ch[j].back();
				ch[j].pop_back();
				ans+=j+'a';
				break;
			}
		}
	}
	cout<<ans<<endl;
}
