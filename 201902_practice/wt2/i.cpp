#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
const int INF=0x3f3f3f3f;
struct Edge{
    int from,to,cap,flow;
};
struct DINIC{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];

    void AddEdge(int from,int to,int cap,int c=0)//有向图默认为零
    {
        edges.push_back(Edge {from,to,cap,0});
        edges.push_back(Edge {to,from,c,0});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS()
    {
        memset(vis,0,sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!Q.empty())
        {
            int x=Q.front();Q.pop();
            for(int i=0;i<G[x].size();i++)
            {
                Edge& e=edges[G[x][i]];
                if(!vis[e.to]&&e.cap>e.flow)
                {
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x,int a)
    {
        if(x==t||a==0) return a;
        int flow=0,f;
        for(int& i=cur[x];i<G[x].size();i++)
        {
            Edge& e=edges[G[x][i]];
            if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0)
            {
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }
    int Maxflow(int s,int t)
    {
        this->s=s;this->t=t;
        int flow=0;
        while(BFS())
        {
            memset(cur,0,sizeof(cur));
            flow+=DFS(s,INF);
        }
        return flow;
    }
}F;
const int var=2005;
long long s;
struct Point{
	long long  x,y,water;
}pt[var*2];
bool ok(Point a,Point b)
{
	return round(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)))<=s-10;
}
int main()
{
	int n,m;
	int S=var*2+1,T=var*2+2;
	scanf("%d%d%lld",&n,&m,&s);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&pt[i].x,&pt[i].y);
		F.AddEdge(S,i,1);
	}
	for(int i=0;i<m;i++) 
	{
		scanf("%lld%lld%lld",&pt[var+i].x,&pt[var+i].y,&pt[var+i].water);
		F.AddEdge(i+var,T,pt[i+var].water);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(ok(pt[i],pt[j+var]))
			{
				F.AddEdge(i,j+var,1);
			}
		}
	}
	int ans=F.Maxflow(S,T);
	puts(ans==n?"YES":"NO");
}
