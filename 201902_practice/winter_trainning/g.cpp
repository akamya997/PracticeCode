#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxk=1e5+7;
long long fac[maxk];
void db()
{
	fac[0]=1;
	for(int i=1;i<maxk;i++) fac[i]=fac[i-1]*i%mod;
}
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

long long inv(long long a){return quick(a,mod-2);}
long long C(int n,int m)
{
	return fac[n]*inv(fac[n-m])%mod*inv(fac[m])%mod;
}

int main()
{
	db();
	int T;
	ignore=scanf("%d",&T);
	while(T--)
	{
		int n,k;
		ignore=scanf("%d%d",&n,&k);
		if(k%2!=0) puts("0");
		else{
			long long ans=0;
			long long base=C(k,k/2);
			for(int i=0;i<=k/2;i++)
				ans=(ans+base*C(k/2,i)%mod)%mod;
			printf("%lld\n",ans);
		}
	}
}
