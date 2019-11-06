#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(NULL));
struct Treap{
	int val,pri,sz;
	Treap *l,*r;
	Treap(int val):val(val),pri(rnd()),sz(1){}
	void update()
	{
		sz=1;
		if(l) s+=l->sz;
		if(r) s+=r->sz;
	}
}rt;
typedef pair<Treap*,Treap*> ptt;
ptt split(Treap* a,int val)
{
	if(node==NULL) return ptt(NULL,NULL);
	ptt root;
	if(node->val<=val)
	{
		root=split(node->r,val);
		node->r=root.first,rt.first=node;
	}
	else{
		root=split(node->l,val);
		node->l=root.second,root.second=node;
	}
	node->update();
	return root;
}
Treap* merge(Treap* a,Treap* b)
{
	if(a==NULL) return b;
	if(b==NULL) return a;
	if(a->pri>=b->pri)
	{
		a->r=merge(a->r,b);
		a->update();
		return a;
	}
	else{
		b->l=merge(a,b->l);
		b->update();
		return b;
	}
}
void insert(int x)
{
	Treap* p=new Treap(val);
	ptt pa=split(rt,x);
	pa.first=merge(pa.first,p);
	rt=merge(pa.first,pa.second);
}
int ext[100005];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(ext,0,sizeof(ext));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0,op,x,y;i<m;i++)
		{
			scanf("%d",&op);
			switch(op)
			{
				Case 0:scanf("%d%d",&x,&y);;break;
			}
		}
	}
}
