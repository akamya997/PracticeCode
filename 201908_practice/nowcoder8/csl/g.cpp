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
const int maxn=105;
int arr[maxn];
int n;
inline int getsum()
{
	int ret=0;
	for(int i=0;i<n;i++) ret^=arr[i];
	return ret;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	if(getsum()==0) cout<<-1<<endl;
	else{
		while(true)
		{
			int sum=getsum();
			for(int i=0;i<n;i++)
			{
				if((arr[i]^sum)<arr[i])
				{
					cout<<i<<" "<<(arr[i]-(arr[i]^sum))<<endl;
					arr[i]^=sum;
					break;
				}
			}
			bool ok=1;
			for(int i=1;i<=n;i++)
			{
				if(arr[i]) {
					ok=0;
					break;
				}
			}
			if(ok) break;
			int id,val;
			cin>>id>>val;
			arr[id]-=val;
		}
	}
	
}
