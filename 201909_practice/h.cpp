#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int maxn=1e5+7;
const long long INF=0x3f3f3f3f3f3f3f3f;
int arr[maxn];
long long dp[maxn][6];
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	memset(dp,0x3f,sizeof(dp));
	string s1="wrong";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=dp[0][4]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(s[i-1]==s1[j])
			{
				if(j==0) dp[i][j]=dp[i-1][j]+arr[i-1];
				else dp[i][j]=min(dp[i-1][j]+arr[i-1],dp[i-1][j-1]);
			}
			else dp[i][j]=dp[i-1][j];
			//cout<<i<<","<<j<<":"<<dp[i][j]<<endl;
		}
	}
	long long ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<5;i++)
		ans=min(ans,dp[n][i]);
	cout<<ans<<endl;
}
