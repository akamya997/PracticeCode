#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
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
const ll INF=1e18;
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
struct node{
	ll x,y;
	string ans;
};
ll a,b,c,d;
map<PII,bool> vis;
string op;
inline bool inc(ll x,ll y,ll z)
{
	return x<=y&&y<=z;
}
bool bfs()
{
	vis.clear();
	queue<node> q;
	q.push({a,b,""});
	while(!q.empty())
	{
		auto u=q.front();q.pop();
		if(vis.count(make_pair(u.x,u.y))) continue;
		if(a>b&&u.x-u.y>c-d) continue;
		if(a<b&&u.y-u.x>d-c) continue;
		vis[make_pair(u.x,u.y)]=1;
		if(u.x==c&&u.y==d)
		{
			op=u.ans;
			return 1;
		}
		if(inc(-INF,(__int128)2*u.y-u.x,INF))
			q.push(node{u.x,2*u.y-u.x,u.ans+'A'});
		if(inc(-INF,(__int128)2*u.x-u.y,INF))
			q.push(node{2*u.x-u.y,u.y,u.ans+'B'});
	}
	return 0;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d;
		if((a>b&&c<d)||(a<b&&c>d)||!bfs())
			cout<<"No\n";
		else{
			cout<<"Yes"<<'\n';
			cout<<op<<'\n';
		}
	}
}
