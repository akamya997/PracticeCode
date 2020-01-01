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
double dp[1<<15][15];
inline double dis(int x1,int x2,int y1,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
vc<pi> all;
int n;
double dfs(int st,int cur)
{
	if(st==(1<<(n+1))-1)  return 0;
	double & ret=dp[st][cur];
	if(ret>=0) return ret;
	ret=INF;
	for(int i=1;i<=n;i++)
	{
		if(st&(1<<i)) continue;
		double cd=dis(all[cur].first,all[i].first,all[cur].second,all[i].second);
		ret=min(ret,dfs(st|(1<<i),i)+cd);
	}
	return ret;
}
int main()
{
	while(~scanf("%d",&n))
	{
		all.clear();
		memset(dp,-1,sizeof(dp));
		all.emplace_back(0,0);
		for(int i=0,x,y;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			all.emplace_back(x,y);
		}
		printf("%.2f\n",dfs(1,0));
	}

}
