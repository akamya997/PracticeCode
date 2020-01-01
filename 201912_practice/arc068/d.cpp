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
typedef pair<int,int> pi;
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
int cnt[maxn];
int a[maxn];
vc<pi> all;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int cc=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i-1])
		{
			all.emplace_back(a[i-1],cc);
		//	dbg(a[i-1],cc);
			cc=1;
		}
		else cc++;
	}
	all.emplace_back(a[n-1],cc);
	int l=0,r=all.size()-1;
	int ans=0;
	while(l<r)
	{
		while(l<r&&all[l].second==1) ans++,l++;
		while(l<r&&all[r].second==1) r--,ans++;
		if(l<r)
		{
			all[l].second--;
			all[r].second--;
		}
	//	dbg(l,r,ans);
	}
	if(l==r)
	{
		if(all[l].second&1) ans++;
	}
	cout<<ans<<endl;

}
