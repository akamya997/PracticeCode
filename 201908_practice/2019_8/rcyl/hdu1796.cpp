#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int lcm(int a,int b)
{
	return a/__gcd(a,b)*b;
}
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		vector<int> tot;
		for(int i=1,tmp;i<=m;i++)
		{
			scanf("%d",&tmp);
			tot.push_back(tmp);
		}
		ll ans=0;
		for(int i=1;i<(1<<m);i++)
		{
			ll cur=1;
			for(int j=0;j<m;j++)
			{
				if(i>>j&1)
					cur=lcm(cur,tot[j]);
			}
			if(__builtin_popcount(i)&1) cur*=1;
			else cur*=-1;
			if(!cur) continue;
			ans+=(n-1)/cur;
		}
		printf("%lld\n",ans);

	}
}
