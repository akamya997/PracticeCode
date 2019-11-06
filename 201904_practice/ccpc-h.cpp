#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn=2e5+7;
const int INF=0x3f3f3f3f;
vector<int> G[maxn];
vector<int> tar;
int n;
int far[maxn];
int dis[maxn][4];
int vis[maxn];
vector<int> circle;
int idx,odx;
struct Edge{
	int u,v;
}edge[maxn];
int pre[maxn],nxt[maxn];
bool inc[maxn];
bool istar[maxn];
void bfs(int st,int num)
{
	memset(vis,0,sizeof(vis));
	queue<int> q;
	dis[st][num]=0;
	vis[st]=1;
	q.push(st);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(auto v:G[u])
		{
			if(!vis[v]) 
			{
				q.push(v);
				vis[v]=1;
				dis[v][num]=dis[u][num]+1;
			}
		}
	}
}
int Find(int x)
{
	return x==far[x]?x:far[x]=Find(far[x]);
}
void Union(int x,int y)
{
	x=Find(x);y=Find(y);
	far[y]=x;
}
void init()
{
	for(int i=0;i<=n;i++) {G[i].clear();far[i]=i;}
	tar.clear();
	circle.clear();
	memset(inc,0,sizeof(inc));
	memset(dis,0,sizeof(dis));
	memset(istar,0,sizeof(istar));
}
void Findcircle()
{
	for(int i=1;i<=n;i++)
	{
		if(Find(edge[i].u)==Find(edge[i].v))
		{
			idx=edge[i].u;odx=edge[i].v;
			return;
		}
		Union(edge[i].u,edge[i].v);
	}
}
int dfs(int u,int fa)
{
	int ret=istar[u]?dis[u][0]:INF;
	for(auto v:G[u])
	{
		if(v==fa) continue;
		if(inc[v]) continue;
		ret=min(ret,dfs(v,u));
	}
	return ret;
}
int main()
{
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		init();
		for(int i=1,u,v;i<=n;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
			edge[i].u=u,edge[i].v=v;
		}
		int m;
		scanf("%d",&m);
		for(int i=0,tmp;i<m;i++)
		{
			scanf("%d",&tmp);
			tar.push_back(tmp);
			istar[tmp]=1;
		}
		int a,b;
		scanf("%d%d",&a,&b);
		bfs(a,0);bfs(b,1);
		bool win=0;
		for(auto p:tar)
		{
			if(dis[p][0]<=dis[p][1]) win=1;
		}
		printf("Case %d: ",++kas);
		if(win) puts("Panda");
		else{
			Findcircle();
			memset(vis,0,sizeof(vis));
			queue<int> q;
			q.push(idx);
			pre[idx]=-1;
			vis[idx]=1;
			while(!q.empty())
			{
				int u=q.front();q.pop();
				for(auto v:G[u])
				{
					if(idx==u&&v==odx) continue;
					if(!vis[v])
					{
						q.push(v);
						vis[v]=1;
						pre[v]=u;
					}
				}
			}
			int cur=odx;
			nxt[odx]=-1;
			while(cur!=-1)
			{
				circle.push_back(cur);
				inc[cur]=1;
				if(pre[cur]!=-1) nxt[pre[cur]]=cur;
				cur=pre[cur];
			}
			int ain,bin,mina=INF,minb=INF;
			for(int i=1;i<=n;i++)
			{
				if(!inc[i]) continue;
				if(dis[i][0]<mina)
				{
					ain=i;
					mina=dis[i][0];
				}
				if(dis[i][1]<minb)
				{
					minb=dis[i][1];
					bin=i;
				}
			}
			if(dis[ain][0]<=dis[bin][1]||ain==bin)
			{
				puts("Sheep");
			}
			else{
				int din=dis[ain][0];
				for(int i=1;i<=n;i++)
				{
					if(inc[i])
						dis[i][0]=dfs(i,-1)==INF?INF:dis[i][0];
				}
				if(dis[ain][0]!=INF)
					puts("Sheep");
				else{
					int lpos=ain,rpos=ain;
					bool cg=0;
					while(1)
					{
						if(dis[lpos][0]!=INF) break;
						lpos=pre[lpos];
						if(lpos==-1)
							lpos=odx;
					}
					while(1)
					{
						if(dis[rpos][0]!=INF) break;
						rpos=nxt[rpos];
						if(rpos==-1) rpos=idx;
					}
					if(lpos==rpos)
						puts("Sheep");
					else{
						win=1;
						bfs(lpos,2);bfs(rpos,3);
						for(auto u:circle)
						{
							if(dis[u][1]>din) continue;
							if((din-dis[u][1])%2!=0) continue;
							if(dis[u][2]<dis[lpos][0]-din&&dis[u][3]<dis[rpos][0]-din)
							{
								win=0;break;
							}
						}
						if(dis[lpos][1]+dis[lpos][3]<dis[rpos][0]||dis[rpos][1]+dis[rpos][2]<dis[lpos][0]) win=0;
						if(win) puts("Panda");
						else puts("Sheep");
					}
				}
			}
		}
	}
}
