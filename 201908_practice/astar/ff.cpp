#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
const int maxn=2e5+7;
vector<int> G[maxn],nG[maxn];
int dfn[maxn], low[maxn], bel[maxn];
int n,k;
int ti, scc; //时间戳与联通分量计数
stack<int> st;
int cur;
struct Edge{
	int from,to;
}edge[maxn*2];
void dfs(int u)
{
    dfn[u] = low[u] = ++ti;
    st.push(u);
    for (auto v:G[u])
    {
        if (!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!bel[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        scc++;
        while (1)
        {
            int t = st.top();
            st.pop();
            bel[t] = scc;
            if (u == t)
                break;
        }
    }
}
int deg[maxn];
void SCC()
{
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i);
    for (int i = 0; i < cur; i++) //遍历所有边建图
    {
        int u = edge[i].from, v = edge[i].to;
        if (bel[u] != bel[v])
        {
			nG[bel[u]].push_back(bel[v]);
			deg[bel[v]]++;
		}
    }
}
int topo[maxn];
int p[maxn],q[maxn];
void toposort()
{
	queue<int> q;
	for(int i=1;i<=scc;i++)
		if(!deg[i]) q.push(i);
	int cc=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		topo[cc++]=u;
		for(auto v:nG[u])
		{
			deg[v]--;
			if(!deg[v]) q.push(v);
		}
	}
}
char ans[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&p[i]);
		if(i>1) 
		{
			G[p[i-1]].push_back(p[i]);
			edge[cur++]={p[i-1],p[i]};
		}
	}
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&q[i]);
		if(i>1) 
		{
			G[q[i-1]].push_back(q[i]);
			edge[cur++]={q[i-1],q[i]};
		}
	}
	SCC();
	dbg(scc);
	if(scc<k) puts("NO");
	else{
		puts("YES");
		toposort();
		for(int i=0;i<scc;i++)
			ans[topo[i]]=min((int)'z','a'+i);
		for(int i=1;i<=n;i++)
			printf("%c",ans[bel[i]]);
		puts("");
	}
}
