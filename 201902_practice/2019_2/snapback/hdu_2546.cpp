#include<bits/stdc++.h>
using namespace std;
int v[105];
int dp[1105];
int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++)
			ignore=scanf("%d",&v[i]);
		sort(v+1,v+n+1);
		int m;
		ignore=scanf("%d",&m);
		m+=100;
		memset(dp,0,sizeof(dp));
		dp[m]=1;
		int ans=m-100;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				if(j+v[i]<105) continue;
				dp[j]=(dp[j+v[i]]|dp[j]);
				if(dp[j])
					ans=min(ans,j-100);
			}
		}
		printf("%d\n",ans);
	}
}
