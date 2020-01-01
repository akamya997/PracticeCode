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
bool vis[maxn];
struct D{
	int id;
	ll x,y;
	bool operator<(const D& a)const{
		if(a.x==x)
			return y<a.y;
		return x<a.x;
	}
};
D pt[maxn];
int cc[maxn];
vc<D> all;
ll dis;
inline void add(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
void solve(ll k)
{
	for(int i=0,j=0,l=0,r=0;i<all.size();i++)
	{
		while(all[l].x<all[i].x-dis||(all[l].x==all[i].x-dis&&all[l].y<all[i].y-k)) l++;
		r=max(r,l);
		while(all[r].x==all[i].x-dis&&all[r].y<=all[i].y+k) r++;
		cc[all[i].id]+=r-l;
		j=max(j,l);
		if(l>=r) continue;
		add(all[i].id,all[l].id);
		while(j<r-1)
		{
			add(all[j].id,all[j+1].id);
			j++;
		}

	}
}
ll ans=0;
void dfs(int u)
{
	if(vis[u]) return;
	vis[u]=1;
	ans+=cc[u];
	for(auto v:G[u])
		dfs(v);
}
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	for(int i=1,x,y;i<=n;i++)
	{
		cin>>x>>y;
		pt[i].x=x+y;
		pt[i].y=x-y;
		pt[i].id=i;
		all.push_back(pt[i]);
	}
	D st=pt[a];
	dis=max(abs(st.x-pt[b].x),abs(st.y-pt[b].y));
	sort(all.begin(),all.end());
	solve(dis);
	for(int i=0;i<n;i++)
		swap(all[i].x,all[i].y);
	sort(all.begin(),all.end());
	solve(dis-1);
	dfs(a);
	cout<<ans<<endl;
}
