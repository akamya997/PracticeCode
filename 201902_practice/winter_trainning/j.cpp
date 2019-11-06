#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
long long arr[maxn];
long long pre[maxn];
long long tot;
int main()
{
	int n,m;
	tot=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
		tot+=arr[i];
		if(i==0) pre[0]=arr[i];
		else pre[i]=pre[i-1]+arr[i];
	}
	for(int i=0;i<n;i++)
	{
		long long ans=tot-arr[i]+m;
		if(i>0) ans=max(ans,pre[i-1]);
		if(i<n-1) ans=max(ans,tot-pre[i]);
		printf("%lld ",ans);
	}
	puts("");

}
