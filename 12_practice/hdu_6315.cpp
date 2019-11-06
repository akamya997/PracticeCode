#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
struct node{
	int b,low,sum;
}sgt[maxn*4];
int lazy[maxn*4];
void pushup(int rt)
{
	sgt[rt].low=min(sgt[rt*2].low,sgt[rt*2+1].low);
	sgt[rt].sum=sgt[rt*2].sum+sgt[rt*2+1].sum;
}
void pushdown(int L,int R,int rt)
{
	if(lazy[rt])
	{
		sgt[rt*2].low-=lazy[rt];
		sgt[rt*2+1].low-=lazy[rt];
		lazy[rt*2]+=lazy[rt];
		lazy[rt*2+1]+=lazy[rt];
		lazy[rt]=0;
	}
	if(sgt[rt].low<=0)
	{
		if(L==R)
		{
			while(sgt[rt].low<=0)
			{
				sgt[rt].low+=sgt[rt].b;
				sgt[rt].sum++;
			}
			return;
		}
		int mid=L+R>>1;
		pushdown(L,mid,rt*2);
		pushdown(mid+1,R,rt*2+1);
		pushup(rt);
	}
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%d",&sgt[rt].b);
		sgt[rt].low=sgt[rt].b;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
	pushup(rt);
}
void update(int l,int r,int L,int R,int rt)
{
	pushdown(L,R,rt);
	if(L>=l&&R<=r)
	{
		sgt[rt].low-=1;
		lazy[rt]+=1;
		return ;
	}
	int mid=L+R>>1;
	if(mid>=l)
		update(l,r,L,mid,rt*2);
	if(mid<r)
		update(l,r,mid+1,R,rt*2+1);
	pushup(rt);
}
int query(int l,int r,int L,int R,int rt)
{
	pushdown(L,R,rt);
	if(L>=l&&R<=r)
	{
		return sgt[rt].sum;
	}
	int mid=L+R>>1;
	int ret=0;
	if(mid>=l)
		ret+=query(l,r,L,mid,rt*2);
	if(mid<r)
		ret+=query(l,r,mid+1,R,rt*2+1);
	return ret;
}
int main()
{
	int n,q;
	while(~scanf("%d%d",&n,&q))
	{
		memset(sgt,0,sizeof(sgt));
		memset(lazy,0,sizeof(lazy));
		build(1,n,1);
		char op[10];
		while(q--)
		{
			int l,r;
			scanf("%s",op);
			scanf("%d%d",&l,&r);
			if(op[0]=='a')
				update(l,r,1,n,1);
			else{
				int ans=query(l,r,1,n,1);
				printf("%d\n",ans);
			}
		}
	}
}
