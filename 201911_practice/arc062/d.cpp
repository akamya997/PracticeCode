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
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int INF=0x3f3f3f3f;
const int maxn=1e5+7;
int pre[maxn];
int main()
{
	string s;
	cin>>s;
	for(int i=1;i<=s.length();i++)
	{
		if(s[i-1]=='g')
			pre[i]=pre[i-1]+1;
		else pre[i]=pre[i-1]-1;
	//	dbg(i,pre[i]);
	}
	int mx=INF;
	int ans=0;
	for(int i=s.length();i>0;i--)
	{
		mx=min(mx,pre[i]);
		if(mx>=2&&s[i-1]=='g')
		{
			mx-=2;
			ans++;
		}
	}
	cout<<ans<<endl;
}
