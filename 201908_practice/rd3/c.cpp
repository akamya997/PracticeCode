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
const int maxn=1e5+7;
struct node{
	int ch[2],cnt;
	node(){memset(ch,0,sizeof(ch));cnt=0;}
}tree[maxn*60];
int tot=1;
set<int> ext;
void Insert(int x)
{
	if(!ext.count(x))
		ext.insert(x);
	else return;
	int cur=0;
	for(int i=31;i>=0;i--)
	{
		int val=(x>>i&1);
		if(!tree[cur].ch[val])
			tree[cur].ch[val]=tot++;
		cur=tree[cur].ch[val];
		tree[cur].cnt++;
	}
}
void del(int x)
{
	if(ext.count(x))
		ext.erase(x);
	else return;
	int cur=0;
	for(int i=31;i>=0;i--)
	{
		int val=(x>>i&1);
		cur=tree[cur].ch[val];
		tree[cur].cnt--;
	}
}
int query(int x)
{
	int ret=0;
	int cur=0;
	for(int i=31;i>=0;i--)
	{
		int val=(x>>i&1);
		if(tree[tree[cur].ch[val]].cnt)
		{
			cur=tree[cur].ch[val];
			ret+=val*(1<<i);
		}
		else 
		{
			cur=tree[cur].ch[val^1];
			ret+=(val^1)*(1<<i);
		}
	}
	int ans=0;
	for(int i=0;i<31;i++)
	{
		if((1<<i)>x&&(1<<i)>ret) break;
		if((x>>i&1)&&(ret>>i&1))
			ans|=(1<<i);
		else if(!(x>>i&1)&&!(ret>>i&1))
			ans|=(1<<i);
	}
	dbg(ret);
	return max(x,ans);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0,x;i<n;i++)
	{
		scanf("%d",&x);
		Insert(x);
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int c,v;
		scanf("%d%d",&c,&v);
		if(c==0)
			printf("%d\n",query(v));
		else if(c==1)
			Insert(v);
		else del(v);
	}
}
