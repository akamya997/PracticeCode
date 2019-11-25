#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[10005][15];
struct item{
	int v,w;
};
vector<item> kind[15];
int main()
{
	int n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(int i=0;i<15;i++) kind[i].clear();
		memset(dp,-0x3f,sizeof(dp));
		for(int i=0,a,b,c;i<n;i++)
		{
			ignore=scanf("%d%d%d",&a,&b,&c);
			kind[a].push_back(item{b,c});
		}
		dp[0][0]=0;
		for(int i=1;i<=k;i++)
		{
			for(int j=0;j<kind[i].size();j++)
			{
				item cur=kind[i][j];
				for(int l=m;l>=cur.v;l--)
					dp[l][i]=max(max(dp[l][i],dp[l-cur.v][i]+cur.w),dp[l-cur.v][i-1]+cur.w);
			}
		}
		int ans=-INF;
		for(int i=0;i<=m;i++)
			ans=max(ans,dp[i][k]);
		if(ans<=0) puts("Impossible");
		else printf("%d\n",ans);
	}
}
