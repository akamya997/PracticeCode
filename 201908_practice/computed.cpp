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
const int maxn=2e5+7;
map<int,int> pos;
int arr[maxn];
int var=10;
int main()
{
	int n;
	scanf("%d",&n);
	ll ans=0;
	for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
		x=arr[i];
        ans = (ans + 1LL * (i - pos[x]) * (n - i + 1) % mod * x % mod) % mod;
        pos[x] = i;
    }
	set<vector<int>> st;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=min(n,i+var);j++)
		{
			static vector<int> cur;
			cur.clear();
			for(int k=i;k<=j;k++)
			{
				cur.push_back(arr[k]);
			}
			if(st.count(cur))
			{
				ll tot=0;
				static set<int> tt;
				tt.clear();
				for(auto u:cur) tt.insert(u);
				for(auto u:tt) tot+=u;
				ans=(ans-tot+mod)%mod;
			}
			else st.insert(cur);
		}
	}
	printf("%lld\n",ans);
}
