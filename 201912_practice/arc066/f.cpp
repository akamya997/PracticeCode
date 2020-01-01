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
ll pre[maxn],suf[maxn];
ll T[maxn];
ll S[maxn];
ll dp[maxn];
int dq[maxn];
inline ll f(int x)
{
	return dp[x]+S[x]+x*(x-1)/2;
}
inline bool down(int i,int j,int k)
{
	return (f(k)-f(j))*(j-i)>=(f(j)-f(i))*(k-j);
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>T[i];
		S[i]=S[i-1]+T[i];
	}
	{
		int sz=0;
		dq[++sz]=0;
		for(int i=1;i<=n;i++)
		{
			while(sz>=2&&f(dq[sz])-f(dq[sz-1])<=i*(dp[sz]-dq[sz-1]))
				sz--;
			int id=dq[sz];
			dp[i]=max(dp[i-1],dp[id]-(S[i]-S[id])+(i-id)*(i-id+1)/2);
			while(sz>=2&&down(dq[sz-1],dq[sz],i)) sz--;
			dq[++sz]=i;
			pre[i]=dp[i];
		}
	}
	{
		int sz=0;
		dq[++sz]=0;
		for(int i=1;i<=n/2;i++)
		{
			swap(T[i],T[n-i+1]);
			S[i]=S[i-1]+T[i];
		}
		for(int i=1;i<=n;i++)
		{
			while(sz>=2&&f(dq[sz])-f(dq[sz-1])<=i*(dp[sz]-dq[sz-1]))
				sz--;
			int id=dq[sz];
			dp[i]=max(dp[i-1],dp[id]-(S[i]-S[id])+(i-id)*(i-id+1)/2);
			while(sz>=2&&down(dq[sz-1],dq[sz],i)) sz--;
			dq[++sz]=i;
			suf[n-i+1]=dp[i];
		}
	}

}
