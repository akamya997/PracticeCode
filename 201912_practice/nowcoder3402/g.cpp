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
typedef pair<int,int> pi;
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
const int INF=0x3f3f3f3f;
const int maxn=1005;
char maze[maxn][maxn];
bool vis[maxn][maxn];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int n,m;
inline bool check(int x,int y)
{
	return maze[x][y]=='j'||maze[x][y]=='e'||maze[x][y]=='s'||maze[x][y]=='i';
}
void dfs(int x,int y)
{
	if(vis[x][y]||x<0||y<0||x>=n||y>=m) return;
	if(!check(x,y)) return;
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		dfs(nx,ny);
	}
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",maze[i]);
			for(int j=0;j<m;j++)
				 vis[i][j]=0;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(!vis[i][j]&&check(i,j))
				{
					dfs(i,j);
					ans++;
				}
			}
		}
		printf("%d\n",ans);
		
	}
}
