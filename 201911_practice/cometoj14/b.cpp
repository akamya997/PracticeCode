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
const int maxn=1e6+7;
int ok[maxn];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int pre[10];
		memset(pre,-1,sizeof(pre));
		if(s[0]=='p') ok[0]=1;
		else ok[0]=0;
		for(int i=1;i<n;i++)
		{
			ok[i]=ok[i-1];
			if(!ok[i]&&s[i]=='p') ok[i]=1;
			else if(ok[i]==1&&s[i]=='i') ok[i]++;
			else if(ok[i]==2&&s[i]=='n') ok[i]++;
			else if(ok[i]==3&&s[i]=='k') ok[i]++;
		}
		int ans=-1;
		for(int i=n-1;i>=0;i--)
		{
			if(s[i]=='k'&&pre[4]==-1)
				pre[4]=i;
			else if(s[i]=='n'&&pre[4]!=-1)
			{
				if(pre[3]==-1) pre[3]=i;
				if(ok[i]>=3)
					ans=max(ans,pre[4]-i-1);
			}
			else if(s[i]=='i'&&pre[3]!=-1)
			{
				if(pre[2]==-1) pre[2]=i;
				if(ok[i]>=2)
					ans=max(ans,pre[3]-i-1);
			}
			else if(s[i]=='p'&&pre[2]!=-1)
			{
				if(pre[1]==-1) pre[1]=i;
				ans=max(ans,pre[2]-i-1);
			}
		}
		cout<<ans<<'\n';
	}
}
