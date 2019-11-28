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
typedef pair<int,int> PII;
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
const int maxn=1e6+7;
string maze[maxn];
string ans[maxn];
string cur[maxn];
string tmp[maxn];
int n,m;
int dx[]={0,1,0,-1,1,1,-1,-1},dy[]={1,0,-1,0,-1,1,-1,1};
bool check(int T)
{
	if(T*2>=n||T*2>=m) return false;
	vector<vi> mark(n+1,vi(m+1));
	vector<vi> dp(n+1,vi(m+1));
	vector<vi> vis(n+1,vi(m+1,-1));
	mark[0][0]++;
	mark[T][T]--;
	mark[T][m-T]++;
	mark[n-T][T]++;
	mark[n-T][m-T]--;
	for(int i=0;i<n;i++)
	{
		cur[i]="";
		for(int j=0;j<m;j++)
		{
			cur[i]+='.';
			if(maze[i][j]!='X')
			{
				int lx=max(0,i-T),ly=max(0,j-T);
				int rx=min(n-1,i+T),ry=min(m-1,j+T);
				mark[lx][ly]++;
				mark[lx][ry+1]--;
				mark[rx+1][ly]--;
				mark[rx+1][ry+1]++;
			}
		}
	}
	dp[0][0]=mark[0][0];
	for(int i=1;i<n;i++) dp[i][0]=dp[i-1][0]+mark[i][0];
	for(int i=1;i<m;i++) dp[0][i]=dp[0][i-1]+mark[0][i];
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			dp[i][j]=-dp[i-1][j-1]+dp[i][j-1]+dp[i-1][j]+mark[i][j];
	int cnt=0;
	queue<PII> q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(dp[i][j]==0)
			{
				if(maze[i][j]=='X')
				{
					cnt++;
					cur[i][j]=maze[i][j];
					q.push(make_pair(i,j));
					vis[i][j]=0;
				}
			}
		}
		tmp[i]=cur[i];
	}
	while(!q.empty())
	{
		auto u=q.front();q.pop();
		tmp[u.first][u.second]='X';
		if(vis[u.first][u.second]>=T) continue;
		for(int i=0;i<8;i++)
		{
			int nx=u.first+dx[i],ny=u.second+dy[i];
			if(nx<0||nx>=n||ny<0||ny>=m) continue;
			if(vis[nx][ny]!=-1) continue;
			q.push(make_pair(nx,ny));
			vis[nx][ny]=vis[u.first][u.second]+1;
		}
	}
	for(int i=0;i<n;i++) if(tmp[i]!=maze[i]) return false;
	return cnt>0;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>maze[i];
	int L=1,R=min(n,m)-1;
	int op=0;
	while(L<=R)
	{
		int mid=L+R>>1;
		if(check(mid))
		{
			L=mid+1;
			op=mid;
			for(int i=0;i<n;i++) ans[i]=cur[i];
		}
		else R=mid-1;
	}
	cout<<op<<endl;
	if(!op)
		for(int i=0;i<n;i++) cout<<maze[i]<<'\n';
	else for(int i=0;i<n;i++) cout<<ans[i]<<'\n';
}
