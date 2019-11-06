#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
long long ans[maxn];
void db()
{
	for(int i=4;i<maxn;i+=4)
		ans[i]=1LL*i/4*i/4*i/2;
	for(int i=3;i<maxn;i+=3)
		ans[i]=1LL*i/3*i/3*i/3;
}
int main()
{
	db();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		if(!ans[n]) puts("-1");
		else printf("%lld\n",ans[n]);
	}
}
