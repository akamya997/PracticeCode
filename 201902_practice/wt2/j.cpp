#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int maxn=1e5+7;
ld seg[maxn*4];
ld INF=1;
ld mul(ld a,ld b)
{
	return a*b;
}
void pushup(int rt)
{
	seg[rt]=mul(seg[rt*2],seg[rt*2+1]);
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%Lf",&seg[rt]);
		return;
	}
	int mid=l+r>>1;
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
	pushup(rt);
}
void update(int pt,ld val,int L,int R,int rt)
{
	if(L==R)
	{
		seg[rt]=val;
		return ;
	}
	int mid=L+R>>1;
	if(mid>=pt) update(pt,val,L,mid,rt*2);
	else update(pt,val,mid+1,R,rt*2+1);
	pushup(rt);
}
ld query(int l,int r,int L,int R,int rt)
{
	if(L>=l&&R<=r)
		return seg[rt];
	int mid=L+R>>1;
	ld ret=1;
	if(l<=mid) ret=mul(ret,query(l,r,L,mid,rt*2));
	if(r>mid) ret=mul(ret,query(l,r,mid+1,R,rt*2+1));
	return ret;
}
int main()
{
	for(int i=0;i<100;i++) INF*=2;
	int n;
	scanf("%d",&n);
	build(1,n,1);
	int q;
	scanf("%d",&q);
	int op;
	ld p;
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			int x;
			scanf("%d%Lf",&x,&p);
			update(x,p,1,n,1);
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			ld ans=query(l,r,1,n,1);
			if(ans>=INF) puts("INFINITE!");
			else printf("%.10Lf\n",ans);
		}
	}
}
