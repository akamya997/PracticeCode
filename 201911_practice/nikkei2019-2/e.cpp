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

struct Tri{
	int a,b,c;
};
vc<Tri> ans;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	set<int> can;
	for(int i=k;i<=k+3*n-1;i++) can.insert(i);
	for(int i=1;i<=n;i++)
	{
		int fi=*can.begin(),ed=*can.rbegin();
		can.erase(fi);
		can.erase(ed);
		auto it=can.upper_bound(ed-fi);
		if(it==can.begin())
		{
			puts("-1");
			return 0;
		}
		it--;
		ans.push_back({fi,*it,ed});
		can.erase(it);
	}
	for(auto u:ans) printf("%d %d %d\n",u.a,u.b,u.c);
}
