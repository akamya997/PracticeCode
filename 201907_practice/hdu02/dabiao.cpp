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

ll N;
	mt19937 csl(time(NULL));

ll cal(vector<int> v)
{
	int sz=v.size();
	ll ans=0;
	for(int i=1;i<sz;i++)
		for(int j=0;j<i;j++)
			if(v[i]>v[j])	ans++;
	return ans;
}

ll work(vector<int> v)
{
//	for(auto x:v) cout<<x<<" ";
//	cout<<endl;
	int sz=v.size();
	ll cnt=0;
	if(sz>0)
	{
		cnt+=cal(v);
		vector<int> vv;
		for(int i=0;i<sz;i++)
			if((csl()%2)&1)
				vv.push_back(v[i]);
		cnt+=work(vv);
	}
	return cnt;
}

int TT=10000000;

ll NN;
int main()
{
	while(scanf("%lld",&NN)!=EOF)
	{
		ll ans=0;
		int T=TT;
		while(T--)
		{
			ll temp=csl()%NN+1;
			N=temp;
//			cout<<T<<":"<<endl;
			vector<int> v;
			for(int i=1;i<=N;i++)	v.push_back(i);
			random_shuffle(v.begin(),v.end());
			ans+=work(v);
//			cout<<"ans: "<<ans<<endl;
		}
		cout<<(double)ans/TT<<endl;
	}
}
