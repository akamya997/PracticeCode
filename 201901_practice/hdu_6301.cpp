#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
struct Seg{
	int l,r;
	bool operator <(const Seg &a)const{
		if(l==a.l) return r>a.r;
		return l<a.l;
	}
}seg[maxn];
int ans[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
			scanf("%d%d",&seg[i].l,&seg[i].r);
		sort(seg,seg+m);
		for(int i=0;i<=n;i++)
			ans[i]=0;
		int L=0,R=0,to=0x3f3f3f3f;
		for(int i=0;i<m;i++)
		{
			if(seg[i].r<R)
			{
				continue;
			}
			to=ans[seg[i].l]-1;
			int bin=max(R+1,seg[i].l);
		cout<<bin<<":"<<to<<endl;
			for(int j=bin;j<=min(seg[i].r,bin+to-1);j++)
				ans[j]=j-bin+1;
			for(int j=bin+to;j<=seg[i].r;j++)
				ans[j]=ans[R]+j-bin-to+1;
			L=seg[i].l;
			R=seg[i].r;
		}
		printf("%d",ans[1]==0?1:ans[1]);
		for(int i=2;i<=n;i++)
			printf(" %d",ans[i]==0?1:ans[i]);
		printf("\n");
	}
}
