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
const int maxn=2e3+7;
const int mod=1e9+7;
ll quick(ll a,ll b)
{
	if(b<0) return 1;
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll dp[maxn][maxn];
int main()
{
	int n,k;
	cin>>n>>k;
	dp[0][n+1]=1;
	for(int i=1;i<=k;i++)
	{
		vc<ll> suf(n+3);
		for(int j=n-i+1+(i==1);j>=1;j--)
			suf[j]=(suf[j+1]+dp[i-1][j])%mod;
		for(int j=1;j<=n-i+1;j++)
		{
			//dp[i][j]=suf[j+1];
			dp[i][j]=(suf[j+1]+dp[i-1][j])%mod;
	//		dbg(i,j,dp[i][j]);
		}
	}
	cout<<dp[k][1]*quick(2,n-k-1)%mod<<endl;
}
