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
const ll INF=0x3f3f3f3f3f3f3f3f;
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
const int maxn=2005;
struct Point{
	int x,y,w;
}pt[maxn];
vector<int> allx,ally;
int getx(int x)
{
	return lower_bound(allx.begin(),allx.end(),x)-allx.begin()+1;
}
int gety(int x)
{
	return lower_bound(ally.begin(),ally.end(),x)-ally.begin()+1;
}
struct Sgt{
	ll le,ri,tot,sum;
}seg[maxn<<2];
int n;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
void init(int L=1,int R=n,int o=1)
{
	seg[o].le=seg[o].ri=seg[o].tot=seg[o].sum=0;
	if(L==R)
		return;
	int mid=L+R>>1;
	init(Lson);
	init(Rson);
}
inline void pushup(int o)
{
	seg[o].le=max(seg[lson].le,seg[lson].sum+seg[rson].le);
	seg[o].ri=max(seg[rson].ri,seg[rson].sum+seg[lson].ri);
	seg[o].sum=seg[lson].sum+seg[rson].sum;
	seg[o].tot=max({seg[lson].tot,seg[rson].tot,seg[lson].ri+seg[rson].le});
}
void update(int p,ll val,int L=1,int R=n,int o=1)
{
	if(L==R)
	{
		seg[o].le+=val;
		seg[o].ri+=val;
		seg[o].tot+=val;
		seg[o].sum+=val;
		return ;
	}
	int mid=L+R>>1;
	if(p<=mid) update(p,val,Lson);
	else update(p,val,Rson);
	pushup(o);
}
vector<pair<int,ll> > xval[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		allx.clear();ally.clear();
		scanf("%d",&n);
		for(int i=0;i<=n;i++) xval[i].clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&pt[i].x,&pt[i].y,&pt[i].w);
			allx.push_back(pt[i].x);
			ally.push_back(pt[i].y);
		}
		sort(allx.begin(),allx.end());
		sort(ally.begin(),ally.end());
		allx.erase(unique(allx.begin(),allx.end()),allx.end());
		ally.erase(unique(ally.begin(),ally.end()),ally.end());
		for(int i=0;i<n;i++)
		{
			pt[i].x=getx(pt[i].x);
			pt[i].y=gety(pt[i].y);
			xval[pt[i].x].push_back(make_pair(pt[i].y,pt[i].w));
		}
		ll ans=0;
		for(int l=0;l<=n;l++)
		{
			init();
			for(int r=l+1;r<=n;r++)
			{
				for(auto& u:xval[r])
					update(u.first,u.second);
				ans=max(ans,seg[1].tot);
			}
		}
		printf("%lld\n",ans);
	}
}
