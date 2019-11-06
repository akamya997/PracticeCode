#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+7;
typedef long long ll;

int pos[N],nxt[N],pre[N];
int rval[N];
int n,k;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		pre[0]=0;
		nxt[n+1]=n+1;
		for(int t,i=1;i<=n;++i)
		{
			scanf("%d",&t);
			pos[t]=i;
			pre[i]=i-1;
			nxt[i]=i+1;
		}
		ll rcnt,lcnt,ans=0,sum;
		int x;
		for(int i=1;i<=n;++i)
		{
			int x=pos[i];
			sum=rcnt=lcnt=0;
			for(int j=x;j<=n&&rcnt<k;j=nxt[j])
				rval[++rcnt]=nxt[j]-j;
			if(rcnt>=k)
				sum+=rval[k]*(x-pre[x]);
			for(int j=pre[x];j>0&&lcnt<k-1;j=pre[j])
			{
				lcnt++;
				if(k-lcnt>rcnt)
					continue;
				sum+=(j-pre[j])*rval[k-lcnt];
			}
			ans+=sum*i;
			nxt[pre[x]]=nxt[x];
			pre[nxt[x]]=pre[x];
		}
		printf("%lld\n",ans);
	}
}
