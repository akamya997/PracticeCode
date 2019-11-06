#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
int tot=0;
int newnode(int fa);
struct node{
	int fa;
	int sz;
	int mx;
	vector<int> son;
	vector<int> v;
	inline bool isleaf()
	{
		return son.size()==0;
	}
	node(){fa=-1;v.clear();sz=0;mx=0;son.clear();}
	inline void Clear(){fa=-1;v.clear();sz=0;mx=0;son.clear();}
	inline void maintain();
	inline void Insert(int val)
	{
		sz++;
		v.push_back(val);
	}
}tree[100050];
inline bool cmp(int a,int b)
{
	return tree[a].mx<tree[b].mx;
}
inline void node::maintain()
{
	sort(v.begin(),v.end());
	mx=*max_element(v.begin(),v.end());
	sort(son.begin(),son.end(),cmp);
}
int split(int cur)
{
	tree[cur].maintain();
	int mid=newnode(tree[cur].fa);
	int l=newnode(mid),r=newnode(mid);
	tree[mid].v.push_back(tree[cur].v[1]);
	tree[l].v.push_back(tree[cur].v[0]);
	tree[r].v.push_back(tree[cur].v[2]);
	tree[mid].son.push_back(l);
	tree[mid].son.push_back(r);
	if(!tree[cur].isleaf())
	{
		tree[l].son.push_back(tree[cur].son[0]);
		tree[l].son.push_back(tree[cur].son[1]);
		tree[r].son.push_back(tree[cur].son[2]);
		tree[r].son.push_back(tree[cur].son[3]);
	}
	tree[l].maintain();
	tree[r].maintain();
	tree[mid].maintain();
	return mid;
}
int rt;
inline int newnode(int fa)
{
	tree[++tot].Clear();
	tree[tot].fa=fa;
	return tot;
}
inline int Find(vector<int>& all,int cur)
{
	for(int i=0;i<all.size();i++)
	{
		if(cur==all[i])
			return i;
	}
	assert(false);
	return -1;
}
void split(int cur,int val,int fa)
{
	if(tree[cur].v.size()==3)
	{
		int ret=split(cur);
		if(fa==-1)
		{
			rt=ret;
			fa=rt;
		}
		else{
			tree[fa].son.erase(tree[fa].son.begin()+Find(tree[fa].son,cur));
			tree[fa].v.push_back(tree[ret].v[0]);
			for(int i=0;i<tree[ret].son.size();i++)
			{
				tree[fa].son.push_back(tree[ret].son[i]);
				tree[tree[ret].son[i]].fa=fa;
			}
		}
		tree[fa].maintain();
		for(int i=0;i<tree[fa].v.size();i++)
		{
			if(i&&val>tree[fa].v[i-1]&&val<tree[fa].v[i])
			{split(tree[fa].son[i],val,fa);break;}
			else if(!i&&val<tree[fa].v[0])
			{split(tree[fa].son[i],val,fa);break;}
			else if(i==tree[fa].v.size()-1&&val>tree[fa].v[i])
			{split(tree[fa].son[i+1],val,fa);break;}
		}
		tree[fa].maintain();
		return;
	}
	if(tree[cur].isleaf()) return;
	for(int i=0;i<tree[cur].v.size();i++)
	{
		if(i&&val>tree[cur].v[i-1]&&val<tree[cur].v[i])
		{split(tree[cur].son[i],val,cur);break;}
		else if(!i&&val<tree[cur].v[0])
		{split(tree[cur].son[i],val,cur);break;}
		else if(i==tree[cur].v.size()-1&&val>tree[cur].v[i])
		{split(tree[cur].son[i+1],val,cur);break;}
	}
	tree[cur].maintain();
	return;
}
void Insert(int cur,int val)
{
	//dbg(cur,val,tree[cur].v.size(),tree[cur].son.size(),tree[cur].isleaf(),rt);
	if(tree[cur].isleaf())
	{
		tree[cur].Insert(val);
		tree[cur].maintain();
		return;
	}
	for(int i=0;i<tree[cur].v.size();i++)
	{
		if(i&&val>tree[cur].v[i-1]&&val<tree[cur].v[i])
			Insert(tree[cur].son[i],val);
		else if(!i&&val<tree[cur].v[0])
			Insert(tree[cur].son[i],val);
		else if(i==tree[cur].v.size()-1&&val>tree[cur].v[i])
			Insert(tree[cur].son[i+1],val);
	}
	tree[cur].maintain();
}
void solve(int cur)
{
	for(int i=0;i<tree[cur].v.size();i++)
		printf("%d%c",tree[cur].v[i],i==tree[cur].v.size()-1?'\n':' ');
	for(auto u:tree[cur].son)
		solve(u);
}
int main()
{
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		tot=0;
		rt=newnode(-1);
		int n;
		scanf("%d",&n);
		for(int i=1,val;i<=n;i++)
		{
//			dbg(i);
			scanf("%d",&val);
			split(rt,val,-1);
			Insert(rt,val);
	//		solve(rt);
			//dbg(rt);
	//		cout<<i<<":"<<endl;
	//		solve(rt);
			assert(tot<100050);
		}
		printf("Case #%d:\n",++kas);
		solve(rt);
	}
}
