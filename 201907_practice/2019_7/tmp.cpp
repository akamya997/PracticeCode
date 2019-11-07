#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+7;
const int mod=998244353;
const int INF=0x3f3f3f3f;
map<int,int> cnt[maxn];
ll solve(int n,int up)
{
	if(cnt[n].count(up)) return cnt[n][up];
	ll ret=0;
	if(1LL*up*up<n) return 0;
	if(n==2) return 0;
	if(n==1||n==0) return 1;
	for(int i=min(up,n/2);i>=1;i--)
	{
		if(i*2+1>n) continue;
		ret=(ret+solve(n-(i*2+1),i))%mod;
	}
	return cnt[n][up]=ret;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",solve(n,INF));
	}
}
