#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int row[maxn],dp[maxn];
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&row[j]);
				if(j==1) row[j]=max(row[j],row[j-1]);
				if(j>=2)
					row[j]=max(row[j-2]+row[j],row[j-1]);
			}
			dp[i]=row[m-1];
		}
		dp[1]=max(dp[0],dp[1]);
		for(int i=2;i<n;i++)
		{
			dp[i]=max(dp[i-2]+dp[i],dp[i-1]);
		}
		printf("%d\n",dp[n-1]);
	}
}
