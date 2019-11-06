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
const int maxn=4005;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};//d,r,u,l
struct node{
	int x,y,up;
};
int vis[100][maxn][6];
void bfs()
{
	memset(vis,-1,sizeof(vis));
	queue<node> q;
	q.push({0,0,0});
	vis[0][0][0]=0;
	while(!q.empty())
	{
		auto u=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=u.x+dx[i],ny=u.y+dy[i];
			if(nx<0||ny<0||nx>=100||ny>=maxn) continue;
			int nup;
			if(i==0)
			{
				if(u.up==0) nup=4;
				else if(u.up==1) nup=0;
				else if(u.up==2||u.up==3) nup=u.up;
				else if(u.up==4) nup=5;
				else nup=1;
			}
			else if(i==1)
			{
				if(u.up==1||u.up==4) nup=u.up;
				else if(u.up==0) nup=2;
				else if(u.up==2) nup=5;
				else if(u.up==3) nup=0;
				else nup=3;
			}
			else if(i==2)
			{
				if(u.up==0) nup=1;
				else if(u.up==1) nup=5;
				else if(u.up==2||u.up==3) nup=u.up;
				else if(u.up==4) nup=0;
				else nup=4;
			}
			else{
				if(u.up==1||u.up==4) nup=u.up;
				else if(u.up==0) nup=3;
				else if(u.up==2) nup=0;
				else if(u.up==3) nup=5;
				else nup=2;
			}
			if(vis[nx][ny][nup]==-1)
			{
				vis[nx][ny][nup]=vis[u.x][u.y][u.up]+1;
				q.push({nx,ny,nup});
			}
		}

	}
}
int getdis(int x1,int y1,int x2,int y2)
{
	int xx=abs(x2-x1),yy=abs(y2-y1);
	if(xx>yy) swap(xx,yy);
	if(xx>=3) return xx+yy;
	return vis[xx][yy][0];
}
int dis[1<<17][17];
struct Point{
	int x,y;
}p[17];
int main()
{
	bfs();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		p[0]={0,0};
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
		n++;
		memset(dis,0x3f,sizeof(dis));
		dis[1][0]=0;
		for(int i=1;i<(1<<n);i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!(i&(1<<j))) continue;
				for(int k=0;k<n;k++)
				{
					if(i&(1<<k)) continue;
					dis[i|(1<<k)][k]=min(dis[i|(1<<k)][k],dis[i][j]+getdis(p[j].x,p[j].y,p[k].x,p[k].y));
				}
			}
		}
		int ans=INF;
		for(int i=1;i<n;i++) ans=min(ans,dis[(1<<n)-1][i]);
		printf("%d\n",ans);
	}
}
