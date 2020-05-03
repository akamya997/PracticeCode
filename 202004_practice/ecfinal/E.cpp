#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+7;

typedef pair<ll,ll> pi;
typedef vector<ll> vi;
struct Edge{
    int to,w;
};
vector<Edge> G[maxn];
int n,m;
vi path[maxn];
void dfs(int u,vi &ed)
{
    if(u==n) return;
    assert(G[u].size()==1);
    auto e=G[u][0];
    ed.push_back(e.w);
    dfs(e.to,ed);
}
struct D{
    ll pos,num;
    bool operator<(const D &a)const
	{
        if(pos==a.pos) return num<num;
        return pos>a.pos;
    }
};
int main()
{
    scanf("%d%d",&n,&m);
    for(int x,y,z,i=1;i<=m;++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        G[x].push_back({y,z});
    }
    int tot=0;
    for(auto e:G[1])
    {
        vi cur;
        cur.push_back(e.w);
        dfs(e.to,cur);
        path[tot++]=cur;
    }
    //printf("sum: %lld                 number of path: %d\n",sum,tot);
    vector<vi> cost(tot);
    priority_queue<D> q;
    int len=path[0].size();
    ll ans=0;
    ll sum=0;
    for(int i=0;i<tot;++i)
    {
        //cout<<len<<endl;
        for(auto v:path[i])
            cost[i].push_back(v);
        sort(cost[i].begin(),cost[i].end());
        for(auto c:cost[i]) sum+=c-cost[i][0];
        int cc=0;
        while(cc<len&&cost[i][0]==cost[i][cc]) cc++;
        if(cc<len)
            q.push(D{cc,i});
    }
    while(sum>=len&&!q.empty())
    {
        auto u=q.top();q.pop();
        assert(u.pos<len);
        int cc=u.pos;
        ll all=cost[u.num][u.pos]-cost[u.num][u.pos-1];
        if(all*len<=sum)
        {
            sum-=all*len;
            ans+=all*cc;
        }
        else {
            ll cnt=sum/len;
            sum=0;
            ans+=cnt*cc;
        }
        //printf("u.num:%lld cc:%d ans:%lld sum:%lld pos:%lld\n",u.num,cc,ans,sum,u.pos);
        while(cc<len&&cost[u.num][u.pos]==cost[u.num][cc]) cc++;
        if(cc<len)
            q.push(D{cc,u.num});
    }
    //printf("sum:%lld need:%lld\n",sum,need);
    printf("%lld\n",ans+sum/len*len);
}


