#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int maxn=5e5+7;
struct Edge{
    int to,tp;
};
vector<Edge> G[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) G[i].clear();
        vi cnt(n+2);
        int cc=0;
        for(int i=0,u,v;i<m;i++)
        {
            cin>>u>>v;
            if(v<u)
            {
                cnt[v]++;
                cnt[u+1]--;
                cc++;
                G[v].push_back(Edge{u,1});
            }
            else{
                G[u].push_back(Edge{v,0});
            }
        }
        int cur=0;
        vi ok(n+1);
        bool suc=0;
        for(int i=1;i<=n;i++)
        {
            cur+=cnt[i];
            if(cur==cc)
                ok[i]=1,suc=1;
        }
        if(!suc)
            cout<<0<<'\n';
        else{
            vi cov(n+2);
            cur=0;
            int R=0;
            vi ans;
            for(int i=1;i<=n;i++)
            {
                for(auto &e:G[i])
                {
                    if(e.tp==1) R=max(R,e.to);
                }
                cur+=cov[i];
                if(!cur&&ok[i]) ans.push_back(i);
                for(auto &e:G[i])
                {
                    if(e.tp==0&&e.to<=R)
                    {
                        cov[e.to]--;
                        cur++;
                    }
                }
            }
            cout<<ans.size();
            for(auto u:ans) cout<<" "<<u;
            cout<<'\n';
        }

    }
}