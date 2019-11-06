#include<bits/stdc++.h>
using namespace std;
long long dp[101][101][5001];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		for(int i=0;i<101;i++)
			for(int j=0;j<5001;j++)
				dp[0][i][j]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			long long a,b,c;
			scanf("%lld%lld%lld",&a,&b,&c);
			for(int j=0;j<=n-i+1;j++)
			{
				for(int k=(1+j)*j/2;k<=(1+j)*j/2+(n-i+1-j)*j&&k<=5000;k++)
				{
					dp[i][j][k]=max(dp[i-1][j+1][k+j+1]+a,max(dp[i-1][j][k+j]+k*b,dp[i-1][j][k+j]+j*c));
				}
			}
		}
		printf("%lld\n",dp[n][0][0]);
	}
}
