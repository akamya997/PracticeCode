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
const int maxn=2e5+7;
int main()
{
	int h,w,n;
	cin>>h>>w>>n;
	int stx,sty;
	cin>>stx>>sty;
	string s,t;
	cin>>s>>t;
	bool ok=1;
	int miny=sty,maxy=sty,minx=stx,maxx=stx;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='L') maxy--;
		else if(s[i]=='R') miny++;
		else if(s[i]=='U') maxx--;
		else if(s[i]=='D') minx++;
		if(miny>w||maxy<=0||minx>h||maxx<=0)
		{
			ok=0;break;
		}
		if(t[i]=='L') miny=max(1,miny-1);
		else if(t[i]=='R') maxy=min(w,maxy+1);
		else if(t[i]=='U') minx=max(1,minx-1);
		else maxx=min(h,maxx+1);
	}
	if(ok) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
