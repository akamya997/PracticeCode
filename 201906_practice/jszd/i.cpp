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
typedef unsigned long long ull;
const int maxn=1e6+7;
ull base=1e9+7;
ull pre[maxn];
ull hi[maxn];
int main()
{
	string s;
	cin>>s;
	hi[0]=1;
	for(int i=1;i<=s.length();i++)
	{
		hi[i]=hi[i-1]*base;
		pre[i]=pre[i-1]+s[i-1]*hi[i];
	//	dbg(i,pre[i]);
	}
	int cur=0,las=s.length();
	int len=1;
	int ans=0;
	for(int i=1;i<=s.length();i++)
	{
		if(i>las-len)
		{
			ans++;break;
		}
	//	dbg(i,cur,las,len,las-len-cur);
		if((pre[i]-pre[cur])*hi[las-len-cur]==pre[las]-pre[las-len])
		{
	//		dbg(i,cur,las,len);
			ans+=2;
			las=las-len;
			cur=i;
			len=1;
			if(las<cur+1) break;
		}
		else len++;
	}
	cout<<ans<<endl;
}
