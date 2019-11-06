#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn=1e4+7;
const int INF=0x3f3f3f3f;
struct Edge{
    int v,w;
};
vector<Edge> G[maxn];
int sz[maxn],maxson[maxn],minson,rt,cursz;
bool vis[maxn];
int n,k;
void findrt(int u,int fa)
{
    maxson[u]=0,sz[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        Edge e=G[u][i];
        int v=e.v;
        if(v==fa||vis[v]) continue;
        findrt(v,u);
        sz[u]+=sz[v];
        maxson[u]=max(maxson[u],sz[v]);
    }
    maxson[u]=max(maxson[u],cursz-sz[u]);
    if(minson>maxson[u]) minson=maxson[u],rt=u;
}
int ans=0;
int dis[maxn];
int cc;
void getdis(int u,int fa=-1,int d=0)
{
    dis[cc++]=d;
    for(int i=0;i<G[u].size();i++)
    {
        Edge e=G[u][i];
        int v=e.v;
        if(v==fa||vis[v]) continue;
        getdis(v,u,d+e.w);
    }
}
int calc(int u,int d)
{
    int ret=0;
    cc=0;
    getdis(u,-1,d);
    int l=0,r=cc-1;
    sort(dis,dis+cc);
    while(l<r)
    {
        while(l<r&&dis[r]+dis[l]>k)
            r--;
        ret+=r-l;
        l++;
    }
    return ret;
}
void dfs(int u)
{
    ans+=calc(u,0);
    vis[u]=1;
    int totsz=cursz;
    for(int i=0;i<G[u].size();i++)
    {
        Edge e=G[u][i];
        int v=e.v;
        if(vis[v]) continue;
        ans-=calc(v,e.w);
        minson=INF,rt=0;
        cursz=sz[v]>sz[u]?totsz-sz[u]:sz[v];
        findrt(v,-1);
        dfs(rt);
    }
}
int main()
{
    while(~scanf("%d%d",&n,&k)&&n+k)
    {
        for(int i=0;i<=n;i++) G[i].clear(),vis[i]=0;
		ans=0;
        for(int i=1,u,v,w;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back(Edge{v,w});
            G[v].push_back(Edge{u,w});
        }
        cursz=n,minson=INF,rt=0;
        findrt(1,-1);
        dfs(rt);
        printf("%d\n",ans);
    }
}
