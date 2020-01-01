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
const int maxn=1e3+7;
struct Point{
	int x,y,r;
}pt[maxn];
double dis[maxn];
bool vis[maxn];
struct D{
	int u;
	double d;
	bool operator<(const D&a)const{
		return d>a.d;
	}
};
inline double getdis(int i,int j)
{
	return sqrt(1LL*(pt[i].x-pt[j].x)*(pt[i].x-pt[j].x)+1LL*(pt[i].y-pt[j].y)*(pt[i].y-pt[j].y));
}
int n;
void dij()
{
	priority_queue<D> q;
	q.push({0,0});
	for(int i=0;i<maxn;i++) dis[i]=1e15;
	dis[0]=0;
	while(!q.empty())
	{
		auto u=q.top();q.pop();
		if(vis[u.u]) continue;
		vis[u.u]=1;
		for(int i=0;i<=n;i++)
		{
			if(i==u.u) continue;
			double d=getdis(i,u.u);
			d-=pt[i].r+pt[u.u].r;
			if(d<0) d=0;
			if(dis[i]>u.d+d)
			{
				dis[i]=u.d+d;
				q.push({i,dis[i]});
			}
		}
	}
}
int main()
{
	int xs,ys,xt,yt;
	scanf("%d%d%d%d",&xs,&ys,&xt,&yt);
	scanf("%d",&n);
	pt[0]={xs,ys,0};
	pt[n+1]={xt,yt,0};
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&pt[i].x,&pt[i].y,&pt[i].r);
	n++;
	dij();
	printf("%.10f\n",dis[n]);
}
