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
struct state{
	int x,y,bx1,by1,bx2,by2;
	bool operator==(const state &a)const{
		return x==a.x&&y==a.y&&bx1==a.bx1&&by1==a.by1&&bx2==a.bx2&&by2==a.by2;
	}
};
int vis[13][13][13][13][13][13];
state pre[13][13][13][13][13][13];
char maze[13][13];
vector<PII> box;
vector<PII> tar;
PII st;
int n,m;
state bg,ed;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
inline bool judge(state S)
{
	if((S.bx1==tar[0].first&&S.bx2==tar[1].first&&S.by1==tar[0].second&&S.by2==tar[1].second)||(S.bx1==tar[1].first&&S.bx2==tar[0].first&&S.by1==tar[1].second&&S.by2==tar[0].second))
		return true;
	return false;
}
bool bfs()
{
	bool ok=0;
	if(box.size()==1) 
	{
		box.push_back(make_pair(-1,-1));
		tar.push_back(make_pair(-1,-1));
	}
	queue<state> q;
	q.push(state{st.first,st.second,box[0].first,box[0].second,box[1].first,box[1].second});
	bg=state{st.first,st.second,box[0].first,box[0].second,box[1].first,box[1].second};
	memset(vis,-1,sizeof(vis));
	while(!q.empty())
	{
		auto u=q.front();q.pop();
		if(judge(u)) 
		{
			ed=u;
			ok=1;
			break;
		}
		for(int i=0;i<4;i++)
		{
			state nxt=u;
			nxt.x+=dx[i],nxt.y+=dy[i];
			if(nxt.x<0||nxt.y<0||nxt.x>=n||nxt.y>=m||maze[nxt.x][nxt.y]=='#') continue;
			if(u.bx1==nxt.x&&u.by1==nxt.y)
			{
				int xx=nxt.x+dx[i],yy=nxt.y+dy[i];
				if(xx<0||yy<0||xx>=n||yy>=m||maze[xx][yy]=='#'||(xx==u.bx2&&yy==u.by2)) continue;
				nxt.bx1=xx;
				nxt.by1=yy;
			}
			if(u.bx2==nxt.x&&u.by2==nxt.y)
			{
				int xx=nxt.x+dx[i],yy=nxt.y+dy[i];
				if(xx<0||yy<0||xx>=n||yy>=m||maze[xx][yy]=='#'||(xx==u.bx1&&yy==u.by1)) continue;
				nxt.bx2=xx;nxt.by2=yy;
			}
			if(vis[nxt.x][nxt.y][nxt.bx1][nxt.by1][nxt.bx2][nxt.by2]!=-1) continue;
			q.push(nxt);
			vis[nxt.x][nxt.y][nxt.bx1][nxt.by1][nxt.bx2][nxt.by2]=vis[u.x][u.y][u.bx1][u.by1][u.bx2][u.by2]+1;
			pre[nxt.x][nxt.y][nxt.bx1][nxt.by1][nxt.bx2][nxt.by2]=u;
		}
	}
	return ok;
}
vector<char> ans;
void print(state cur)
{
	if(cur==bg) return;
	print(pre[cur.x][cur.y][cur.bx1][cur.by1][cur.bx2][cur.by2]);
	state pp=pre[cur.x][cur.y][cur.bx1][cur.by1][cur.bx2][cur.by2];
	if(cur.x==pp.x+1) ans.push_back('D');
	else if(cur.x==pp.x-1) ans.push_back('U');
	else if(cur.y==pp.y+1) ans.push_back('R');
	else ans.push_back('L');
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",maze[i]);
		for(int j=0;j<m;j++)
		{
			if(maze[i][j]=='B')
				box.push_back(make_pair(i,j));
			else if(maze[i][j]=='Q')
				st=make_pair(i,j);
			else if(maze[i][j]=='X')
				tar.push_back(make_pair(i,j));
		}
	}
	if(!bfs())
		puts("-1");
	else{
		print(ed);
		printf("%d\n",(int)ans.size());
		for(auto u:ans) printf("%c",u);
		puts("");
	}
}
