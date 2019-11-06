#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
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
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
ll v;
int a[70];
PII dp[65][65][75];
bool vis[65][65][75];
ll two[66];
PII dfs(int pos,int cnt,bool limit)
{
	if(cnt>v) return {0,0};
	if(pos==-1) return {cnt==v,0LL};
	if(!limit&&vis[pos][cnt][v]) return dp[pos][cnt][v];
	PII	ret={0,0};
	int up=limit?a[pos]:1;
	for(int i=0;i<=up;i++)
	{
		PII cur=dfs(pos-1,cnt+(i==1),limit&&i==up);
		ret.first+=cur.first;
		ret.second=(ret.second+i*cur.first%mod*two[pos]%mod+cur.second)%mod;
	}
	if(!limit)
	{
		vis[pos][cnt][v]=1;
		dp[pos][cnt][v]=ret;
	}
	return ret;
}
PII solve(ll cur)
{
	int pos=0;
	while(cur)
	{
		a[pos++]=cur%2;
		cur/=2;
	}
	return dfs(pos-1,0,1);
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	two[0]=1;
	for(int i=1;i<66;i++) two[i]=two[i-1]*2%mod;
	int T;
	cin>>T;
	while(T--)
	{
		ll l,r;
		cin>>l>>r>>v;
		if(v>70)
			cout<<"0 0\n";
		else{
			PII R=solve(r);
			PII L=solve(l-1);
			cout<<R.first-L.first<<" "<<(R.second-L.second+mod)%mod<<'\n';
		}
	}
}
