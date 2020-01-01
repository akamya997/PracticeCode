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
const int maxn=1e5+7;
vi G[maxn];
int dis[2][maxn];
int vis[maxn];
void dfs(int tp,int u,int fa=-1)
{
	for(auto v:G[u])if(v!=fa)
	{
		dis[tp][v]=dis[tp][u]+1;
		dfs(tp,v,u);
	}
}
int main()
{
	int n,u,v;
	cin>>n>>u>>v;
	for(int i=1,x,y;i<n;i++)
	{
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dis[0][u]=dis[1][v]=0;
	dfs(0,u);
	dfs(1,v);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=dis[0][i],y=dis[1][i];
		if(x<y)
			ans=max(ans,y-1);
	}
	cout<<ans<<endl;

}
