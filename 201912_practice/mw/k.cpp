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
const int maxn=2e5+7;
int pre[maxn],suf[maxn];
int tree[maxn];
void add(int x)
{
	while(x<maxn)
	{
		tree[x]++;
		x+=x&-x;
	}
}
int query(int x)
{
	int ret=0;
	while(x)
	{
		ret+=tree[x];
		x-=x&-x;
	}
	return ret;
}
int main()
{
	int n,k;
	cin>>n>>k;
	vi a(n+1);
	vi all;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=k) all.push_back(a[i]);
	}
	ll ans=0;
	for(int i=0;i<all.size();i++)
	{
		ans+=i-query(all[i]);
		add(all[i]);
	}
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		cur+=(a[i]<=k);
		pre[i]=cur;
	}
	cur=0;
	for(int i=n;i>=1;i--)
	{
		cur+=(a[i]<=k);
		suf[i]=cur;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>k)
			ans+=min(pre[i],suf[i]);
	}
	cout<<ans<<endl;
}
