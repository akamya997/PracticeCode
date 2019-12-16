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
unordered_map<ll,ll> cnt;
ll org;
ll getcnt(ll x)
{
	if(x>org) return 0;
	if(cnt.count(x)) return cnt[x];
	ll ret=0;
	if(x&1) ret=getcnt(x*2)+1;
	else ret=1+getcnt(x*2)+getcnt(x+1);
	return cnt[x]=ret;
}
int main()
{
	ll n,k;
	cin>>n>>k;
	ll ans=1;
	org=n;
	while(n)
	{
		const int var=1;
		for(int i=-var;i<=var;i++)
		{
			ll cur=n+i;
			if(cur<=0||cur>org) continue;
			ll ccc=getcnt(cur);
			if(ccc>=k) ans=max(ans,cur);
		}
		n/=2;
	}
	cout<<ans<<endl;
}
