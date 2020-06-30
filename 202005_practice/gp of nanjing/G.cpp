#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;

const int maxn=505;
double dp[maxn][maxn*2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,a,b;
    cin>>n>>a>>b;
    vi x(n+1);
    for(int i=1;i<=n;i++) cin>>x[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>=1;j--)
        {
            for(int k=x[i];k<maxn*2;k++)
            {
                double p=1.0/(n-j+1);
                dp[j][k]+=dp[j-1][k-x[i]]*j*p;
                //dbg(i,j,k,dp[j][k]);
            }
        }
    }
    double ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=x[i];k<maxn*2;k++)
            {
                double p=1.0/(n-j+1);
                dp[j][k]-=dp[j-1][k-x[i]]*j*p;
            }
        }
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<=a;k++)
            {
                if(k+x[i]>a&&k+x[i]<=b)
                {
                    double p=1.0/(n-j);
                    ans+=dp[j][k]*p;
                }
            }
        }
        for(int j=n;j>=1;j--)
        {
            for(int k=x[i];k<maxn*2;k++)
            {
                double p=1.0/(n-j+1);
                dp[j][k]+=dp[j-1][k-x[i]]*j*p;
            }
        }
    }
    cout<<fixed<<setprecision(10);
    cout<<ans<<'\n';
}