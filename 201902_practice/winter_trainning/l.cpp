#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int ans[1005];
long long pre[maxn];
map<long long ,bool> ext;
int main()
{
	int n;
	ignore=scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		ans[i]=1000000+i;
	}
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);
	puts("");
}
