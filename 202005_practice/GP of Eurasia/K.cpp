#include<bits/stdc++.h>
using namespace std;
const int maxn=50;
typedef long long ll;
typedef vector<int> vi;
int G[maxn][maxn];
ll st[maxn];
vi ap;
map<ll,int> dp;
set<int> rem,cango;
map<ll,ll> nxt;
int best=0;
int dfs(ll cur,int cans)
{
    if(dp.count(cur)) return dp[cur];
    if(cans+rem.size()<=best) return 0;
    best=max(best,cans);
    int ret=0;
    vi cg;
    for(auto u:cango) cg.push_back(u);
    //random_shuffle(cg.begin(),cg.end());
    for(auto v:cg)
    {
        if(cur&(1LL<<v)) continue;
        vi del;
        int cc=0;
        for(auto u:rem)
        {
            if(st[u]&(1LL<<v))
            {
                del.push_back(u);
                cc+=(G[u][v]==G[0][v]);
            }
        }
        for(auto u:del) rem.erase(u);
        if(!del.size()) continue;
        cango.erase(v);
        int np=dfs(cur|(1LL<<v),cans+cc)+cc;
        if(np>ret)
        {
            nxt[cur]=cur|(1LL<<v);
            ret=np;
        }
        for(auto u:del) rem.insert(u);
        cango.insert(v);
    }
    //cout<<cur<<":"<<ret<<endl;
    return dp[cur]=ret;
}
vi op;
ll las=0;
void print(ll u)
{
    if(!nxt.count(u)) {las=u;return;}
    ll cur=u^nxt[u];
    assert(__builtin_popcountll(cur)==1);
    for(int i=0;;i++)
    {
        if((1LL<<i)==cur)
        {
            op.push_back(i+1);
            break;
        }
    }
    print(nxt[u]);
}
int main()
{
    //srand(time(NULL));
    //for(int i=0;i<20;i++) cout<<rand()<<endl;
    memset(G,-1,sizeof(G));
    int n,m;
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=0,u,v,w;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        u--,v--;
        G[u][v]=G[v][u]=w;
        if(u==0)
        {
            ap.push_back(v);
            if(!w) ans++;
        }
        st[u]|=(1LL<<v);
        st[v]|=(1LL<<u);
    }
    for(int i=1;i<n;i++)
    {
        if(G[0][i]==-1)
            rem.insert(i);
    }
    for(auto u:ap) cango.insert(u);
    ans+=dfs(0,ans);
    printf("%.12f\n",1.0*ans/(n-1));
    print(0);
    for(int i=0;i<n;i++)
    {
        if((st[0]>>i&1)&&!(las>>i&1)) op.push_back(i+1);
    }
    assert(op.size()==ap.size());
    for(int i=0;i<op.size();i++)
    {
        printf("%d",op[i]);
        if(i==(int)op.size()-1) printf("\n");
        else printf(" ");
    }
}