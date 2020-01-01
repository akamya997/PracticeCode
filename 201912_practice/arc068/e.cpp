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
const int maxn=3e5+7;
struct Seg{
	int l,r;
	bool operator<(const Seg& a)const{
		return r-l>a.r-a.l;
	}
};
int ans[maxn];
int cf[maxn];
int tree[maxn];
void add(int x,int v)
{
	while(x<maxn)
	{
		tree[x]+=v;
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
	int n,m;
	cin>>n>>m;
	vc<Seg> seg(n);
	for(int i=0;i<n;i++)
	{
		cin>>seg[i].l>>seg[i].r;
		int len=seg[i].r-seg[i].l+1;
		cf[1]++;
		cf[len+1]--;
	}
	int cur=0;
	for(int i=1;i<=m;i++)
	{
		cur+=cf[i];
		ans[i]=cur;
	}
	sort(seg.begin(),seg.end());
	for(int i=1;i<=m;i++)
	{
	//	dbg(i,ans[i]);
		while(seg.size()&&seg.back().r-seg.back().l+1<i)
		{
			add(seg.back().l,1);
			add(seg.back().r+1,-1);
			seg.pop_back();
		}
		for(int j=i;j<=m;j+=i)
			ans[i]+=query(j);
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<'\n';

}
