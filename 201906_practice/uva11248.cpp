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
struct Edge{
	int from,to;ll cap,flow;
};
const int maxn=105;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll c;

struct Dinic{
	int n,m,s,t;
	ll mx=0;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool vis[maxn];
	int d[maxn];
	int cur[maxn];
	vector<Edge> sv;
	ll mxcur=0;
	void addedge(int from,int to,ll cap)
	{
		edges.push_back(Edge {from,to,cap,0});
		edges.push_back(Edge {to,from,0,0});
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}

	bool bfs()
	{
		memset(vis,0,sizeof(vis));
		queue<int> q;
		q.push(s);
		d[s]=0;
		vis[s]=1;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int i=0;i<G[u].size();i++)
			{
				Edge &e=edges[G[u][i]];
				if(!vis[e.to]&&e.cap>e.flow)
				{
					vis[e.to]=1;
					d[e.to]=d[u]+1;
					q.push(e.to);
				}
			}
		}
		return vis[t];
	}
	ll dfs(int u,ll dist)
	{
		if(u==t||dist==0) return dist;
		ll flow=0,f;
		for(int &i=cur[u];i<G[u].size();i++)
		{
			Edge &e=edges[G[u][i]];
			if(d[u]+1==d[e.to]&&(f=dfs(e.to,min(dist,e.cap-e.flow)))>0)
			{
				e.flow+=f;
				edges[G[u][i]^1].flow-=f;
				flow+=f;
				dist-=f;
				if(!dist) break;
			}
		}
		return flow;
	}

	ll maxflow(int s,int t)
	{
		this->s=s;
		this->t=t;
		mxcur=mx;
		while(bfs())
		{
			memset(cur,0,sizeof(cur));
			mxcur+=dfs(s,INF);
			if(mxcur>=c) break;
		}
		return mxcur;
	}

};
struct ANS{
	int u,v;
	bool operator<(const ANS a)const{
		if(a.u==u) return v<a.v;
		return u<a.u;
	}
};
int main()
{
	int kas=0;
	int n,e;
	while(~scanf("%d%d%lld",&n,&e,&c)&&(n+e+c))
	{
		Dinic F;
		int s=1,t=n;
		for(int i=0,u,v;i<e;i++)
		{
			ll w;
			scanf("%d%d%lld",&u,&v,&w);
			F.addedge(u,v,w);
		}
		bool ok=0;
		if(F.maxflow(s,t)>=c)
			ok=1;
		F.mx=F.mxcur;
		if(ok)
			printf("Case %d: possible\n",++kas);
		else{
			F.sv=F.edges;
			vector<ANS> ans;
			for(int i=0;i<F.sv.size();i++)
			{
				auto u=F.sv[i];
				if(u.flow==u.cap)
				{
					ll tt=u.cap;
					F.sv[i].cap=c;
					F.edges=F.sv;
					F.sv[i].cap=tt;
					if(F.maxflow(s,t)>=c)
						ans.push_back(ANS {u.from,u.to});
				}
			}
			if(!ans.size())
				printf("Case %d: not possible\n",++kas);
			else {
				printf("Case %d: possible option:",++kas);
				sort(ans.begin(),ans.end());
				for(int i=0;i<ans.size();i++)
				{
					printf("(%d,%d)%c",ans[i].u,ans[i].v,i==ans.size()-1?'\n':',');
				}
			}

		}
	}
}
