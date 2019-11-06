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
const int maxn=5e5+7;
const int inf=0x3f3f3f3f;
int n,m,cur,ans,root;
 
struct P
{
	int mn[2],mx[2],d[2],lch,rch;
	int& operator[](int x) {return d[x];}
	friend bool operator<(P x,P y) {return x[cur]<y[cur];}
	friend int dis(P x,P y) {return abs(x[0]-y[0])+abs(x[1]-y[1]);}
}p[maxn];
 
struct kdtree
{
	P t[maxn],T;
	int ans;
	void update(int k)
	{
		int l=t[k].lch,r=t[k].rch;
		for (int i=0;i<2;i++)
		{
			t[k].mn[i]=t[k].mx[i]=t[k][i];
			if (l) t[k].mn[i]=min(t[k].mn[i],t[l].mn[i]);
			if (r) t[k].mn[i]=min(t[k].mn[i],t[r].mn[i]);
			if (l) t[k].mx[i]=max(t[k].mx[i],t[l].mx[i]);
			if (r) t[k].mx[i]=max(t[k].mx[i],t[r].mx[i]);
 		}
	}
	int build(int l,int r,int now)
	{
		cur=now;
		int mid=(l+r)/2;
		nth_element(p+l,p+mid,p+r+1);
		t[mid]=p[mid];
		for (int i=0;i<2;i++) t[mid].mx[i]=t[mid].mn[i]=t[mid][i];
		if (l<mid) t[mid].lch=build(l,mid-1,now^1);
		if (r>mid) t[mid].rch=build(mid+1,r,now^1);
		update(mid);
		return mid;
	}
	int getmn(P x)
	{
		int ans=0;
		for (int i=0;i<2;i++)
		{
			ans+=max(T[i]-x.mx[i],0);
			ans+=max(x.mn[i]-T[i],0);
		}
		return ans;
	}
	int getmx(P x)
	{
		int ans=0;
		for (int i=0;i<2;i++) ans+=max(abs(T[i]-x.mn[i]),abs(T[i]-x.mx[i]));
		return ans;
	}
	void querymx(int k)
	{
		ans=max(ans,dis(t[k],T));
		int l=t[k].lch,r=t[k].rch,dl=-inf,dr=-inf;
		if (l) dl=getmx(t[l]);
		if (r) dr=getmx(t[r]);
		if (dl>dr)
		{
			if (dl>ans) querymx(l);
			if (dr>ans) querymx(r);
		}
		else
		{
			if (dr>ans) querymx(r);
			if (dl>ans) querymx(l);
		}
	}
	void querymn(int k)
	{
		if (dis(t[k],T)) ans=min(ans,dis(t[k],T));
		int l=t[k].lch,r=t[k].rch,dl=inf,dr=inf;
		if (l) dl=getmn(t[l]);
		if (r) dr=getmn(t[r]);
		if (dl<dr)
		{
			if (dl<ans) querymn(l);
			if (dr<ans) querymn(r);
		}
		else
		{
			if (dr<ans) querymn(r);
			if (dl<ans) querymn(l);
		}
	}
	int query(int f,int x,int y)
	{
		T[0]=x;T[1]=y;
		if (f==0) ans=-inf,querymx(root);
		else ans=inf,querymn(root);
		return ans;
	}
}kd;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i][0],&p[i][1]);
	root=kd.build(1,n,0);ans=inf;
	for(int i=1;i<=n;i++)
	{
		int mx=kd.query(0,p[i][0],p[i][1]),mi=kd.query(1,p[i][0],p[i][1]);
		ans=min(mx-mi,ans);
	}
	printf("%d\n",ans);
	
}
