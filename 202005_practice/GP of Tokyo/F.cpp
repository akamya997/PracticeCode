#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
typedef long long ll;
typedef vector<int> vi;
vi G[maxn<<3];
int deg[maxn<<3];
inline void addedge(int u,int v)
{
    G[u].push_back(v);
    deg[v]++;
}
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
int n;
int tot;
struct seg{
    int id[maxn<<2];
    void build(int L=1,int R=n,int o=1)
    {
        id[o]=++tot;
        if(L==R)
        {
            addedge(L,id[o]);
            return;
        }
        int mid=L+R>>1;
        build(Lson);
        build(Rson);
        addedge(id[lson],id[o]);
        addedge(id[rson],id[o]);
    }
    void add(int p,int l,int r,int L=1,int R=n,int o=1)
    {
        if(l<=L&&r>=R)
        {
            addedge(id[o],p);
            return;
        }
        int mid=L+R>>1;
        if(l<=mid) add(p,l,r,Lson);
        if(r>mid) add(p,l,r,Rson);
    }
}sgt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vi a(n+1),b(n+1);
    tot=n;
    sgt.build();
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    ll op=0;
    for(int i=1;i<=n;i++)
    {
        //printf("%d\n",i);
        int d=abs(b[i]-a[i]);
        op+=d;
        int l,r;
        if(a[i]>b[i])
        {
            l=lower_bound(a.begin()+1,a.end(),b[i]-d)-a.begin();
            r=i-1;
            if(l<i) sgt.add(i,l,i-1);
            if(r>i) sgt.add(i,i+1,r);
            //printf("l:%d r:%d\n",l,r);
            //if(l<=r) sgt.add(i,l,r);
        }
        else{
            l=i+1;
            r=lower_bound(a.begin()+1,a.end(),b[i]+d)-a.begin()-1;
            if(l<i) sgt.add(i,l,i-1);
            if(r>i) sgt.add(i,i+1,r);
            //printf("l:%d r:%d\n",l,r);
            //if(l<=r) sgt.add(i,l,r);
        }
    }
    vi ans;
    queue<int> q;
    for(int i=1;i<=tot;i++)
        if(!deg[i]) q.push(i);
    while(!q.empty())
    {
        auto u=q.front();q.pop();
        if(u<=n) ans.push_back(u);
        for(auto v:G[u])
        {
            deg[v]--;
            if(!deg[v]) q.push(v);
        }
    }
    assert(ans.size()==n);
    cout<<op<<'\n';
    for(int i=0;i<n;i++) cout<<ans[i]<<" \n"[i==n-1];
}