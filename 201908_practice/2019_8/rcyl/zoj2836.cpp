#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=15;
int arr[maxn];
int lcm(int a,int b)
{
	return a/__gcd(a,b)*b;
}
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		ll ans=0;
		for(int i=1;i<(1<<n);i++)
		{
			int cur=1;
			for(int j=0;j<n;j++)
			{
				if(i>>j&1)
					cur=lcm(cur,arr[j]);
			}
			if(__builtin_popcount(i)&1) cur*=1;
			else cur*=-1;
			ans+=m/cur;
		}
		printf("%lld\n",ans);
	}
}
