#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2050;
vector<int> G[maxn];
int dp[maxn];
int cnt[maxn];
int low[maxn];
const int INF=0x3f3f3f3f;
int ans;
string s;
void dfs(int u,int fa=-1)
{
	vector<int> cur;
	cnt[u]=(s[u-1]=='1');
	int sum=0,mxi=0;
	for(auto &v:G[u])if(v!=fa)
	{
		dfs(v,u);
		cnt[u]+=cnt[v];
		dp[v]+=cnt[v];
		dp[u]+=dp[v];
		low[v]+=cnt[v];
		if(low[mxi]<low[v]) mxi=v;
		sum+=dp[v];
		low[u]^=(dp[v]&1);
	}
	sum-=dp[mxi];
	low[u]=max(low[u],low[mxi]-sum);
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	cin>>s;
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ans=INF;
	for(int i=1;i<=n;i++)
	{
		memset(dp,0,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		memset(low,0,sizeof(low));
		dfs(i);
	//	cout<<i<<":"<<low[i]<<" "<<dp[i]<<endl;
		if(!low[i]) ans=min(ans,dp[i]/2);
	}
	if(ans==INF) cout<<-1<<endl;
	else cout<<ans<<endl;
}
