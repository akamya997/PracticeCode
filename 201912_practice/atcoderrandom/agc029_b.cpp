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

int main()
{
	int n;
	cin>>n;
	multiset<int> all;
	for(int i=0,tmp;i<n;i++)
	{
		cin>>tmp;
		all.insert(tmp);
	}
	int ans=0;
	while(all.size())
	{
		auto cur=all.rbegin();
		int val=*cur;
		all.erase(all.find(*cur));
		for(int i=0;i<31;i++)
		{
			if((1<<i)<=val) continue;
			if(all.count((1<<i)-val))
			{
				all.erase(all.find((1<<i)-val));
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
