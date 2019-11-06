#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define N 100001
using namespace std;
int n,m,cnt,sz,head[N],deep[N],son[N],belong[N],pl[N],v[N],ft[N][18];
bool vis[N];
struct seg{int l,r,lc,rc,s,tag;}t[4*N];
struct edge{int to,next;}e[2*N];
void insert(int u,int v)
{
    e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;
    e[++cnt].to=u;e[cnt].next=head[v];head[v]=cnt;
}
void dfs1(int x)
{
    vis[x]=son[x]=1;
    for(int i=1;i<=17;i++)
    {
        if(deep[x]<(1<<i))break;
        ft[x][i]=ft[ft[x][i-1]][i-1];
    }
    for(int i=head[x];i;i=e[i].next)
    {
        if(vis[e[i].to])continue;
        deep[e[i].to]=deep[x]+1;
        ft[e[i].to][0]=x;
        dfs1(e[i].to);
        son[x]+=son[e[i].to];
    }
}
void dfs2(int x,int chain)
{
    pl[x]=++sz;belong[x]=chain;
    int k=0;
    for(int i=head[x];i;i=e[i].next)
        if(deep[e[i].to]>deep[x]&&son[k]<son[e[i].to])
           k=e[i].to;
    if(!k)return;
    dfs2(k,chain);
    for(int i=head[x];i;i=e[i].next)
        if(deep[e[i].to]>deep[x]&&k!=e[i].to)
           dfs2(e[i].to,e[i].to);
}
int lca(int x,int y)
{
    if(deep[x]<deep[y])swap(x,y);
    int t=deep[x]-deep[y];
    for(int i=0;i<=17;i++)
       if(t&(1<<i))x=ft[x][i];
    for(int i=17;i>=0;i--)
       if(ft[x][i]!=ft[y][i])
       {x=ft[x][i];y=ft[y][i];}
    if(x==y)return x;
    return ft[x][0];
}
void build(int k,int l,int r)
{
    t[k].l=l;t[k].r=r;t[k].s=1;t[k].tag=-1;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void pushup(int k)
{
    t[k].lc=t[k<<1].lc;t[k].rc=t[k<<1|1].rc;
    if(t[k<<1].rc^t[k<<1|1].lc)t[k].s=t[k<<1].s+t[k<<1|1].s;
    else t[k].s=t[k<<1].s+t[k<<1|1].s-1;
}
void pushdown(int k)
{
    int tmp=t[k].tag;t[k].tag=-1;
    if(tmp==-1||t[k].l==t[k].r)return;
    t[k<<1].s=t[k<<1|1].s=1;
    t[k<<1].tag=t[k<<1|1].tag=tmp;
    t[k<<1].lc=t[k<<1].rc=tmp;
    t[k<<1|1].lc=t[k<<1|1].rc=tmp;
}
void change(int k,int x,int y,int c)
{
    pushdown(k);
    int l=t[k].l,r=t[k].r;
    if(l==x&&r==y)
    {t[k].lc=t[k].rc=c;t[k].s=1;t[k].tag=c;return;}
    int mid=(l+r)>>1;
    if(mid>=y)change(k<<1,x,y,c);
    else if(mid<x)change(k<<1|1,x,y,c);
    else
    {
        change(k<<1,x,mid,c);
        change(k<<1|1,mid+1,y,c);
    }
    pushup(k);
}
int ask(int k,int x,int y)
{
    pushdown(k);
    int l=t[k].l,r=t[k].r;
    if(l==x&&r==y)return t[k].s;
    int mid=(l+r)>>1;
    if(mid>=y)return ask(k<<1,x,y);
    else if(mid<x)return ask(k<<1|1,x,y);
    else
    {
        int tmp=1;
        if(t[k<<1].rc^t[k<<1|1].lc)tmp=0;
        return ask(k<<1,x,mid)+ask(k<<1|1,mid+1,y)-tmp;
    }
}
int getc(int k,int x)
{
    pushdown(k);
    int l=t[k].l,r=t[k].r;
    if(l==r)return t[k].lc;
    int mid=(l+r)>>1;
    if(x<=mid)return getc(k<<1,x);
    else return getc(k<<1|1,x);
}
int solvesum(int x,int f)
{
    int sum=0;
    while(belong[x]!=belong[f])
    {
        sum+=ask(1,pl[belong[x]],pl[x]);
        if(getc(1,pl[belong[x]])==getc(1,pl[ft[belong[x]][0]]))sum--;
        x=ft[belong[x]][0]; 
    }
    sum+=ask(1,pl[f],pl[x]);
    return sum;
}
void solvechange(int x,int f,int c)
{
    while(belong[x]!=belong[f])
    {
        change(1,pl[belong[x]],pl[x],c);
        x=ft[belong[x]][0]; 
    }
    change(1,pl[f],pl[x],c);
}
void solve()
{
    int a,b,c;
    dfs1(1);
    dfs2(1,1);
    build(1,1,n);
    for(int i=1;i<=n;i++)
        change(1,pl[i],pl[i],v[i]);
    for(int i=1;i<=m;i++)
    {
        char ch[10];
        scanf("%s",ch);
        if(ch[0]=='Q')
        {
            scanf("%d%d",&a,&b);
            int t=lca(a,b);
            printf("%d\n",solvesum(a,t)+solvesum(b,t)-1);
        }
        else
        {
            scanf("%d%d%d",&a,&b,&c);
            int t=lca(a,b);
            solvechange(a,t,c);solvechange(b,t,c);
        }
    }
}
void ini()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        insert(x,y);
    }
}
int main()
{
    ini();
    solve();
    return 0;
}
