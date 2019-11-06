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
struct Edge{
	int u,v,x,tp,id;
	bool operator<(const Edge& a)const{
		if(x==a.x) return tp>a.tp;
		return x<a.x;
	}
};
const int maxn=2e5+7;
Edge all[maxn];
int n,m;

#define lc ch[x][0]
#define rc ch[x][1]
namespace LCT
{
int fa[maxn], ch[maxn][2], val[maxn],id[maxn], mm[maxn], lz[maxn];
inline bool nroot(int x)
{
    return ch[fa[x]][0] == x || ch[fa[x]][1] == x;
}

inline void pushup(int x) //维护链信息
{
	mm[x]=val[x];
	id[x]=x;
	if(mm[x]>mm[lc])
	{
		mm[x]=mm[lc];
		id[x]=id[lc];
	}
	if(mm[x]>mm[rc])
	{
		mm[x]=mm[rc];
		id[x]=id[rc];
	}
}

inline void pushr(int x)
{
    swap(lc, rc);
    lz[x] ^= 1;
} //反转
inline void pushdown(int x)
{
    if (lz[x])
    {
        if (lc)
            pushr(lc);
        if (rc)
            pushr(rc);
        lz[x] = 0;
    }
}

void rotate(int x) //单次旋转
{
    int y = fa[x], z = fa[y], k = ch[y][1] == x, w = ch[x][!k];
    if (nroot(y))
        ch[z][ch[z][1] == y] = x;
    ch[x][!k] = y;
    ch[y][k] = w;
    if (w)
        fa[w] = y;
    fa[y] = x;
    fa[x] = z;
    pushup(y);
}
void pushall(int x) //递归下放标记
{
    if (nroot(x))
        pushall(fa[x]);
    pushdown(x);
}
void splay(int x)
{
    pushall(x);
    while (nroot(x))
    {
        int y = fa[x];
        int z = fa[y];
        if (nroot(y))
            rotate((ch[y][0] == x) ^ (ch[z][0] == y) ? x : y);
        rotate(x);
    }
    pushup(x);
}
void access(int x)
{
    for (int y = 0; x; x = fa[y = x])
    {
        splay(x);
        rc = y;
        pushup(x);
    }
}
void makeroot(int x)
{
    access(x);
    splay(x);
    pushr(x);
}
int findroot(int x)
{
    access(x);
    splay(x);
    while (lc)
        pushdown(x), x = lc;
    splay(x);
    return x;
}
void split(int x, int y)
{
    makeroot(x);
    access(y);
    splay(y);
}
void link(int x, int y)
{
    makeroot(x);
    if (findroot(y) != x)
        fa[x] = y;
}
void cut(int x, int y)
{
    makeroot(x);
    if (findroot(y) == x && fa[y] == x && !ch[y][0])
    {
        fa[y] = ch[x][1] = 0;
        pushup(x);
    }
}
}; // namespace LCT
struct D
{
	int u,v,w;
}edge[maxn];
bool vis[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	int t=0;
	for(int i=1,u,v,l,r;i<=m;i++)
	{
		scanf("%d%d%d%d",&u,&v,&l,&r);
		edge[i]=D{u,v,r};
		all[t++]={u,v,l,r,i};
		all[t++]={u,v,r,-1,i};
	}
	sort(all,all+t);

	LCT::mm[0]=INF;
	for(int i=1;i<=m;++i)
		LCT::val[n+i]=edge[i].w;
	for(int i=1;i<=n;++i)
		LCT::val[i]=0x3f3f3f3f;
	//for(int i=1;i<=m+n;i++)
	//	LCT::mm[i]=LCT::val[i];
	ll ans=0;
	int pre=0;
	for(int i=0;i<t;i++)
	{

		int u=edge[all[i].id].u,v=edge[all[i].id].v;
		int id=all[i].id;
		if(all[i].tp!=-1)
		{
			//insert a segment
			if(LCT::findroot(u)!=LCT::findroot(v))
			{
				LCT::link(id+n,u);
				LCT::link(id+n,v);
			}
			else
			{
				LCT::split(u,v);
				if(LCT::mm[v]<all[i].tp)	
				{
					int getid=LCT::id[v]; 
					LCT::cut(getid,edge[getid-n].u);
					LCT::cut(getid,edge[getid-n].v);
					vis[getid-n]=1;
					LCT::link(id+n,u);
					LCT::link(id+n,v);
				}
			}
			pre=max(pre,all[i].x-1);
			if(LCT::findroot(1)==LCT::findroot(n))
			{
				LCT::split(1,n);
				ans+=LCT::mm[n]-pre;
				pre=LCT::mm[n];
			}

		}
		else{
			if(!vis[all[i].id])
			{
				LCT::cut(id+n,edge[id].v);
				LCT::cut(id+n,edge[id].u);
			}
		}
	}
	printf("%lld\n",ans);

}
