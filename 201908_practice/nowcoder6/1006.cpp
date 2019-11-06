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
char  s[maxn],t[maxn];
int fail[maxn];
void getfail()
{
    int len = strlen(t);
    int j = 0, k = fail[0] = -1;
    while (j < len)
    {
        while (k != -1 && t[j] != t[k])
            k = fail[k];
        fail[++j] = ++k;
    }
}

ll kmp()
{
    int  m = strlen(t);
	int n=m;
    int i = 1, j = 0;
    ll ret = 0;
    while (i < n)
    {
        while (j != -1 && t[i] != t[j])
        {
			dbg(i,j);
			ret+=j+1;
			j = fail[j];
		}
        i++, j++;
    }
	dbg(ret,j);
	while(j>0)
	{
		ret+=j;
		if(fail[j]==0) ret+=j-1;
		j=fail[j];
	}
    return ret;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",t);
		getfail();
		for(int i=0;i<=strlen(t);i++) dbg(i,fail[i]);
		printf("%lld\n",kmp());
	}
}
