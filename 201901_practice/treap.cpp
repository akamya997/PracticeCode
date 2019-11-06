#include<bits/stdc++.h>
using namespace std;
namespace treap{
	struct Node{
		Node* l,*r;
		int sz,val,prior;
		Node(int _val):l(NULL),r(NULL),sz(1),val(_val),prior(rand()){}
	};
	typedef Node* pN;
	pN root=NULL;
	void pushup(pN cur)
	{
		if(cur) cur->sz=1;
		else return;
		if(cur->l) cur+=cur->l->sz;
		if(cur->r) cur+=cur->r->sz;
	}
	void split(pN rt,int k,pN &l,pN &r)
	{
		if(!rt)
			l=r=NULL;
		else if(k<rt->val) split(rt->l,k,l,rt->l),r=rt;
		else split(rt->r,k,rt->r,r),l=rt;
		pushup(rt);
	}
	void merge(pN &rt,pN l,pN r)
	{
		if(!l||!r) rt=l?l:r;
		else if(l->prior>r->prior) merge(l->r,l->r,r),rt=l;
		else merge(r->l,l,r->l),rt=r;
	}
	void insert(int val)
	{
		pN l,r;
		split(root,val,l,r);
		merge(l,l,new Node(val));
		merge(root,l,r);
	}
}
int main()
{
	
}
