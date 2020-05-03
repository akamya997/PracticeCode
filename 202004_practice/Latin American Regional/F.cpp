#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=5005;
typedef long long ll;
ll dp[maxn][maxn];
int main()
{
    int s,b;
    cin>>s>>b;
    dp[0][0]=1;
    for(int i=1;i<=s;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(i>=2&&j>=2) dp[i][j]=(2*dp[i-1][j-1]-dp[i-2][j-2]+mod)%mod;
            else dp[i][j]=dp[i-1][j-1];
            if(j>=i)
                dp[i][j]=(dp[i][j]+dp[i][j-i])%mod;
            //printf("i:%d j:%d dp[i][j]:%lld\n",i,j,dp[i][j]);
        }
    }
    cout<<dp[s][b]<<'\n';
}