#include<bits/stdc++.h>
using namespace std;
const int maxn=4e3+7;
int dp[maxn][maxn];
const int mod=1e9+7;
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<=n+m;i++)
            for(int j=0;j<=n+m;j++)
                dp[i][j]=0;
		dp[0][0]=1;
		for(int i=0;i<=n+m;i++)
		{
			for(int j=0;j<=n+m;j++)
			{
				if(i<n||i-j<n)
					dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
				if(j<m||j-i<m)
					dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
			}
		}
        printf("%d\n",dp[n+m][n+m]);
    }
    
}
