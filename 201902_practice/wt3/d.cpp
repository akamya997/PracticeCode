#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=1e5+7;
long long fac[maxn];
void db()
{
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
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
	if(n<m) return 0;
	return fac[n]*inv(fac[m])%mod*inv(fac[n-m])%mod;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	db();
	int T;
	cin>>T;
	while(T--)
	{
		int a,b;
		cin>>a>>b;
		long long ans=C(a-1,b)*2LL%mod;
		cout<<ans<<'\n';
	}
}
