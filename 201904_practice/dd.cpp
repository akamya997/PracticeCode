#include<bits/stdc++.h>
using namespace std;
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
const int maxn=1e5+7;
bool ext[100];
bool las[maxn];
int main()
{
	string s;
	cin>>s;
	for(int i=s.length()-1;i>=0;i--)
	{
		int id=s[i]-33;
		if(!ext[id])
		{
			ext[id]=1;
			las[i]=1;
		}
	}
	memset(ext,0,sizeof(ext));
	int l=0,r=0;
	string ans;
	while(r<s.length())
	{
		int id=s[r]-33;
		if(las[r]&&!ext[id])
		{
			deque<char> st;
			while(l<r)
			{
				if(ext[s[l]-33]) {l++;continue;}
				while(!st.empty()&&st.back()>=s[l])
				{
					ext[st.back()-33]=0;
					st.pop_back();
				}
				st.push_back(s[l]);
				ext[s[l]-33]=1;
				l++;
			}
			if(ext[id])
			{
				while(!st.empty())
				{
					ans+=st.front();
					st.pop_front();
				}
				l++;
				r++;
				continue;
			}
			while(!st.empty()&&st.back()>=s[l])
			{
				ext[st.back()-33]=0;
				st.pop_back();
			}
			st.push_back(s[l]);
			ext[s[l]-33]=1;
			l++;
			while(!st.empty())
			{
				ans+=st.front();
				st.pop_front();
			}
		}
		r++;
		dbg(ans);
	}
	cout<<ans<<endl;
}
