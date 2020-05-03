#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int maxn=1e5+7;
vi G[maxn];
bool vis[maxn];
int fi[maxn][2];
void dfs(int u,int rt,int tp)
{
    if(vis[u]) return;
    vis[u]=1;
    fi[u][tp]=rt;
    for(auto v:G[u])
        dfs(v,rt==-1?v:rt,tp);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,T;
    cin>>n>>m>>T;
    for(int i=0,u,v;i<m;i++)
    {
        cin>>u>>v;
        G[v].push_back(u);
    }
    dfs(T,-1,0);
    memset(vis,0,sizeof(vis));
    reverse(G[T].begin(),G[T].end());
    dfs(T,-1,1);
    vi ans;
    for(auto v:G[T])
    {
        //printf("v:%d 0: %d 1:%d\n",v,fi[v][0],fi[v][1]);
        if(fi[v][0]==fi[v][1])
            ans.push_back(v);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<'\n';
    

}