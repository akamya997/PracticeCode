#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=4005;
int n,dp[N][N],f[N][N],g[N][N],fw[N],fb[N];
struct node
{
    char c;
    int x;
}a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
        scanf(" %c %d",&a[i].c,&a[i].x);
        if(a[i].c=='W') fw[a[i].x]=i;
        else fb[a[i].x]=i;
    }
    for(int i=1;i<=2*n;i++)
    {
        for(int j=0;j<=n;j++)
            f[i][j]=f[i-1][j],g[i][j]=g[i-1][j];
        for(int j=a[i].x-1;j>=0;j--)
            if(a[i].c=='W') f[i][j]++;
        else g[i][j]++;
    }
    memset(dp,inf,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
    {
        if(i+1<=n)
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+f[fw[i+1]][i]+g[fw[i+1]][j]-1);
        if(j+1<=n)
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]+f[fb[j+1]][i]+g[fb[j+1]][j]-1);
    }
    printf("%d\n",dp[n][n]);
}
