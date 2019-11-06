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
struct Cube{
	int x,y,z;
};
const int maxn=105;
struct Query{
	Cube a,b;
	int ans1,ans2;
}Q[1005];
int n,m,h;
const int maxv=2e6+7;
int fa[maxv];
int getid(int x,int y,int z)
{
	return x*m*h+y*h+z;
}
void init()
{
	for(int i=0;i<=n*m*h;i++) fa[i]=i;
}
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
int cnt;
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	if(x==y) return;
	cnt--;
	fa[y]=x;
}
int isrock[maxn][maxn][maxn];
int dx[]={0,0,0,0,1,-1},dy[]={0,0,1,-1,0,0},dz[]={1,-1,0,0,0,0};
void Union(int x,int y,int z)
{
	for(int i=0;i<6;i++)
	{
		int nx=x+dx[i],ny=y+dy[i],nz=z+dz[i];
		if(nx<0||nx>=n||ny<0||ny>=m||nz<0||nz>=h) continue;
		if(isrock[nx][ny][nz])
			Union(getid(x,y,z),getid(nx,ny,nz));
	}
}
bool isair[maxn][maxn][maxn];
void Unionair(int x,int y,int z)
{
	isair[x][y][z]=1;
	for(int i=0;i<6;i++)
	{
		int nx=x+dx[i],ny=y+dy[i],nz=z+dz[i];
		if(nx<0||nx>=n||ny<0||ny>=m||nz<0||nz>=h) continue;
		if(isair[nx][ny][nz])
			Union(getid(x,y,z),getid(nx,ny,nz));
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&h);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				for(int k=0;k<h;k++)
					isrock[i][j][k]=isair[i][j][k]=0;
		init();
		int q;
		scanf("%d",&q);
		dbg(q,T,"hhh");
		for(int i=0;i<q;i++)
			scanf("%d%d%d%d%d%d",&Q[i].a.x,&Q[i].a.y,&Q[i].a.z,&Q[i].b.x,&Q[i].b.y,&Q[i].b.z);
		cnt=0;
		for(int i=0;i<q;i++)
		{
			for(int x=Q[i].a.x;x<=Q[i].b.x;x++)
			{
				for(int y=Q[i].a.y;y<=Q[i].b.y;y++)
				{
					for(int z=Q[i].a.z;z<=Q[i].b.z;z++)
					{
						isrock[x][y][z]++;
					}
				}
			}
			cnt+=(Q[i].b.x-Q[i].a.x+1)*(Q[i].b.y-Q[i].a.y+1)*(Q[i].b.z-Q[i].a.z+1);
			for(int y=Q[i].a.y;y<=Q[i].b.y;y++)
			{
				for(int z=Q[i].a.z;z<=Q[i].b.z;z++)
				{
					Union(Q[i].a.x,y,z);
					Union(Q[i].b.x,y,z);
				}
			}
			for(int x=Q[i].a.x;x<=Q[i].b.x;x++)
				for(int z=Q[i].a.z;z<=Q[i].b.z;z++)
				{
					Union(x,Q[i].a.y,z);
					Union(x,Q[i].b.y,z);
				}
			for(int x=Q[i].a.x;x<=Q[i].b.x;x++)
				for(int y=Q[i].a.y;y<=Q[i].b.y;y++)
				{
					Union(x,y,Q[i].a.z);
					Union(x,y,Q[i].b.z);
				}
			for(int x=Q[i].a.x+1;x<=Q[i].b.x-1;x++)
			{
				for(int y=Q[i].a.y+1;y<=Q[i].b.y-1;y++)
				{
					for(int z=Q[i].a.z+1;z<=Q[i].b.z-1;z++)
					{
                        cnt--;
					}
				}
			}
			Q[i].ans1=cnt;
		}
		cnt=0;
		init();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				for(int k=0;k<h;k++)
				{
					if(!isrock[i][j][k])
					{
						cnt++;
						Unionair(i,j,k);
					}
				}
			}
		}
		for(int i=q-1;i>=0;i--)
		{
			Q[i].ans2=cnt;
			if(!i) break;
			int inside=(Q[i].b.x-Q[i].a.x-1)*(Q[i].b.y-Q[i].a.y-1)*(Q[i].b.z-Q[i].a.z-1);
			cnt+=(Q[i].b.x-Q[i].a.x+1)*(Q[i].b.y-Q[i].a.y+1)*(Q[i].b.z-Q[i].a.z+1)-(inside>0?inside:0);
			for(int y=Q[i].a.y;y<=Q[i].b.y;y++)
			{
				for(int z=Q[i].a.z;z<=Q[i].b.z;z++)
				{
					Unionair(Q[i].a.x,y,z);
					Unionair(Q[i].b.x,y,z);
				}
			}
			for(int x=Q[i].a.x;x<=Q[i].b.x;x++)
				for(int z=Q[i].a.z;z<=Q[i].b.z;z++)
				{
					Unionair(x,Q[i].a.y,z);
					Unionair(x,Q[i].b.y,z);
				}
			for(int x=Q[i].a.x;x<=Q[i].b.x;x++)
				for(int y=Q[i].a.y;y<=Q[i].b.y;y++)
				{
					Unionair(x,y,Q[i].a.z);
					Unionair(x,y,Q[i].b.z);
				}
		}
		for(int i=0;i<q;i++)
			printf("%d %d\n",Q[i].ans1,Q[i].ans2);
	}
}

