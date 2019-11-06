#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
long long arr[maxn];
long long ans[maxn];
int n,k;
long long x;
bool check(long long cur)
{
	long long cnt=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>cur) continue;
		cnt+=(cur-arr[i])/x+1;
	}
	return cnt>=k;
}
int main()
{
	scanf("%d%d%lld",&n,&k,&x);
	for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
	long long l=0,r=3e18;
	while(l<r)
	{
		long long mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	for(int i=0;i<n;i++)
	{
		long long cur=0;
		if(r<arr[i]) cur=0;
		else{
			cur=(r-arr[i])/x+1;
			if((r-arr[i])%x==0) cur--;
			if(cur>=k)
			{
				cur=k;
				k=0;
			}
			else{
				k-=cur;
			}
		}
		ans[i]=cur;
	}
	for(int i=0;i<n;i++)
	{
		if(!k) break;
		if(r>=arr[i]&&(r-arr[i])%x==0)
		{
			ans[i]++;k--;
		}
	}
	for(int i=0;i<n;i++) printf("%lld ",ans[i]);
	puts("");
}
