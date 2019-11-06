#pragma GCC optimize (3)
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
vector<int> allx,ally;
inline int getx(int x)
{
	return lower_bound(allx.begin(),allx.end(),x)-allx.begin()+1;
}
inline int gety(int x)
{
	return lower_bound(ally.begin(),ally.end(),x)-ally.begin()+1;
}
struct Rec{
	int x1,y1,x2,y2;
}rec[205];
int cnt[405][405][4];
double dis[405][405];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int n;
struct node{
	double dis;int x,y;
	inline bool operator<(const node& a)const{
		return dis>a.dis;
	}
};
bool vis[405][405];
inline bool inrec(int r,int c,Rec cur)
{
	return r>=cur.x1&&r<=cur.x2&&c>=cur.y1&&c<=cur.y2;
}
inline void opt(int r,int c)
{
	for(int i=0;i<n;i++)
	{
		if(!inrec(r,c,rec[i])) continue;
		for(int j=0;j<4;j++)
		{
			int nr=r+dx[j],nc=c+dy[j];
			if(inrec(nr,nc,rec[i]))
				cnt[r][c][j]++;
		}
	}
}
double dijstra(Rec tar)
{
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=allx.size();i++)
		for(int j=0;j<=ally.size();j++)
			dis[i][j]=1e18;
	dis[tar.x1][tar.y1]=0;
	priority_queue<node> q;
	q.push(node{0,tar.x1,tar.y1});
	while(!q.empty())
	{
		auto u=q.top();q.pop();
		if(vis[u.x][u.y]) continue;
		vis[u.x][u.y]=1;
		for(int i=0;i<4;i++)
		{
			int nx=u.x+dx[i],ny=u.y+dy[i];
			if(!nx||!ny||nx-1==allx.size()||ny-1==ally.size()) continue;
			double w=abs(allx[u.x-1]-allx[nx-1])+abs(ally[u.y-1]-ally[ny-1]);
			w/=cnt[u.x][u.y][i]+1;
			if(dis[nx][ny]>u.dis+w)
			{
				dis[nx][ny]=w+u.dis;
				q.push(node{dis[nx][ny],nx,ny});
			}
		}
	}
	return dis[tar.x2][tar.y2];
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		allx.clear();
		ally.clear();
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&rec[i].x1,&rec[i].y1,&rec[i].x2,&rec[i].y2);
			allx.push_back(rec[i].x1);
			allx.push_back(rec[i].x2);
			ally.push_back(rec[i].y1);
			ally.push_back(rec[i].y2);
		}
		Rec tar;
		scanf("%d%d%d%d",&tar.x1,&tar.y1,&tar.x2,&tar.y2);
		allx.push_back(tar.x1);
		allx.push_back(tar.x2);
		ally.push_back(tar.y1);
		ally.push_back(tar.y2);
		sort(allx.begin(),allx.end());
		sort(ally.begin(),ally.end());
		allx.erase(unique(allx.begin(),allx.end()),allx.end());
		ally.erase(unique(ally.begin(),ally.end()),ally.end());
		tar.x1=getx(tar.x1);tar.x2=getx(tar.x2);
		tar.y1=gety(tar.y1);tar.y2=gety(tar.y2);
		for(int i=0;i<n;i++)
		{
			rec[i].x1=getx(rec[i].x1);
			rec[i].x2=getx(rec[i].x2);
			rec[i].y1=gety(rec[i].y1);
			rec[i].y2=gety(rec[i].y2);
		}
		for(int i=1;i<=allx.size();i++)
			for(int j=1;j<=ally.size();j++)
				opt(i,j);
		double ans=dijstra(tar);
		printf("%.5f\n",ans);
	}
}
