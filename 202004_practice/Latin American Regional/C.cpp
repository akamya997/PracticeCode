#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
typedef long long ll;
typedef pair<int,int> pi;
const ll INF=0x3f3f3f3f3f3f3f3f;
pi f[2][maxn][20];
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
ll mx[maxn<<2],mi[maxn<<2];
int a[maxn];
ll pre[maxn];
int n,down,up;
void build(int L=1,int R=n,int o=1)
{
    if(L==R)
    {
        mx[o]=mi[o]=pre[L];
        return;
    }
    int mid=L+R>>1;
    build(Lson);
    build(Rson);
    mx[o]=max(mx[lson],mx[rson]);
    mi[o]=min(mi[lson],mi[rson]);
}
ll qmax(int l,int r,int L=1,int R=n,int o=1)
{
    if(l<=L&&r>=R)
        return mx[o];
    int mid=L+R>>1;
    ll ret=-INF;
    if(l<=mid) ret=qmax(l,r,Lson);
    if(r>mid) ret=max(ret,qmax(l,r,Rson));
    return ret;
}
ll qmin(int l,int r,int L=1,int R=n,int o=1)
{
    if(l<=L&&r>=R)
        return mi[o];
    int mid=L+R>>1;
    ll ret=INF;
    if(l<=mid) ret=qmin(l,r,Lson);
    if(r>mid) ret=min(ret,qmin(l,r,Rson));
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>down>>up;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    build();
    for(int i=1;i<=n;i++)
    {
        {
            int L=i,R=n,ans=n+1;
            while(L<=R)
            {
                int mid=L+R>>1;
                ll cur=qmin(i,mid);
                cur-=pre[i-1];
                if(up+cur<=down)
                {
                    R=mid-1;
                    ans=mid;
                }
                else L=mid+1;
            }
            f[1][i][0]=make_pair(ans,0);
        }
        {
            int L=i,R=n,ans=n+1;
            while(L<=R)
            {
                int mid=L+R>>1;
                ll cur=qmin(i,mid);
                cur-=pre[i-1];
                if(down+cur<=down)
                {
                    R=mid-1;
                    ans=mid;
                }
                else L=mid+1;
            }
            f[0][i][0]=make_pair(ans,0);
        }
        {
            int L=i,R=n,ans=n+1;
            while(L<=R)
            {
                int mid=L+R>>1;
                ll cur=qmax(i,mid);
                cur-=pre[i-1];
                if(up+cur>=up)
                {
                    R=mid-1;
                    ans=mid;
                }
                else L=mid+1;
            }
            f[1][i][0]=min(f[1][i][0],make_pair(ans,1));
        }
        {
            int L=i,R=n,ans=n+1;
            while(L<=R)
            {
                int mid=L+R>>1;
                ll cur=qmax(i,mid);
                cur-=pre[i-1];
                if(down+cur>=up)
                {
                    R=mid-1;
                    ans=mid;
                }
                else L=mid+1;
            }
            f[0][i][0]=min(f[0][i][0],make_pair(ans,1));
        }
    }
    f[0][n+2][0]=f[1][n+2][0]=make_pair(n+1,0);
    f[0][n+1][0]=f[1][n+1][0]=make_pair(n+1,0);
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            f[0][i][j]=f[f[0][i][j-1].second][f[0][i][j-1].first+1][j-1];
            f[1][i][j]=f[f[1][i][j-1].second][f[1][i][j-1].first+1][j-1];
            //printf("f[0][%d][%d]:(%d,%d)\n",i,j-1,f[0][i][j-1].first,f[0][i][j-1].second);
        }
        f[0][n+2][j]=f[1][n+2][j]=make_pair(n+1,0);
        f[0][n+1][j]=f[1][n+1][j]=make_pair(n+1,0);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r,x;
        cin>>l>>r>>x;
        int dpos=n+1,upos=n+1;
        {
            int L=l,R=n;
            while(L<=R)
            {
                int mid=L+R>>1;
                ll cur=qmin(l,mid)-pre[l-1];
                if(x+cur<=down)
                {
                    R=mid-1;
                    dpos=mid;
                }
                else L=mid+1;
            }
        }
        {
            int L=l,R=n;
            while(L<=R)
            {
                int mid=L+R>>1;
                ll cur=qmax(l,mid)-pre[l-1];
                if(x+cur>=up)
                {
                    R=mid-1;
                    upos=mid;
                }
                else L=mid+1;
            }
        }
        if(dpos>r&&upos>r)
            cout<<pre[r]-pre[l-1]+x<<'\n';
        else{
            int pos=min(dpos,upos);
            int tp=0;
            if(dpos<upos)
                tp=0;
            else tp=1;
            int L=0,R=n,ans=-1,at=-1;
            while(L<=R)
            {
                int mid=L+R>>1;
                int curpos=pos,curtp=tp;
                for(int j=0;(1<<j)<=n;j++)
                {
                    if(mid>>j&1)
                    {
                        pi nxt=f[curtp][curpos+1][j];
                        //printf("mid:%d curpos:%d curtp:%d nxt:%d\n",mid,curpos,curtp,nxt.second);
                        curtp=nxt.second;
                        curpos=nxt.first;
                    }
                }
                if(curpos<=r)
                {
                    ans=curpos;
                    L=mid+1;
                    at=curtp;
                }
                else R=mid-1;
            }
            assert(ans!=-1);
            //printf("!:%d\n",ans);
            cout<<pre[r]-pre[ans]+(at?up:down)<<'\n';
        }
    }
}