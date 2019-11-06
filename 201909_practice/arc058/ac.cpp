#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int INF=2147483647;
const ll mod=1e9+7;
inline int read()
{
	int x=0,k=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*k;
}
ll dp[42][(1<<19)+3],ans;
int N,X,Y,Z;
int main()
{
	N=read(),X=read(),Y=read(),Z=read();
	int st=((1<<(X+Y+Z-1))|(1<<(Y+Z-1))|(1<<(Z-1)));
	dp[0][0]=1;
	ans=1ll;
	rep(i,1,N)
	{
		ans=ans*10%mod;
		rep(S,0,(1<<(X+Y+Z))-1)
		{
			if(dp[i-1][S])
			rep(c,1,10)
			{
				int now=((S<<c)|(1<<(c-1)));
				now&=((1<<(X+Y+Z))-1);
				if((now&st)!=st)dp[i][now]=(dp[i][now]+dp[i-1][S])%mod;
			}
		}
	}
	rep(S,0,(1<<(X+Y+Z))-1)
	ans=(ans-dp[N][S]+mod)%mod;
	printf("%lld",ans);
	return 0;
}
