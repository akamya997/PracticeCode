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
char maze[16][16];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
//D,R,U,L
string ans="";
int stx,sty,edx,edy;
void dfs(int x,int y,int dir)
{
	if(dir==1&&maze[x+1][y]=='#')
		ans+='D';
	else if(dir==3&&maze[x-1][y]=='#')
		ans+='U';
	else if(dir==2&&maze[x][y+1]=='#')
		ans+='R';
	else if(dir==0&&maze[x][y-1]=='#')
		ans+='L';
	if(x==edx&&y==edy) return;
	int nx=x+dx[dir],ny=y+dy[dir];
	if(maze[nx][ny]!='#')
	{
		dfs(nx,ny,dir);
		return;
	}
	while(maze[nx][ny]=='#')
	{
		dir=(dir-1+4)%4;
		nx=x+dx[dir],ny=y+dy[dir];
	}
	dfs(x,y,dir);
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>maze[i];
		for(int j=0;j<n;j++)
		{
			if(maze[i][j]=='S')
				stx=i,sty=j;
			if(maze[i][j]=='T')
				edx=i,edy=j;
		}
	}
	int dir=1;
	dfs(stx,sty,dir);
	cout<<ans<<endl;

}
