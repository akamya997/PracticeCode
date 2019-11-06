#include <bits/stdc++.h>
 
using namespace std;
const int N=5005;
typedef long long ll;
const int mod=1e9+7;
#define go(i,a,b) for(int i=(a);i<=(b);i++)
#define dep(i,a,b) for(int i=(a);i>=(b);i--)
#define add(a,b) ((a+=(b))%=mod)
ll dp[N][N],sum[N][N],f[N],ans;
vector<int>path[N];
int is[N];
int n,m,k,x,y;
void cal(int u,int to){
    go(i,1,k-1)f[i]=dp[u][i]*sum[to][min(i,k-i)-1]%mod;
    go(i,1,k-1)add(f[i],sum[u][min(i,k-i)]*dp[to][i-1]%mod);
    go(i,1,k/2)add(f[i],(mod-dp[u][i]*dp[to][i-1]%mod)%mod);//容斥，减去计算重复的方案
    go(i,1,k)
        add(dp[u][i],(dp[to][i-1]+f[i])%mod),//加上这颗子树的方案
        sum[u][i]=(sum[u][i-1]+dp[u][i])%mod;
}
void dfs(int u,int fa){
    for(auto to:path[u]){
        if(to==fa)continue;
        dfs(to,u);
        cal(u,to);
    }
    if(is[u]){//如果这个点可选
        sum[u][0]=dp[u][0]=1;//只选这个点
        go(i,1,k)
            add(dp[u][i],dp[u][i]),//分选它不选两种，所以要乘2
            sum[u][i]=(sum[u][i-1]+dp[u][i])%mod;//更新前缀和
    }
    add(ans,u!=1?dp[u][k]:sum[u][k]);//如果这个点是根，加所有情况，否则只加长度为k的情况
}
int main()
{
 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		path[u].push_back(v);
		path[v].push_back(u);
	}
	for(int i=1;i<=m;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		is[tmp]=1;
	}
    dfs(1,0);
	printf("%lld\n",ans);
    return 0;
}
