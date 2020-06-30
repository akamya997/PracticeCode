#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int L;
    cin>>L>>n;
    vi a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    sort(b.begin(),b.end());
    map<int,int> ext;
    for(int j=0;j<n;j++)
    {
        int i=0;
        ext[(abs(a[i]-b[j]))]=1;
        if(a[i]!=b[j]) ext[(2*L-(abs(a[i]-b[j])))]=1;
        ext[(a[i]+b[j]-1)]=1;
        ext[(2*L-(a[i]+b[j]-1))]=1;
    }
    int ans=-1;
    auto judge=[&](vector<vi>& G){
        vi vis(n*2);
        function<int(int,int)> dfs=[&](int u,int fa){
            vis[u]=1;
            int ret=0;
            for(auto v:G[u])if(v!=fa)
                ret=dfs(v,u)+1;
            return ret;
        };
        for(int i=0;i<2*n;i++)
        {
            assert(G[i].size()<=2);
            if(G[i].size()<2&&!vis[i])
            {
                int len=dfs(i,-1);
                if(len%2==0) return false;
            }
        }
        return true;
    };
    auto getid=[&](int x){
        return lower_bound(b.begin(),b.end(),x)-b.begin();
    };
    for(auto &u:ext)
    {
        int T=u.first;
        //cout<<"!"<<T<<endl;
        vector<vi> G(n*2);
        auto add=[&](int x,int y){
            //cout<<x<<" "<<y<<endl;
            G[x].push_back(y+n);
            G[y+n].push_back(x);
        };
        for(int i=0;i<n;i++)
        {
            if(a[i]-T>=1)
            {
                int p=getid(a[i]-T);
                if(b[p]==a[i]-T) add(i,p);
            }
            else{
                int dt=T-a[i]+1;
                int p=getid(dt);
                if(b[p]==dt) add(i,p);
            }
            if(a[i]+T<=L)
            {
                int p=getid(a[i]+T);
                if(b[p]==a[i]+T) add(i,p);
            }
            else{
                int dt=L-(T-(L-a[i]))+1;
                int p=getid(dt);
                if(b[p]==dt) add(i,p);
            }
        }
        if(judge(G))
        {
            ans=T;
            break;
        }
    }
    cout<<ans<<'\n';
}