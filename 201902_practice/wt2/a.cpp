#include<bits/stdc++.h>
using namespace std;
const int maxn=(1e6+7)/3;
const int mod=1e9+7;
long long dp[maxn][9];
void db()
{
	dp[1][1]=1;
	for(int i=2;i<maxn;i++)
	{
		for(int j=1;j<=8;j++)
			dp[i][1]=(dp[i][1]+dp[i-1][j])%mod;
		for(int j=2;j<=8;j++)
		{
			dp[i][j]=dp[i-1][j-1];
		}
	}
}
int main()
{
	db();
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		n/=3;
		long long ans=0;
		for(int i=1;i<=8;i++) ans=(ans+dp[n][i])%mod;
		cout<<ans<<endl;
	}
}
