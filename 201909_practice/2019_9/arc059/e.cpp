#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll quick(ll a,ll b,int m=mod)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%m;
		a=a*a%m;
		b>>=1;
	}
	return ret;
}
const int maxn=1005;
int a[maxn],b[maxn];
ll C[maxn][maxn];
void init()
{
	for(int i=0;i<maxn;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j]);
	}
}
ll solve(int n,int k)
{
	if(!n) return 1;
	return C[n+k-1][n-1];
}
int main()
{
	init();
	cout<<C[600][200]<<endl;
	int n,c;
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		ll cur=0;
		for(int x=a[i];x<=b[i];x++)
		{
			ll pro=1;
			for(int k=0;k<=c;k++)
				pro=pro*quick(x,(c-k)*solve(n-1,k)%(mod-1))%mod;
			cout<<pro<<endl;
			cur=(cur+pro)%mod;
		}
		cout<<i<<":"<<cur<<endl;
		ans=(ans*cur)%mod;
	}
	printf("%lld\n",ans);
}
