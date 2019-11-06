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
	int u,v,w;
};
struct node{
	int u,w;
	bool operator<(const node a)const{
		return w>a.w;
	}
};
vector<Edge> ans;
bool ok=1;
const int maxn=1e3+7;
vector<Edge> G[maxn];
vector<node> dfs(int u,int tot,int fa=-1)
{
	vector<node> ret;
	if(!ok) return ret;
	int val=0;
	if(G[u].size()==1)
	{
		ret.push_back(node {u,tot});
		return ret;
	}
	for(auto &e:G[u])
	{
		int v=e.v;
		if(v!=fa)
		{
			auto cur=dfs(v,e.w,u);
			for(auto u:cur)
				ret.push_back(u);
		}
	}
	for(auto elem:ret) val+=elem.w;
	if(val<tot) ok=0;
	else if(val>tot){
		int delta=val-tot;
		if(ret.size()==1||delta%2!=0)
			ok=0;
		else{
			while(delta&&ret.size()>1)
			{
				sort(ret.begin(),ret.end());
				int flow=ret.back().w;
				if(flow>delta)
				{
					delta=0;
					ret[0].w-=flow;
					ret.back().w-=flow;
					ans.push_back(Edge {ret[0].u,ret.back().u,flow});
				}
				else{
					delta-=flow;
					ret[0].w-=flow;
					ans.push_back(Edge {ret[0].u,ret.back().u,flow});
					ret.pop_back();
				}
			}
			if(delta) ok=0;
		}
	}
	dbg(u,tot);
	for(auto e:ret) dbg(e.u,e.w);
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back(Edge {u,v,w});
		G[v].push_back(Edge {v,u,w});
	}
	dfs(1,0);
	if(ok)
	{
		puts("YES");
		printf("%d\n",(int)ans.size());
		for(auto e:ans)
			printf("%d %d %d\n",e.u,e.v,e.w);
	}
	else puts("NO");

}
