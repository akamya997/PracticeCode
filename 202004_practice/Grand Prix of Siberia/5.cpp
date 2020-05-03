#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int maxn=1e5+7;
int fa[maxn];
int col[maxn];
int vis[maxn];
void init()
{
    for(int i=0;i<maxn;i++) fa[i]=i;
}
int Find(int x)
{
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
    x=Find(x);y=Find(y);
    fa[y]=x;
}
struct Edge{
    int u,v,tp,id;
};
vector<Edge> G[maxn];
vector<Edge> all;
bool ok=1;
inline void addedge(int u,int v,int tp,int id)
{
    G[u].push_back({0,v,tp,id});
    G[v].push_back({0,u,tp,id});
    all.push_back(Edge{u,v,tp,id});
}
void dfs(int u,int cc)
{
    //printf("u:%d col:%d\n",u,cc);
    if(col[u]!=-1)
    {
        if(col[u]!=cc)
            ok=0;
        return;
    }
    col[u]=cc;
    for(auto &e:G[u])
    {
        int v=e.v;
        int nc=cc^e.tp^1;
        dfs(v,nc);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    memset(col,-1,sizeof(col));
    int zero=n+1,one=n+2;
    addedge(zero,one,0,0);
    for(int i=1;i<=m;i++)
    {
        string op;
        cin>>op;
        if(op=="vert")
        {
            int x;
            cin>>x;
            addedge(x,zero,1,i);
        }
        else if(op=="hor")
        {
            int x;
            cin>>x;
            addedge(x,one,1,i);
        }
        else if(op=="par")
        {
            int x,y;
            cin>>x>>y;
            addedge(x,y,1,i);
        }
        else if(op=="perp")
        {
            int x,y;
            cin>>x>>y;
            addedge(x,y,0,i);
        }
    }
    dfs(one,1);
    dfs(zero,0);
    for(int i=1;i<=n;i++)
    {
        if(col[i]==-1) dfs(i,0);
    }
    if(!ok)
        cout<<"inconsistent\n";
    else{
        cout<<"consistent\n";
        vi ans;
        init();
        for(auto &u:all)
        {
            //printf("u:%d v:%d tp:%d\n",u.u,u.v,u.tp);
            if(Find(u.u)!=Find(u.v)){
                vis[u.id]=1;
                Union(u.u,u.v);
            }
        }
        for(int i=1;i<=m;i++)
            if(!vis[i]) ans.push_back(i);
        cout<<ans.size()<<'\n';
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" \n"[i==(ans.size()-1)];
    }
}