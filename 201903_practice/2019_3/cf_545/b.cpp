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
vector<int> zz,zo,oz,oo;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s1,s2;
	cin>>n>>s1>>s2;
	for(int i=0;i<n;i++)
	{
		if(s1[i]=='0'&&s2[i]=='0') zz.push_back(i+1);
		else if(s1[i]=='0'&&s2[i]=='1') zo.push_back(i+1);
		else if(s1[i]=='1'&&s2[i]=='0') oz.push_back(i+1);
		else oo.push_back(i+1);
	}
	deque<int> p1,p2;
	int cnt1=oz.size(),cnt2=zo.size();
	int cntt1=cnt1,cntt2=cnt2;
	for(auto &p:zo) p2.push_back(p);
	for(auto &p:oz) p1.push_back(p);
	for(auto &p:oo)
	{
		if(p1.size()<p2.size())
		{
			p1.push_back(p);
			cntt1++;
		}
		else 
		{
			p2.push_back(p);
			cntt2++;
		}
	}
	while(cntt1<cntt2&&cnt2)
	{
		cnt2--;
		cntt2--;
		p1.push_back(p2[0]);
		p2.pop_front();
	}
	while(cntt1>cntt2&&cnt1)
	{
		cnt1--;
		cntt1--;
		p2.push_back(p1[0]);
		p1.pop_front();
	}
	dbg(p1);dbg(p2);
	if(p1.size()>n/2||p2.size()>n/2) cout<<-1<<endl;
	else{
		for(auto &p:zz)
		{
			if(p1.size()<n/2) p1.push_back(p);
			else p2.push_back(p);
		}
		for(auto &p:p1) cout<<p<<" ";
		cout<<endl;
	}
		

}
