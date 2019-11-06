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
const int maxn=5e5+7;
void getfail(char *t,int *fail)
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
bool isloop(int *fail,int i)
{
	return fail[i]*2>=i&&i%(i-fail[i])==0;
}
char t2[maxn];
char t[maxn];
int fail[maxn];
int f2[maxn];
int main()
{
	scanf("%s",t);
	getfail(t,fail);
	int len=strlen(t);
	if(!isloop(fail,len))
		puts("1\n1");
	else if(len-fail[len]==1)
		printf("%d\n%d\n",len,1);
	else{
		int ans=0;
		for(int i=0;i<len;i++)
			t2[i]=t[len-1-i];
		t2[len]='\0';
		getfail(t2,f2);
		for(int i=1;i<len;i++)
		{
			if(!isloop(fail,i)&&!isloop(f2,len-i))
				 ans++;
		}
		printf("%d\n%d\n",2,ans);
	}

}
