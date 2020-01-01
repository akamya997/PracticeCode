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
const int maxn=1e3+7;
int a[maxn];
int sg[maxn];int n,m;
int dfs(int x)
{
	if(sg[x]!=-1) return sg[x];
	sg[x]=0;
	for(int i=1;i<=m;i++)
	{
		if(a[i]<=x)
		{
			if(!dfs(x-a[i]))
			{
				sg[x]=1;
				break;
			}
		}
	}
	return sg[x];
}
int main()
{
	memset(sg,-1,sizeof(sg));
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i];
	if(dfs(n)) cout<<"Y\n";
	else cout<<"N\n";
}
