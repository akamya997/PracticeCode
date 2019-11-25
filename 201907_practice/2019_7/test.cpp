#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
#include<cstdio>
using namespace std;
const int INF=INT_MAX;
struct Node
{
    int to,w;
}t1,t2;
vector<Node>G[1000001],G1[1000001];
struct node
{
    int u,w;
    bool operator <(const struct node &b) const
    {
        return w>b.w;
    }
}tem;
bool visit[1000001];
int Dis[1000001];


long long Dija(int n,int m)
{
    for(int i=1;i<=n;i++){
        Dis[i]=INF;
        visit[i]=false;
    }
    priority_queue<node>q;
    tem.w=0,tem.u=1;
    Dis[1]=0;
    q.push(tem);
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        int t=tem.u;
        if(visit[t])   continue;
        visit[t]=true;
        int sum=tem.w;
        for(int i=0;i<G[t].size();i++)
        {
            int u=G[t][i].to;
           // cout<<u<<' '<<t<<' '<<G[t][i].w<<' '<<sum<<endl;
            if(sum+G[t][i].w<Dis[u])
            {
                Dis[u]=sum+G[t][i].w;
                tem.u=u,tem.w=Dis[u];
                q.push(tem);
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=Dis[i];
    return ans;
}
long long Dijb(int n,int m)
{
    for(int i=1;i<=n;i++){
        Dis[i]=INF;
        visit[i]=false;
    }
    priority_queue<node>q;
    tem.w=0,tem.u=1;
    Dis[1]=0;
    q.push(tem);
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        int t=tem.u;
        if(visit[t])   continue;
        visit[t]=true;
        int sum=tem.w;
        for(int i=0;i<G1[t].size();i++)
        {
            int u=G1[t][i].to;
            if(sum+G1[t][i].w<Dis[u])
            {
                Dis[u]=sum+G1[t][i].w;
                tem.u=u,tem.w=Dis[u];
                q.push(tem);
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=Dis[i];
    return ans;
}

#define reads(n) FastIO::read(n)
namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], obuf[SIZE], str[60];
    int bi = SIZE, bn = SIZE, opt;
    int read(char *s) {
        while (bn) {
            for (; bi < bn && buf[bi] <= ' '; bi++);
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        int sn = 0;
        while (bn) {
            for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        s[sn] = 0;
        return sn;
    }
    bool read(int& x) {
        int n = read(str), bf;
        if (!n) return 0;
        int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
        for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
        if (bf < 0) x = -x;
        return 1;
    }
};
int main()
{
    int T;
	reads(T);
    while(T--)
    {
        int n,m;
		reads(n);reads(m);
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            G1[i].clear();
        }
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
			reads(a);reads(b);reads(c);
            t1.to=a,t1.w=c;
            t2.to=b,t2.w=c;
            G[b].push_back(t1);
            G1[a].push_back(t2);
        }
        long long ans=Dija(n,m)+Dijb(n,m);
        printf("%lld\n",ans);
    }
    return 0;
}
