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
int a[maxn];
int b[maxn][205];
struct item{
	int id,val;
	bool operator<(const item& a)const{
		if(a.val==val) return a.id>id;
		return a.val<val;
	}
};
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
	set<item> cur[205];
	ll ans=0;
	int lpos=1;
	for(int i=1;i<=n;i++)
	{
		ll curans=-pre[i]+pre[lpos];
		for(int j=1;j<=m;j++)
		{
			cur[j].insert(item{i,b[i][j]});
			curans+=(*cur[j].begin()).val;
		}
		ll gain;
		do{
			gain=a[lpos];
			for(int j=1;j<=m;j++)
			{
	//			dbg(j,(*cur[j].begin()).id,(*cur[j].begin()).val);
				if((*cur[j].begin()).id==lpos)
				{
					gain-=(*cur[j].begin()).val;
					if(cur[j].size()>1)
					{
						auto it=cur[j].begin();
						it++;
						gain+=(*it).val;
					}
				}
			}
			if(gain>0)
			{
				curans+=gain;
				for(int j=1;j<=m;j++) cur[j].erase(item{lpos,b[lpos][j]});
				lpos++;
			}
		}while(gain>0&&lpos<i);
	//	dbg(i,curans,lpos);
		ans=max(ans,curans);
	}
	cout<<ans<<endl;
}
