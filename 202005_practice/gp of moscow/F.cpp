#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e5+7;
struct Edge{
    int to,w;
};
int dp[maxn];
vector<Edge> G[maxn];
vector<pi> sz;
bool vis[50];
void dfs(int u,int cur,int fa=-1)
{
    dp[u]=1;
    for(auto &e:G[u])if(e.to!=fa&&e.w<=cur)
    {
        int v=e.to;
        dfs(v,cur,u);
        vis[e.w]=1;
        if(e.w!=cur) dp[u]+=dp[v];
    }
}
void dfs2(int u,int cur,int fa=-1)
{
    if(fa==-1) sz.emplace_back(dp[u],u);
    for(auto &e:G[u])if(e.to!=fa&&e.w<=cur)
    {
        int v=e.to;
        dfs2(v,cur,u);
        if(e.w==cur) sz.emplace_back(dp[v],v);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1,u,v,w;i<n;i++)
    {
        cin>>u>>v>>w;
        G[u].push_back(Edge{v,w});
        G[v].push_back(Edge{u,w});
    }
    int rt=1;
    int cnt=0;
    ll ans=0;
    for(int i=30;i>=0;i--)
    {
        memset(vis,0,sizeof(vis));
        dfs(rt,i);
        sz.clear();
        dfs2(rt,i);
        sort(sz.begin(),sz.end(),greater<pi>());
        int rem=n-cnt;
        if((sz[0].first-cnt)*2<=rem-cnt&&vis[i])
        {
            //cout<<i<<":"<<rem<<endl;
            ans+=(1LL<<i)*(rem-cnt-1);
            break;
        }
        else{
            int cc=0;
            for(int j=1;j<sz.size();j++) cc+=sz[j].first;
            //cout<<i<<":"<<cc<<endl;
            ans+=(1LL<<i)*cc*2;
            cnt=n-sz[0].first;
            rt=sz[0].second;
        }
    }
    cout<<ans<<'\n';

}