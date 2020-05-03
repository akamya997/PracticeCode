#include<bits/stdc++.h>
using namespace std;
const int maxn=255;
int t[maxn][maxn];
struct Edge{
    int to,w;
};
int G[30][30];
int d[30][30];
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) 
        {
            if(i!=j)
                G[i][j]=10000;
        }
    for(int i=1;i<=m;i++)
    {
        string s;
        for(int j=1;j<=n;j++)
        {
            cin>>s;
            if(s[0]=='X') t[i][j]=-1;
            else{
                int v=0;
                for(auto u:s) v=v*10+u-'0';
                t[i][j]=v;
            }
        }
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(j==k||t[i][j]==-1||t[i][k]==-1) continue;
                if(t[i][j]>t[i][k]) G[j][k]=t[i][j]-t[i][k];
                else if(t[i][j]<t[i][k]) G[k][j]=t[i][k]-t[i][j];
                else
                    G[j][k]=G[k][j]=0;
            }
        }
    }
    int ans=1e9;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            d[i][j]=G[i][j];
            //if(i!=j&&i>0&&j>0)
                //ans=min(ans,G[i][j]+G[j][i]);
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<k;i++)
        {
            for(int j=1;j<k;j++)
            {
                if(d[i][j]+G[j][k]+G[k][i]!=0)
                    ans=min(ans,d[i][j]+G[j][k]+G[k][i]);
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
    }
    if(ans>1000) ans=-1;
    cout<<ans<<'\n';
    
}