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
const int maxn=5e3+7;
ll val[maxn][maxn];
int b[maxn][205];
int a[maxn];
int st[maxn],ed[maxn];
inline void add(int v,int x1,int y1,int x2,int y2)
{
	val[x1][y1]+=v;
	val[x1][y2+1]-=v;
	val[x2+1][y1]-=v;
	val[x2+1][y2+1]+=v;
}
ll dp[2][maxn];
ll pre[maxn];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n;i++) 
	{
		cin>>a[i];
		pre[i+1]=pre[i]+a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>b[i][j];
	for(int j=1;j<=m;j++)
	{
		stack<int> s;
		for(int i=1;i<=n;i++)
		{
			while(!s.empty()&&b[s.top()][j]<b[i][j])
			{
				ed[s.top()]=i-1;
				s.pop();
			}
			if(s.empty()) st[i]=1;
			else st[i]=s.top()+1;
			s.push(i);
		}
		while(!s.empty())
		{
			ed[s.top()]=n;
			s.pop();
		}
		for(int i=1;i<=n;i++)
			add(b[i][j],st[i],i,i,ed[i]);
	}
	ll ans=0;
	int cc=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[cc][j]=-dp[cc^1][j-1]+val[i][j]+dp[cc^1][j]+dp[cc][j-1];
			if(i<=j) ans=max(ans,dp[cc][j]-(pre[j]-pre[i]));
		}
		cc^=1;
	}
	cout<<ans<<endl;
}
