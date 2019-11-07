#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
int ans[50],cnt[maxn];
int arr[maxn];
int dp[maxn];
int main()
{
	int T;
	ignore=scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		int n,m;
		ignore=scanf("%d%d",&n,&m);
		for(int i=0;i<m+1;i++)
			ignore=scanf("%d",&arr[i]);
		int cur=0;
		dp[0]=1;
		for(int i=1;i<=m;i++)
		{
			cnt[i]=arr[i]-dp[i];
			for(int k=0;k<cnt[i];k++)
			{
				ans[++cur]=i;
				for(int j=m;j>=i;j--)
					dp[j]=dp[j]+dp[j-i];
			}
		}
		printf("%d",ans[1]);
		for(int i=2;i<=cur;i++)
			printf(" %d",ans[i]);
		puts("");
	}
}
