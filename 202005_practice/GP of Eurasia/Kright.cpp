#include<bits/stdc++.h>
using namespace std;
const int maxn=50;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,int> pi;
int G[maxn][maxn];
ll st[maxn];
vi op;
vi ap,nap;
int n,m;
map<ll,int> dp;
map<ll,pi> pre;
int dfs(ll S)
{
    if(dp.count(S)) return dp[S];
    int ret=0;
    for(int i=0;i<ap.size();i++)
    {
        int cur=ap[i];
        if((S|st[cur])!=S)
        {
            int cc=0;
            for(int j=0;j<n;j++)
            {
                if(st[cur]>>j&1&&!(S>>j&1))
                    cc+=(G[cur][j]==G[0][cur]);
            }
            int nxt=dfs(S|st[cur])+cc;
            if(nxt>ret)
            {
                ret=nxt;
                pre[S]=make_pair(S|st[cur],cur);
            }
        }
    }
    return dp[S]=ret;
}
void solve()
{
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(G[0][i]==-1) nap.push_back(i);
        else if(!G[0][i]) ans++;
        if(G[0][i]!=-1)
        {
            for(int j=1;j<n;j++)
            {
                if(G[i][j]!=-1&&G[0][j]==-1)
                    st[i]|=(1LL<<j);
            }
        }
    }
    ans+=dfs(0);
    printf("%.12f\n",double(ans)/(n-1));
    ll S=0;
    vi vis(50);
    while(pre.count(S))
    {
        op.push_back(pre[S].second);
        vis[pre[S].second]=1;
        S=pre[S].first;
    }
    for(auto u:ap) if(!vis[u]) op.push_back(u);
    for(auto &u:op) u++;

}
int main()
{
    memset(G,-1,sizeof(G));
    scanf("%d%d",&n,&m);
    for(int i=0,u,v,w;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        u--,v--;
        G[u][v]=G[v][u]=w;
        if(u==0)
            ap.push_back(v);
    }
    solve();
    for(int i=0;i<op.size();i++)
    {
        printf("%d",op[i]);
        if(i==(int)op.size()-1) printf("\n");
        else printf(" ");
    }
}