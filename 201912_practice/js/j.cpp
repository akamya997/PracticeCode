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
const int maxn=5e5+7;
int h[maxn];
int pre[maxn];
int suf[maxn];
int pos[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&h[i]);
			pos[h[i]]=i;
		}
		int cc=0;
		for(int i=1;i<=n;i++)
		{
			if(pos[i]>cc)
				pre[i]=pre[i-1]+1;
			else pre[i]=1;
			cc=pos[i];
		}
		cc=n+1;
		suf[n+1]=0;
		for(int i=n;i>=1;i--)
		{
			if(pos[i]>cc)
				suf[i]=suf[i+1]+1;
			else suf[i]=1;
			cc=pos[i];
		}
		int ans=INF;
		for(int i=0;i<=n;i++)
		{
			dbg(i,i-pre[i],n-i-suf[i+1]);
			ans=min(ans,i-suf[i]+n-i-pre[i+1]);
		}
		cout<<ans<<'\n';
	}
}
