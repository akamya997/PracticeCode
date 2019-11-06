#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=5e5+70;
const int mod=998244353;
vector<int> all;
int arr[maxn];
struct node{
	int len,cnt;
	node operator +=(node &a){
		if(len==a.len) cnt=(cnt+a.cnt)%mod;
		else if(len<a.len) 
		{
			len=a.len;
			cnt=a.cnt;
		}
		return *this;
	}
};
int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin()+2;
}
int tree[maxn];
void add(int x,int val)
{
	while(x<maxn)
	{
		tree[x]=max(tree[x],val);
		x+=x&-x;
	}
}
int query(int x)
{
	int ret=0;
	while(x>0)
	{
		ret=max(ret,tree[x]);
		x-=x&-x;
	}
	return ret;
}
node treenode[maxn];
void addnode(int x,int val,int ti)
{
	node cur={val,ti};
	while(x<maxn)
	{
		treenode[x]+=cur;
		x+=x&-x;
	}
}
node querynode(int x)
{
	node ret={0,0};
	while(x>0)
	{
		ret+=treenode[x];
		x-=x&-x;
	}
	return ret;
}
int dp1[maxn],dp2[maxn];
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
ll cntpre[maxn],cntlas[maxn];
ll ans[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		all.push_back(arr[i]);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=1;i<=n;i++)
		arr[i]=getid(arr[i]);
	int len=0;
	for(int i=1;i<=n;i++)
	{
		dp1[i]=query(arr[i]-1)+1;
		add(arr[i],dp1[i]);
		len=max(len,dp1[i]);
	}
	for(int i=1;i<=n;i++)
		arr[i]=-arr[i]+maxn-2;
	memset(tree,0,sizeof(tree));
	for(int i=n;i>=1;i--)
	{
		dp2[i]=query(arr[i]-1)+1;
		add(arr[i],dp2[i]);
	}
	addnode(1,0,1);
	for(int i=n;i>=1;i--)
	{
		if(dp1[i]+dp2[i]-1!=len) continue;
		cntlas[i]=querynode(arr[i]-1).cnt;
		addnode(arr[i],dp2[i],cntlas[i]);
	}
	for(int i=1;i<=n;i++)
		arr[i]=-(arr[i]+2-maxn);
	memset(treenode,0,sizeof(treenode));
	addnode(1,0,1);
	for(int i=1;i<=n;i++)
	{
		//dbg(i,dp1[i],dp2[i]);
		if(dp1[i]+dp2[i]-1!=len) continue;
		cntpre[i]=querynode(arr[i]-1).cnt;
		addnode(arr[i],dp1[i],cntpre[i]);
	}
	ll tot=0;
	for(int i=1;i<=n;i++)
	{
		if(dp1[i]+dp2[i]-1==len)
		{
			ans[i]=1LL*cntpre[i]*cntlas[i]%mod;
	//		dbg(i,cntpre[i],cntlas[i]);
			if(dp1[i]==1)
				tot=(tot+ans[i])%mod;
		}
	}
	tot=inv(tot);
	for(int i=1;i<=n;i++)
		printf("%lld ",1LL*ans[i]*tot%mod);
	puts("");
}
