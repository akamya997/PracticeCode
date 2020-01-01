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
const int maxn=105;
bool op[maxn];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(op,0,sizeof(op));
		int n;
		cin>>n;
		vi a(n);
		vi pos(n+1);
		for(int i=0;i<n;i++) 
		{
			cin>>a[i];
			pos[a[i]]=i;
		}
		for(int i=1;i<=n;i++)
		{
			while(pos[i]!=0)
			{
				if(op[pos[i]-1]) break;
				else{
					int tar=a[pos[i]-1];
					if(tar<i) break;
					op[pos[i]-1]=1;
					pos[tar]=pos[i];
					swap(a[pos[i]],a[pos[i]-1]);
					pos[i]=pos[i]-1;
				}
			}
	//		for(int i=0;i<n;i++) dbg(a[i]);
		}
		for(int i=0;i<n;i++) cout<<a[i]<<" ";
		cout<<'\n';

	}
}
