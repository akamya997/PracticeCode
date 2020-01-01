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
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
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
vi all;
inline int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin();
}
const int maxn=2e5+7;
pi pt[maxn];
vc<pi> line[maxn],col[maxn];
set<pi> sline[maxn],scol[maxn];
queue<pi> q;
map<pi,bool> vis;
ll ans;
ll solveline(int id,ll L,ll R)
{
	auto it=sline[id].lower_bound(make_pair(L,all[id]));
	while(it!=sline[id].end()&&(*it)<=make_pair(R,all[id]))
	{
		auto v=(*it);
		if(!vis.count(v))
		{
			q.push(v);
			vis[v]=1;
		}
		it++;
		sline[id].erase(v);
	}
	return lower_bound(line[id].begin(),line[id].end(),make_pair(R+1,all[id]))-lower_bound(line[id].begin(),line[id].end(),make_pair(L,all[id]));
}
ll solvecol(int id,ll D,ll U)
{
	D++;
	U--;
	if(D>U) return 0;
	auto it=scol[id].lower_bound(make_pair(all[id],D));
	while(it!=scol[id].end()&&(*it)<=make_pair(all[id],U))
	{
		auto v=(*it);
		if(!vis.count(v))
		{
			q.push(v);
			vis[v]=1;
		}
		it++;
		scol[id].erase(v);
	}
	return lower_bound(col[id].begin(),col[id].end(),make_pair(all[id],U+1))-lower_bound(col[id].begin(),col[id].end(),make_pair(all[id],D));
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a,b;
	cin>>n>>a>>b;
	for(int i=1,x,y;i<=n;i++)
	{
		cin>>x>>y;
		pt[i].first=x+y;
		pt[i].second=x-y;
		all.push_back(pt[i].first);
		all.push_back(pt[i].second);
	}
	mkuni(all);
	for(int i=1;i<=n;i++)
	{
		int x=getid(pt[i].first),y=getid(pt[i].second);
		line[y].push_back(pt[i]);
		col[x].push_back(pt[i]);
		sline[y].insert(pt[i]);
		scol[x].insert(pt[i]);
	}
	int sz=all.size();
	for(int i=0;i<=sz;i++)
	{
		sort(line[i].begin(),line[i].end());
		sort(col[i].begin(),col[i].end());
	}
	q.push(pt[a]);
	vis[pt[a]]=1;
	ll dis=max(abs(pt[a].first-pt[b].first),abs(pt[a].second-pt[b].second));
	while(!q.empty())
	{
		auto u=q.front();q.pop();
		ll U=u.second+dis,D=u.second-dis,L=u.first-dis,R=u.first+dis;
		{
			int id=getid(U);
			if(all[id]==U)
				ans+=solveline(id,L,R);
		}
		{
			int id=getid(D);
			if(all[id]==D)
				ans+=solveline(id,L,R);
		}
		{
			int id=getid(L);
			if(all[id]==L)
				ans+=solvecol(id,D,U);
		}
		{
			int id=getid(R);
			if(all[id]==R)
				ans+=solvecol(id,D,U);
		}
	}
	cout<<ans/2<<endl;

}
