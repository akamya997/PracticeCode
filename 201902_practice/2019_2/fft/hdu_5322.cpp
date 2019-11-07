#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=1e5+7;
long long dp[maxn];
long long pret,prekt,prek2t;
long long fac[maxn];
long long quick(long long a,long long b)
{
	long long ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
long long inv(long long a)
{
	return quick(a,mod-2);
}
void db()
{
	fac[0]=1;
	for(int i=1;i<maxn;i++)
		fac[i]=fac[i-1]*i%mod;
}
void solve()
{
	db();
	dp[0]=pret=1;
	prekt=prek2t=0;
	for(int i=1;i<maxn;i++)
	{
		dp[i]=fac[i-1]*(pret*i%mod*i%mod-2LL*i*prekt%mod+mod+prek2t)%mod;
		long long t=dp[i]*inv(fac[i])%mod;
		pret=(pret+t)%mod;
		prekt=(prekt+1LL*i*t%mod)%mod;
		prek2t=(prek2t+1LL*i*i%mod*t%mod)%mod;
	}
}
int main()
{
	solve();
	int n;
	while(~scanf("%d",&n))
	{
		printf("%lld\n",dp[n]);
	}
}
