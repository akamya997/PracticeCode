#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
const int mod=1e9+7;
typedef vector<int> vi;
vi G[maxn];
vi add[maxn];
int cnt[maxn];
int deg[maxn];
set<int> all;
bool vis[maxn];
void dfs(int u)
{
    if(vis[u]) return;
    vis[u]=1;
    for(auto v:add[u]) all.insert(v);
    for(auto v:G[u]) dfs(v);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,l;
    cin>>n>>l;
    for(int i=1;i<=l;i++)
    {
        int cc;
        cin>>cc;
        for(int j=0,tmp;j<cc;j++)
        {
            cin>>tmp;
            if(tmp<=l)
            {
                G[i].push_back(tmp);
                deg[tmp]++;
            }
            else add[i].push_back(tmp);
        }
    }
    cnt[1]=1;
    queue<int> q;
    for(int i=1;i<=l;i++)
    {
        if(!deg[i])
            q.push(i);
    }
    int ti=0;
    while(!q.empty())
    {
        auto u=q.front();q.pop();
        ti++;
        for(auto v:G[u])
        {
            deg[v]--;
            cnt[v]=(cnt[v]+cnt[u])%mod;
            if(!deg[v]) q.push(v);
        }
    }
    assert(ti==l);
    ll ans1=0;
    for(int i=1;i<=l;i++)
        ans1=(ans1+(ll)cnt[i]*add[i].size()%mod)%mod;
    dfs(1);
    cout<<ans1<<" "<<all.size()<<'\n';
}