#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=1e6+7;
struct Edge{
    int to;
    ll v;
};
vector<Edge> G[maxn];
pi dfs(int u,int fa=-1)
{
    pi ret={0,u};
    for(auto &e:G[u])
    {
        int v=e.to;
        if(v==fa) continue;
        pi cur=dfs(v,u);
        cur.first+=e.v;
        ret=max(ret,cur);
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++) G[i].clear();
        ll ans=0;
        for(int i=1,u,v;i<n;i++)
        {
            ll w;
            cin>>u>>v>>w;
            G[u].push_back({v,w});
            G[v].push_back({u,w});
            ans+=w*2;
        }
        auto st=dfs(1);
        st=dfs(st.second);
        ans-=st.first;
        cout<<ans<<'\n';
    }
}