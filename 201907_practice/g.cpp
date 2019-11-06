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
const int maxn=55;
int maze[maxn][maxn];
struct Item{
	int z,t,tp;
}item[5005];
const int mxtime=100000;
int sx,tx,sy,ty;
struct node{
	int t,x,y,hp;
	bool operator<(const node&a)const{
		return t>a.t;
	}
};
bool vis[55][55][55];
int n,m,h,c,d;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void solve()
{
	memset(vis,0,sizeof(vis));
	priority_queue<node> q;
	q.push(node{0,sx,sy,h});
	int ans=-1;
	while(!q.empty())
	{
		auto u=q.top();q.pop();
		if(vis[u.x][u.y][u.hp]) continue;
		vis[u.x][u.y][u.hp]=1;
		if(u.x==tx&&u.y==ty)
		{
			ans=u.t;
			break;
		}
		for(int i=0;i<4;i++)
		{
			int nx=u.x+dx[i],ny=u.y+dy[i],nt=u.t+1,nh=u.hp;
			if(nx<=0||nx>n||ny<=0||ny>m) continue;
			if(item[maze[nx][ny]].tp==1)
			{
				Item cur=item[maze[nx][ny]];
				if(u.hp<=cur.z) continue;
				nh-=cur.z;
				nt+=cur.t;
				if(nt>mxtime) continue;
				q.push(node{nt,nx,ny,nh});
			}
			else if(item[maze[nx][ny]].tp==2)
			{
				Item cur=item[maze[nx][ny]];
				q.push(node{nt,nx,ny,nh});
				nt+=cur.t;
				if(nt>mxtime) continue;
				nh=min(h,nh+cur.z);
				q.push(node{nt,nx,ny,nh});
			}
			else q.push(node{nt,nx,ny,nh});
		}
	}
	printf("%d\n",ans);
}
int main()
{
	int cnt=1;
	scanf("%d%d%d%d%d",&n,&m,&h,&c,&d);
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	for(int i=0,x,y,z,t;i<c;i++)
	{
		scanf("%d%d%d%d",&x,&y,&z,&t);
		maze[x][y]=cnt;
		item[cnt++]={z,t,1};
	}
	for(int i=0,x,y,z,t;i<d;i++)
	{
		scanf("%d%d%d%d",&x,&y,&z,&t);
		maze[x][y]=cnt;
		item[cnt++]={z,t,2};
	}
	solve();
}
