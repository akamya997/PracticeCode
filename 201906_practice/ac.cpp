#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define N 209
using namespace std;

struct edge{int v,w;edge *nxt;}E[10009],*Adj[N],*cur;
int n,m,nn;
int d[N][1<<8],dp[1<<8];
bool in[N][1<<8];
int S[N],P[N],st[N],fac[4],cf,cs;
queue<int> Q;
void addedge(int u,int v,int w){cur->v=v,cur->w=w,cur->nxt=Adj[u],Adj[u]=cur++;}
void up(int &a,int b){if(a==-1||a>b) a=b;}
void spfa(){
    while(!Q.empty()){
        int x=Q.front()/1000,y=Q.front()%1000;
        Q.pop();
        in[x][y]=0;
        for(edge *i=Adj[x];i;i=i->nxt)
            if(d[i->v][y|st[i->v]]==-1||d[x][y]+i->w<d[i->v][y|st[i->v]]){
                d[i->v][y|st[i->v]]=d[x][y]+i->w;
                if(y==(y|st[i->v])&&!in[i->v][y]) in[i->v][y]=1,Q.push(i->v*1000+y);
            }                
    }
}
bool check(int x){
    int t=0;
    for(int i=0;x;i++,x>>=1)
        t+=(x&1)*(i<cf?fac[i]:-1);
    return t>=0;
}
int cnt(int x){
    int r=0;
    for(int i=0;x;i++,x>>=1)
        r+=(x&1)*(i<cf?0:1);
    return r;
}
int main(){
    while(scanf("%d",&n)+1){
        cur=E;
        cf=cs=0;
        memset(Adj,0,sizeof(Adj));
        memset(st,0,sizeof(st));
        memset(d,-1,sizeof(d));
        memset(dp,-1,sizeof(dp));        
        int ans=0;
        for(int i=1;i<=n;i++){            
            scanf("%d%d",P+i,S+i);
            if(S[i]&&P[i]) P[i]--,S[i]=0,ans++;
            if(P[i]) st[i]=1<<cf,fac[cf++]=P[i],d[i][st[i]]=0;
        }        
        for(int i=1;i<=n;i++)
            if(S[i])
                st[i]=1<<(cf+cs++),d[i][st[i]]=0;
        nn=1<<(cf+cs);
        
        scanf("%d",&m);
        while(m--){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        
        for(int y=1;y<nn;y++){
            for(int x=1;x<=n;x++){
                if(st[x]&&!(st[x]&y)) continue;
                for(int i=(y-1)&y;i;i=(i-1)&y)
                    if(d[x][i|st[x]]!=-1&&d[x][(y-i)|st[x]]!=-1)
                        up(d[x][y],d[x][i|st[x]]+d[x][(y-i)|st[x]]);
                if(d[x][y]!=-1) Q.push(x*1000+y),in[x][y]=1;
            }
            spfa();
        }
        for(int i=1;i<=n;i++)
            for(int j=0;j<nn;j++)
                if(d[i][j]!=-1)
                    up(dp[j],d[i][j]);
        int num=0,cost=0;
        for(int i=1;i<nn;i++)
            if(check(i)){
                for(int j=(i-1)&i;j;j=(j-1)&i)
                    if(check(j)&&check(i-j)&&dp[j]!=-1&&dp[i-j]!=-1)
                        up(dp[i],dp[j]+dp[i-j]);
                int t=cnt(i);
                if(dp[i]!=-1&&(t>num||(t==num&&dp[i]<cost)))
                    num=t,cost=dp[i];
            }
        printf("%d %d\n",num+ans,cost);
    }
}
