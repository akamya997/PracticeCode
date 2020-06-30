#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int maxn=205;
int G[maxn][maxn];
int dis[maxn][maxn];
int d[maxn];
void solve()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    memset(G,0x3f,sizeof(G));
    vi p(n);
    s--,t--;
    for(int i=0;i<n;i++) cin>>p[i],G[i][i]=0;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        if(v==t||v==s) G[u][v]=0;
        else G[u][v]=p[v];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) dis[i][j]=G[i][j];
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
        }
    }
    memset(d,0x3f,sizeof(d));
    for(int i=0;i<n;i++)
    {
        d[i]=G[s][t]+G[t][i];
        //cout<<i<<":"<<d[i]<<endl;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            if(dis[i][k]<200)
            {
                d[k]=min(d[k],G[s][k]+G[k][t]+d[i]-G[s][t]);
                //cout<<G[s][k]<<" "<<G[k][t]<<" "<<d[i]<<","<<G[s][t]<<endl;
            //cout<<k<<" "<<i<<":"<<d[k]<<endl;
            }
        }
        //cout<<d[k]<<endl;
        for(int i=0;i<n;i++)
        {
            d[i]=min(d[i],d[k]+G[k][i]);
        }
    }
    cout<<d[s]+p[s]+p[t]<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
}