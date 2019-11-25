#include<bits/stdc++.h>
using namespace std;
int dp[1005][35];
int w[105],vol[105];
int main()
{
	int T;
	ignore=scanf("%d",&T);
	while(T--)
	{
		int n,v,k;
		ignore=scanf("%d%d%d",&n,&v,&k);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
			ignore=scanf("%d",&w[i]);
		for(int i=0;i<n;i++)
			ignore=scanf("%d",&vol[i]);
		for(int i=0;i<n;i++)
		{
			for(int j=v;j>=vol[i];j--)
			{
				vector<int> cur;
				for(int l=1;l<=k;l++)
				{
					cur.push_back(dp[j][l]);
					cur.push_back(dp[j-vol[i]][l]+w[i]);
				}
				sort(cur.begin(),cur.end());
				cur.erase(unique(cur.begin(),cur.end()),cur.end());
				reverse(cur.begin(),cur.end());
				for(int l=0;l<min((int)cur.size(),k);l++)
					dp[j][l+1]=cur[l];
			}
		}
		printf("%d\n",dp[v][k]);
	}
}
