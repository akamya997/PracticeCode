#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int INF=0x3f3f3f3f;
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
const int maxn=1e5+7;
struct Coin{
	int a,b;
}coin[maxn];
bool vis[maxn][2][2];
struct node{
	int id,cnt;
	bool operator<(const node&a)const{
		return cnt>a.cnt;
	}
};
int ans[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			ans[i]=ans[i+n]=0;
			scanf("%d%d",&coin[i].a,&coin[i].b);
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					vis[i][j][k]=0;
		}
		priority_queue<node> q[2][2];
		for(int i=0;i<n;i++)
		{
			q[0][0].push(node{i,coin[i].a});
			q[1][0].push(node{i,coin[i].a});
			q[0][1].push(node{i,coin[i].a+coin[i].b});
			q[1][1].push(node{i,coin[i].a+coin[i].b});
		}
		int cur=0;
		int a[2]={0,0};
		a[0]+=q[0][0].top().cnt;
		vis[q[0][0].top().id][0][0]=1;
		q[0][0].pop();
		ans[1]=a[0];
		for(int i=2;i<=2*n;i++)
		{
			int fromp=ans[cur],frompp=ans[cur^1];
			if(frompp>fromp) cur^=1;       

		}
		for(int i=1;i<=2*n;i++)
			printf("%d%c",ans[i],i==2*n?'\n':' ');
	}
}
