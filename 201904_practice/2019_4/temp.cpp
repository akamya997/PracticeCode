int dfn[maxn],low[maxn],bel[maxn];
int n,m;
int ti,scc;//时间戳与联通分量计数
stack<int> st;
void dfs(int u,int fa)
{
	dfn[u] = low[u] = ++ti;
	st.push(u);
	for(int i = head[u];i != -1;i = edge[i].nxt)
	{
		int v = edge[i].to;
		if(v == fa) continue;
		if(!dfn[v])
		{
			dfs(v,u);
			low[u] = min(low[u] ,low[v]);
		}
		else if(!bel[v])
			low[u] = min(low[u],dfn[v]);
	}
	if(dfn[u] == low[u])
	{
		scc++;
		while(1)
		{
			int t = st.top();st.pop();
			bel[t] = scc;
			if(u == t) break;
		}
	}
}
void DCC()
{
	for(int i = 1;i <= n;i++)
		if(!dfn[i])
			dfs(i ,-1);
	for(int i = 0;i < cur;i++)//遍历所有边建图
	{
		int u = edge[i].from,v = edge[i].to;
		if(bel[u] != bel[v])
			addedge2(bel[u] ,bel[v]);
	}
}
