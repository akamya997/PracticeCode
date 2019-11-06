#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=1e5+7;
long long pre[maxn];
long long arr[maxn];
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
void db(int n,int k)
{
	pre[0]=0;
	pre[1]=k;
	for(int i=2;i<n+2;i++)
	{
		pre[i]=(pre[i-1]+i*(quick(i,k)-1)*quick(i-1,mod-2)%mod)%mod;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k,x1,y1,c,d,e1,e2,f;
		scanf("%d%d%d%d%d%d%d%d%d",&n,&k,&x1,&y1,&c,&d,&e1,&e2,&f);
		db(n,k);
		arr[1]=x1+y1;
		for(int i=2;i<=n;i++)
		{
			int nx=(1LL*c*x1+1LL*d*y1+e1)%f,ny=(1LL*d*x1+1LL*c*y1+e2)%f;
			arr[i]=(nx+ny)%f;
			x1=nx,y1=ny;
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=(ans+1LL*(n-i+1)*arr[i]%mod*pre[i]%mod)%mod;
		}
		printf("%lld\n",ans);

	}
}
