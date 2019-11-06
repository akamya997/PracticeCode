#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int mod=998244353;
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
const int maxn=1e5+7;
int block[maxn];
int arr[maxn];
ll sum[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int var=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		block[i]=i/var;
		sum[block[i]]+=arr[i];
	}
	while(m--)
	{
		int pos,val,l,r;
		cin>>pos>>val>>l>>r;
		sum[block[pos]]-=arr[pos];
		arr[pos]=val;
		sum[block[pos]]+=arr[pos];
		ll ans=0;
		for(int i=block[l]+1;i<=block[r]-1;i++)
			ans+=sum[i];
		int cur=l;
		if(block[l]==block[r])
		{
			for(int i=l;i<=r;i++)
				ans+=arr[i];
		}
		else{
			while(l<=n&&l/var==block[cur])
			{
				ans+=arr[l];
				l++;
			}
			cur=r;
			while(r&&r/var==block[cur])
			{
				ans+=arr[r];
				r--;
			}
		}
		cout<<ans<<'\n';
	}

}
