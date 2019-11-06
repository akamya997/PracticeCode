#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int topo[maxn];
int tot=0;
int main()
{
	int n,m;
	memset(topo,-1,sizeof(topo));
	ignore=scanf("%d%d",&n,&m);
	for(int i=0,u,v;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		if(topo[u]==-1)
			topo[u]=tot++;
		if(topo[v]==-1) topo[v]=tot++;
		if(topo[u]>topo[v]) printf("1");
		else printf("0");
	}
	puts("");
}
