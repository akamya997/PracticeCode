struct Node{
	Node *l,*r;
	int id;
	Node(int _id):id(_id),l(NULL),r(NULL){}
};
Node* rt[maxn];
int tot;//编号
int ins[maxn];
#define Lson L,mid,o->l
#define Rson mid+1,R,o->r
void build(int L,int R,Node* &o)
{
	o=new Node(tot++);
	if(L==R)
	{
		addedge(o->id,L);
		return;
	}
	int mid=L+R>>1;
	build(Lson);
	build(Rson);
	addedge(o->id,o->l->id);addedge(o->id,o->r->id);
}
void update(int p,int l,int r,int L,int R,Node *o)
{
	if(l<=L&&r>=R)
	{
		addedge(ins[p],o->id);
		return;
	}
	int mid=L+R>>1;
	if(l<=mid) update(p,l,r,Lson);
	if(r>mid) update(p,l,r,Rson);
}
void add(int pos,int L,int R,Node* &o,Node* pre)
{
	o=new Node(tot++);
	if(L==R)
	{
		addedge(o->id,ins[pos]);
		return;
	}
	int mid=L+R>>1;
	if(pos<=mid) 
	{
		add(pos,Lson,pre->l);
		o->r=pre->r;
	}
	else{
		add(pos,Rson,pre->r);
		o->l=pre->l;
	}
	addedge(o->id,o->l->id);addedge(o->id,o->r->id);
}
