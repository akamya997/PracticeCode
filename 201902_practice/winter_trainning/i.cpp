#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int arr[maxn];
int main()
{
	int n;
	ignore=scanf("%d",&n);
	for(int i=0;i<n;i++)
		ignore=scanf("%d",&arr[i]);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=arr[n-i-1])
			ans=__gcd(ans,abs(arr[i]-arr[n-i-1]));
	}
	if(!ans) puts("-1");
	else printf("%d\n",ans);
}
