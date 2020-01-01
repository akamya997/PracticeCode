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
const int maxn=11;
int ans[1<<maxn][1<<maxn];
void getans(int x,int y,int c)
{
	if(!c)
	{
		ans[x][y]=1;
		return;
	}
	getans(x,y,c-1);
	int len=(1<<(c-1));
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
		{
			ans[i][j+len]=ans[i][j];
			ans[i+len][j+len]=ans[i][j];
			ans[i+len][j]=(ans[i][j]^1);
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		n--;
		getans(0,0,n);
		for(int i=0;i<(1<<n);i++)
		{
			for(int j=0;j<(1<<n);j++)
			{
				cout<<ans[i][j];
				if(j!=(1<<n)-1) cout<<" ";
			}
			cout<<'\n';
		}
	}
}
