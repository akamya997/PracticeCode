#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n;
		scanf("%lld",&n);
		int nn=sqrt(n);
		if(1LL*nn*nn==n)
			puts("infty");
		else{
			if(n%4!=0)
			{
				puts("0 0");
			}
			else{
				n/=4;
				int cnt=0;
              	int u=sqrt(n);
				long long ans=0;
				for(int i=1;i<=u;i++)
				{
					if(n%i==0)
					{
						cnt++;
						ans=(ans+1LL*(1LL*i+n/i)*n%mod)%mod;
					}
				}
                printf("%d %lld\n",cnt,ans);
			}
		}
	}
}