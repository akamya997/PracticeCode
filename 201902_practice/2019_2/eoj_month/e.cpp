#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
struct Edge{
	int u,v;
}edge[maxn];
int arr[maxn];
int n,m;
vector<int> G[maxn];
vector<int> far[maxn];
int deg[maxn];
int topo[maxn];
int tot=0;
void toposort()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==0) q.push(i);
	}
	while(!q.empty())
	{
		int cur=q.front();q.pop();
		topo[tot++]=cur;
		for(int i=0;i<G[cur].size();i++)
		{
			int v=G[cur][i];
			deg[v]--;
			if(!deg[v]) q.push(v);
		}
	}
}
int dp[maxn];
bool check(int cur)
{
	memset(dp,-0x3f,sizeof(dp));
	for(int i=0;i<tot;i++)
	{
		int num=topo[i];
		if(num==1) dp[num]=arr[num]>=cur?1:-1;
		else{
			for(int j=0;j<far[num].size();j++)
			{
				int v=far[num][j];
				dp[num]=max(dp[v]+(arr[num]>=cur?1:-1),dp[num]);
			}
		}
	}
	return dp[n]>=0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&edge[i].u,&edge[i].v);
		G[edge[i].u].push_back(edge[i].v);
		deg[edge[i].v]++;
		far[edge[i].v].push_back(edge[i].u);
	}
	toposort();
	int l=0,r=1e9,ans=-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",ans);

}
