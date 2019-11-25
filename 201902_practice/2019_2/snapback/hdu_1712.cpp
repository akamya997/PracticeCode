#include<bits/stdc++.h>
using namespace std;
int mat[105][105];
int dp[105];
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)&&(n+m))
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ignore=scanf("%d",&mat[i][j]);
		memset(dp,0,sizeof(dp));
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int k=m;k>=0;k--)
			{
				for(int j=0;j<=k;j++)
				{
					dp[k]=max(dp[k-j]+mat[i][j],dp[k]);
				}
			}
		}
		printf("%d\n",dp[m]);
	}

}
