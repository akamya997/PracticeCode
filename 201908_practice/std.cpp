#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int to,w;
};
vector<Edge> G[14];
long long dp[1<<14][14];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1,u,v,w;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        u--,v--;
        G[u].push_back(Edge{v,w});
        G[v].push_back(Edge{u,w});
    }
    memset(dp,-0x3f,sizeof(dp));
    for(int i=0;i<n;i++) 
    {
        dp[0][i]=0;
        dp[1<<i][i]=0;
    }
    for(int i=1;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            //cout<<(i&(1<<j))<<endl;
            if(!(i&(1<<j))) continue;
            for(int k=0;k<G[j].size();k++)
            {
                Edge v=G[j][k];
                if(!(i&(1<<v.to))) continue;
                for(int T=i;T!=0;T=(T-1)&i)
                {
                    if(!(T&(1<<v.to))||(T&(1<<j))) continue;
                    int num=__builtin_popcount(T);
                    dp[i][j]=max(dp[i-T][j]+dp[T][v.to]+1LL*v.w*num*(n-num),dp[i][j]);
                }
            }
            //cout<<i<<","<<j<<":"<<dp[i][j]<<endl;
        }
    }
    printf("%lld\n",dp[(1<<n)-1][0]);
 
}
