#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
const long long INF=0x3f3f3f3f3f3f3f3f;
int n,m;
struct Edge{
	int to;long long w;
};
vector<Edge> G[maxn];
long long dis[maxn];
int cnt[maxn];
bool inq[maxn];
long long spfa(int st)
{
	long long ret=INF*2;
	for(int i=0;i<=n;i++) dis[i]=2*INF;
	stack<int> q;
	q.push(st);
	dis[st]=0;
	inq[st]=1;
	while(!q.empty())
	{
		int cur=q.top();q.pop();
		inq[cur]=0;
		for(int i=0;i<G[cur].size();i++)
		{
			Edge v=G[cur][i];
			if(dis[v.to]>dis[cur]+v.w)
			{
				cnt[v.to]=cnt[cur]+1;
				if(cnt[v.to]>n+1) return -INF*2LL;
				dis[v.to]=dis[cur]+v.w;
				if(!inq[v.to])
				{
					q.push(v.to);
				}
				inq[v.to]=1;
			}
		}
	}
	for(int i=0;i<n;i++) ret=min(ret,dis[i]);
	return ret;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int mi=0x3f3f3f3f;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++) G[i].clear();
		for(int i=0;i<n;i++) G[n].push_back(Edge{i,0});
		for(int i=0,u,v,w;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			u--;v--;
			mi=min(mi,w);
			G[u].push_back(Edge{v,w});
		}
		if(mi>=0) 
		{
			printf("%d\n",mi);
			continue;
		}
		long long ans=spfa(n);
		if(ans==-2*INF) puts("-inf");
		else printf("%lld\n",ans);
		for(int i=0;i<=n;i++) inq[i]=0,cnt[i]=0;
	}
}
