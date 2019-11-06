#include<bits/stdc++.h>
using namespace std;
int dp[22][1005];
int maze[22][1005];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		memset(dp,-0x3f,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&maze[i][j]);
			}
		}
		dp[1][1]=maze[1][1];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==1&&i==j) continue;
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])+maze[i][j];
				int temp=-0x3f;
				for(int k=1;k<j;k++)
				{
					if(j%k==0) temp=max(temp,dp[i][k]);
				}
				temp+=maze[i][j];
				dp[i][j]=max(dp[i][j],temp);
			}
		}
		printf("%d\n",dp[n][m]);
	}
}
