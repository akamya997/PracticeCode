#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const ll INF=0x3f3f3f3f3f3f3f3f;

#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
const int maxn=1e5+7;
int n;
vc<PII> event[maxn];
ll mi[maxn<<2];
ll lz[maxn<<2];
inline void pushdown(int o)
{
	if(lz[o]!=INF)
	{
		mi[lson]=min(mi[lson],lz[o]);
		mi[rson]=min(mi[rson],lz[o]);
		lz[lson]=min(lz[lson],lz[o]);
		lz[rson]=min(lz[rson],lz[o]);
		lz[o]=INF;
	}
}
inline void pushup(int o)
{
	mi[o]=min(mi[lson],mi[rson]);
}
void update(int l,int r,ll val,int L=1,int R=n,int o=1)
{
	if(l<=L&&r>=R)
	{
		mi[o]=min(mi[o],val);
		lz[o]=min(lz[o],val);
		return;
	}
	pushdown(o);
	int mid=L+R>>1;
	if(l<=mid) update(l,r,val,Lson);
	if(r>mid) update(l,r,val,Rson);
	pushup(o);
}
ll query(int p,int L=1,int R=n,int o=1)
{
	if(L==R) return mi[o];
	int mid=L+R>>1;
	pushdown(o);
	if(p<=mid) return query(p,Lson);
	else return query(p,Rson);
}

int main()
{
	memset(lz,0x3f,sizeof(lz));
	memset(mi,0x3f,sizeof(mi));
	int m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		event[l].push_back(make_pair(r,c));
	}
	update(1,1,0);
	for(int i=1;i<n;i++)
	{
		ll val=query(i);
		for(auto& v:event[i])
			update(i,v.first,val+v.second);
	}
	ll ans=query(n);
	if(ans==INF) ans=-1;
	printf("%lld\n",ans);
}
