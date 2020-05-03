#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int,int> pi;
typedef vector<int> vi;
inline int getdis(pi &a,pi &b)
{
    int sqr=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    int ret=sqrt(sqr);
    while(ret*ret<sqr) ret++;
    //printf("%d->%d\n",sqr,ret);
    return ret;
}
const int maxn=1e3+7;
pi p[maxn];
int cost[maxn];
struct Edge{
    int to,c;
};
struct D{
    int u,d;
    int curd;
    bool operator<(const D& a)const{
        return curd>a.curd;
    }
};
bool vis[maxn][105];
vector<Edge> G[maxn];
int n;
int B;
void dij(vector<vi>& dis,int st)
{
    priority_queue<D> q;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n+1;i++)
    {
        int d=getdis(p[st],p[i]);
        if(d<=B)
        {
            dis[i][d]=d*cost[0];
            //printf("u:%d d:%d cost:%d\n",i,d,dis[i][d]);
            q.push(D{i,d,dis[i][d]});
        }
    }
    while(!q.empty())
    {
        auto u=q.top();
        q.pop();
        if(vis[u.u][u.d]) continue;
        vis[u.u][u.d]=1;
        for(auto &e:G[u.u])
        {
            int v=e.to;
            int len=getdis(p[u.u],p[v]);
            if(len+u.d<=B)
            {
                if(dis[v][len+u.d]>dis[u.u][u.d]+len*e.c)
                {
                    dis[v][len+u.d]=dis[u.u][u.d]+len*e.c;
                    q.push(D{v,len+u.d,dis[v][len+u.d]});
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>p[0].x>>p[0].y;
    int Ter=maxn-1;
    cin>>p[Ter].x>>p[Ter].y;
    cin>>B;
    cin>>cost[0];
    int T;
    cin>>T;
    for(int i=1;i<=T;i++) cin>>cost[i];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y;
        int l;
        cin>>l;
        for(int j=0,tar,m;j<l;j++)
        {
            cin>>tar>>m;
            tar++;
            G[i].push_back(Edge{tar,cost[m]});
            G[tar].push_back(Edge{i,cost[m]});
        }
    }
    p[n+1]=p[Ter];
    vector<vi> d1(n+2,vi(B+1,1e9)),d2(n+2,vi(B+1,1e9));
    dij(d1,0);
    dij(d2,n+1);
    int ans=1000000000;
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=B;j++)
        {
            for(int k=0;k+j<=B;k++)
                ans=min(ans,d1[i][j]+d2[i][k]);
        }
    }
    if(ans==1000000000) cout<<-1<<'\n';
    else cout<<ans<<'\n';
}