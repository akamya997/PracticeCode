#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=1e6+7;
const int INF=0x3f3f3f3f;
struct Edge{
	int to,w,nxt;
};
int n,m;
int head1[maxn],head2[maxn],cnt1,cnt2;
Edge edge1[maxn],edge2[maxn];
void init()
{
	for(int i=0;i<=n;i++) head1[i]=head2[i]=-1;
	cnt1=0,cnt2=0;
}
inline void addedge1(int u,int v,int w)
{
	edge1[cnt1]={v,w,head1[u]};
	head1[u]=cnt1++;
}
inline void addedge2(int u,int v,int w)
{
	edge2[cnt2]={v,w,head2[u]};
	head2[u]=cnt2++;
}
int dis[maxn];
bool inq[maxn];
ll spfa()
{
	for(int i=0;i<=n;i++) inq[i]=0,dis[i]=INF;
	queue<int> q;
	q.push(1);
	dis[1]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=head1[u];i!=-1;i=edge1[i].nxt)
		{
			Edge e=edge1[i];
			int v=e.to;
			if(dis[v]>dis[u]+e.w)
			{
				dis[v]=dis[u]+e.w;
				if(!inq[v])
					q.push(v);
				inq[v]=1;
			}
		}
	}
	ll ret=0;
	for(int i=1;i<=n;i++) ret+=dis[i];
	return ret;
}
ll spfa2()
{
	for(int i=0;i<=n;i++) inq[i]=0,dis[i]=INF;
	queue<int> q;
	q.push(1);
	dis[1]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=head2[u];i!=-1;i=edge2[i].nxt)
		{
			Edge e=edge2[i];
			int v=e.to;
			if(dis[v]>dis[u]+e.w)
			{
				dis[v]=dis[u]+e.w;
				if(!inq[v])
					q.push(v);
				inq[v]=1;
			}
		}
	}
	ll ret=0;
	for(int i=1;i<=n;i++) ret+=dis[i];
	return ret;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		init();
		for(int i=0,u,v,w;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge1(u,v,w);
			addedge2(v,u,w);
		}
		printf("%lld\n",spfa()+spfa2());
	}
}
