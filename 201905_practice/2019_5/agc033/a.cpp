#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
char maze[1005][1005];
int h,w;
int vis[1005][1005];
struct P{
	int x,y;
};
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
void solve()
{
	memset(vis,-1,sizeof(vis));
	queue<P> q;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(maze[i][j]=='#')
			{
				q.push(P {i,j});
				vis[i][j]=0;
			}
		}
	}
	while(!q.empty())
	{
		P u=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=u.x+dx[i],ny=u.y+dy[i];
			if(nx<0||ny<0||nx>=h||ny>=w) continue;
			if(vis[nx][ny]!=-1) continue;
			q.push(P {nx,ny});
			vis[nx][ny]=vis[u.x][u.y]+1;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>h>>w;
	for(int i=0;i<h;i++)
		cin>>maze[i];
	solve();
	int ans=0;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			ans=max(ans,vis[i][j]);
		}
	}
	cout<<ans<<endl;
}
