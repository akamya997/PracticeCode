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

int main()
{
	int l,n,m;
	while(cin>>l>>n>>m)
	{
		vi d(n+2);
		d[0]=0;
		for(int i=1;i<=n;i++) cin>>d[i];
		d[n+1]=l;
		sort(d.begin(),d.end());
		int L=0,R=l,ans=-1;
		//for(int mid=L;mid<=R;mid++)
		while(L<=R)
		{
			int mid=L+R>>1;
			vi dp(n+2);
			int mx=INF;
			int lpos=0;
			for(int i=1;i<=n+1;i++)
			{
				while(lpos<i&&d[i]-d[lpos]>=mid) 
				{
					if(dp[lpos]!=INF)
						mx=min(mx,dp[lpos]-lpos);
					lpos++;
				}
				if(mx==INF) dp[i]=INF;
				else{
					dp[i]=mx+i-1;
				}
			}
			if(dp[n+1]<=m)
			{
				L=mid+1;
				ans=mid;
			}
			else R=mid-1;
		}
		cout<<ans<<'\n';
	}
}
