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
const int maxn=2e5+7;
int fa[3][maxn];
int Find(int tp,int x)
{
	return x==fa[tp][x]?x:fa[tp][x]=Find(tp,fa[tp][x]);
}
void Union(int tp,int x,int y)
{
	x=Find(tp,x);y=Find(tp,y);
	fa[tp][x]=y;
}
map<PII,int> cnt;
int main()
{
	int n,k,l;
	cin>>n>>k>>l;
	for(int i=0;i<=n;i++) fa[0][i]=fa[1][i]=i;
	for(int i=0,p,q;i<k;i++)
	{
		cin>>p>>q;
		Union(0,p,q);
	}
	for(int i=0,r,s;i<l;i++)
	{
		cin>>r>>s;
		Union(1,r,s);
	}
	for(int i=1;i<=n;i++)
	{
		int u=Find(0,i),v=Find(1,i);
		cnt[make_pair(u,v)]++;
	}
	for(int i=1;i<=n;i++)
	{
		int u=Find(0,i),v=Find(1,i);
		cout<<cnt[make_pair(u,v)]<<" ";
	}
	cout<<'\n';
}
