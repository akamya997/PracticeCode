#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
const int INF=1e6;
int dist[maxn],vis[maxn];
int n,m,i,j,k,w;
//int G[maxn][maxn];
struct edge
{
    int w,to;
    //bool operator<(const node&n1)const{return w>n1.w;}
};
vector<edge>G[maxn];
void init()
{
    for(i=1;i<=n;i++)
    {
       G[i].clear();
    }
}
struct node
{
    int w,u;
    bool operator<(const node &n1) const{return w>n1.w;}
};
void addedge(int u,int v,int w)
{
    G[u].push_back(edge{v,w});
    G[v].push_back(edge{u,w});
}
int prim()
{
    for(i=1;i<=n;++i)
    {
        dist[i]=INF;
        vis[i]=0;
    }
    priority_queue<node> Q;
    Q.push({0,1});
    int cost=0,num=1;
    while(!Q.empty())
    {
        node tmp=Q.top();Q.pop();
        int u=tmp.u,w=tmp.w;
        if(vis[u]) continue;
		cout<<num<<" "<<u<<endl;
        vis[u]=1,cost+=w;
        num++;
        for(i=0;i<G[u].size();i++)
        {
            int v=G[u][i].to;
			cout<<"v"<<v<<endl;
            if(dist[v]>G[u][i].w)
            {
                dist[v]=G[u][i].w;
                Q.push({dist[v],v});
            }
        }
    }
    if(num<n) return -1;
    else return cost;
}

int main()
{
    while(cin>>n)
    {
        int ans=0,v,u;
        if(n==0) break;
        init();
        cin>>m;
        while(m--)
        {
          scanf("%d%d%d",&u,&v,&w);
          addedge(u,v,w);
        }
        ans=prim();
        cout<<ans<<endl;
    }
    return 0;
}
