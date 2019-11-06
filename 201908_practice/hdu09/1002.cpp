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
const int maxn=4e5+7;
struct Seg{
	int x,y,val,tp;
	bool operator<(const Seg &a)const{
		if(val==a.val) return tp>a.tp;
		return val<a.val;
	}
}seg[maxn],rev[maxn];
bool cmp(Seg &a,Seg &b){
	if(a.val==b.val) return a.tp>b.tp;
	return a.val>b.val;
}
vector<int> all;
vector<int> allq;
inline int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
ll cnt[maxn<<2];
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
void build(int L=1,int R=all.size(),int o=1)
{
	cnt[o]=0;
	if(L==R)
		return;
	int mid=L+R>>1;
	build(Lson);
	build(Rson);
}
void update(int p,int val,int L=1,int R=all.size(),int o=1)
{
	if(L==R)
	{
		cnt[o]+=val;
		return;
	}
	int mid=L+R>>1;
	if(p<=mid) update(p,val,Lson);
	else update(p,val,Rson);
	cnt[o]=cnt[lson]+cnt[rson];
}
ll query(int l,int r,int L=1,int R=all.size(),int o=1)
{
	if(l<=L&&r>=R)
		return cnt[o];
	int mid=L+R>>1;
	ll ret=0;
	if(l<=mid) ret+=query(l,r,Lson);
	if(r>mid) ret+=query(l,r,Rson);
	return ret;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		all.clear();
		allq.clear();
		int n,m,K;
		scanf("%d%d%d",&n,&m,&K);
		char op[5];
		int cnt=0,cnt2=0;
		all.push_back(0);
		all.push_back(n);
		all.push_back(m);
		seg[cnt++]={0,m,0,4};
		seg[cnt++]={0,m,n,0};
		seg[cnt++]={0,0,0,4};
		seg[cnt++]={0,0,n,0};
		seg[cnt++]={n,0,n,2};
		rev[cnt2++]={0,m,0,0};
		rev[cnt2++]={0,m,n,4};
		rev[cnt2++]={0,0,0,0};
		rev[cnt2++]={0,0,n,4};
		rev[cnt2++]={0,0,0,2};
		allq.push_back(n);
		for(int i=0,x,y;i<K;i++)
		{
			scanf("%d%d",&x,&y);
			scanf("%s",op);
			all.push_back(x);
			all.push_back(y);
			if(op[0]=='L')
			{
				seg[cnt++]={x,y,0,4};
				seg[cnt++]={x,y,x,0};
			}
			else if(op[0]=='R')
			{
				rev[cnt2++]={x,y,x,0};
				rev[cnt2++]={x,y,n,4};
			}
			else if(op[0]=='U')
			{
				seg[cnt++]={x,y,x,2};
				rev[cnt2++]={x,y,x,2};
			}
			else 
			{
				seg[cnt++]={x,y,x,3};
				rev[cnt2++]={x,y,x,3};
			}
		}
		sort(all.begin(),all.end());
		all.erase(unique(all.begin(),all.end()),all.end());
		for(int i=0;i<cnt;i++)
		{
			seg[i].x=getid(seg[i].x);
			seg[i].y=getid(seg[i].y);
			seg[i].val=getid(seg[i].val);
		}
		for(int i=0;i<cnt2;i++)
		{
			rev[i].x=getid(rev[i].x);
			rev[i].y=getid(rev[i].y);
			rev[i].val=getid(rev[i].val);
		}
		sort(seg,seg+cnt);
		sort(rev,rev+cnt2,cmp);
		build();
		ll ans=0;
		m=getid(m);
		int st=getid(0);
		for(int i=0;i<cnt;i++)
		{
			if(seg[i].tp==0)
				update(seg[i].y,-1);
			else if(seg[i].tp==4)
				update(seg[i].y,1);
			else if(seg[i].tp==2)
				ans+=query(seg[i].y,m)-1;
			else ans+=query(st,seg[i].y)-1;
		}
		build();
		for(int i=0;i<cnt2;i++)
		{
			if(rev[i].tp==0)
				update(rev[i].y,-1);
			else if(rev[i].tp==4)
				update(rev[i].y,1);
			else if(rev[i].tp==2)
				ans+=query(rev[i].y,m)-1;
			else ans+=query(st,rev[i].y)-1;
		}
		printf("%lld\n",ans-1);
	}
}
