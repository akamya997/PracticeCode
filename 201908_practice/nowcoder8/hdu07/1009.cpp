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
vector<int> all;
const int var=18;
int fa[var*var];
inline int getid(int x)
{
	return (lower_bound(all.begin(),all.end(),x)-all.begin()+1)*2;
}
bool col[var][var];
void init()
{
	all.clear();
	for(int i=0;i<var*var;i++) fa[i]=i;
	memset(col,0,sizeof(col));
}
int tot;
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x);y=Find(y);
	if(x!=y)
		tot--;
	fa[y]=x;
}
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
struct Point{
	int x,y;
}a,b,c,d;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		tot=var*var;
		init();
		scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y);
		scanf("%d%d%d%d",&c.x,&c.y,&d.x,&d.y);
		all.push_back(a.x);all.push_back(b.x);
		all.push_back(c.x);all.push_back(d.x);
		all.push_back(a.y);all.push_back(b.y);
		all.push_back(c.y);all.push_back(d.y);
		sort(all.begin(),all.end());
		all.erase(unique(all.begin(),all.end()),all.end());
		a.x=getid(a.x),b.x=getid(b.x),c.x=getid(c.x),d.x=getid(d.x);
		a.y=getid(a.y),b.y=getid(b.y),c.y=getid(c.y),d.y=getid(d.y);
		for(int i=a.x;i<=b.x;i++) col[i][a.y]=col[i][b.y]=1;
		for(int i=a.y;i<=b.y;i++) col[a.x][i]=col[b.x][i]=1;
		for(int i=c.x;i<=d.x;i++) col[i][c.y]=col[i][d.y]=1;
		for(int i=c.y;i<=d.y;i++) col[c.x][i]=col[d.x][i]=1;
		for(int i=0;i<var;i++)
		{
			for(int j=0;j<var;j++)
				if(col[i][j]) 
				{
					tot--;
				}
		}
		for(int i=0;i<var;i++)
		{
			for(int j=0;j<var;j++)
			{
				if(!col[i][j])
				{
					for(int k=0;k<4;k++)
					{
						int nx=i+dx[k],ny=j+dy[k];
						if(nx<0||ny<0||nx>=var||ny>=var) continue;
						if(!col[nx][ny])
							Union(i*var+j,nx*var+ny);
					}
				}
			}
		}
		printf("%d\n",tot);
	}
}
