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
const int maxn=6050;
char maze[maxn][maxn];
int dx[]={2,2,-2,-2,4,-4},dy[]={-6,6,-6,6,0,0};
int vis[maxn][maxn];
int r,c;
int bfs(PII st,PII ed)
{
	for(int i=0;i<=4*r+3;i++)
		for(int j=0;j<=6*c+3;j++)
			vis[i][j]=-1;
	queue<PII> q;
	q.push(st);
	vis[st.first][st.second]=1;
	while(!q.empty())
	{
		PII u=q.front();q.pop();
		if(u.first==ed.first&&u.second==ed.second)
			return vis[u.first][u.second];
		for(int i=0;i<6;i++)
		{
			int nx=u.first+dx[i],ny=u.second+dy[i];
			if(nx<=1||nx>=4*r+3||ny<=1||ny>=6*c+3) continue;
			int midx=(nx+u.first)/2,midy=(ny+u.second)/2;
			if(maze[midx][midy]!=' ') continue;
			if(vis[nx][ny]==-1)
			{
				vis[nx][ny]=vis[u.first][u.second]+1;
				q.push(make_pair(nx,ny));
			}
		}
	}
	return -1;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>r>>c>>ws;
		PII st,ed;
		for(int i=1;i<=4*r+3;i++)
		{
			string tmp;
			getline(cin,tmp);
			for(int j=1;j<=tmp.length();j++)
			{
				maze[i][j]=tmp[j-1];
				if(maze[i][j]=='S')
					st=make_pair(i,j);
				else if(maze[i][j]=='T')
					ed=make_pair(i,j);
			}
		}
		cout<<bfs(st,ed)<<'\n';
	}
}
