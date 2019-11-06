#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
struct Gun{
	int c;double ratio;
	bool operator<(const Gun &a)const{
		return c+ratio*a.c<a.c+a.ratio*c;
	}
}gun[maxn];
int main()
{
	int n;
	double w;
	scanf("%d%lf",&n,&w);
	for(int i=0;i<n;i++)
		scanf("%d%lf",&gun[i].c,&gun[i].ratio);
	sort(gun,gun+n);
	double ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=gun[i].c*w;
		w*=gun[i].ratio;
	}
	printf("%.10f\n",ans);
}
