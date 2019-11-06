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
const int mod=1e9+7;
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
const int maxn=2e5+7;
struct Edge{
	int u,v;
}e[maxn];
int val[maxn];
int state[maxn];
int block[maxn];
int ry[500][maxn/2];
bool lz[maxn];
int main()
{
	mt19937 rnd(time(NULL));
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int var=sqrt(m);
		for(int i=0;i<=n;i++)
			state[i]=0;
		for(int i=1/var;i<=m/var;i++)
			for(int j=0;j<=n;j++)
				ry[i][j]=0;
		for(int i=1;i<=n;i++) 
			val[i]=rnd();
		for(int i=1;i<=m;i++)
		{
			lz[i]=0;
			block[i]=i/var;
			scanf("%d%d",&e[i].u,&e[i].v);
			state[e[i].u]^=val[e[i].v];
			state[e[i].v]^=val[e[i].u];
			ry[block[i]][e[i].u]^=val[e[i].v];
			ry[block[i]][e[i].v]^=val[e[i].u];
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int op,u,v;
			scanf("%d%d%d",&op,&u,&v);
			if(op==1)
			{
				if(block[u]==block[v])
				{
					for(int i=u;i<=v;i++)
					{
						state[e[i].u]^=val[e[i].v];
						state[e[i].v]^=val[e[i].u];
					}
				}
				else{
					for(int i=block[u]+1;i<=block[v]-1;i++)
						lz[i]^=1;
					for(int i=u;block[i]==block[u];i++)
					{
						state[e[i].u]^=val[e[i].v];
						state[e[i].v]^=val[e[i].u];
					}
					for(int i=v;block[i]==block[v];i--)
					{
						state[e[i].u]^=val[e[i].v];
						state[e[i].v]^=val[e[i].u];
					}
				}
			}
			else{
				int ansu=state[u],ansv=state[v];
				for(int i=1/var;i<=m/var;i++)
				{
					if(lz[i]) ansu^=ry[i][u],ansv^=ry[i][v];
				}
				printf("%d",ansu==ansv);
			}
		}
		puts("");
	}
}

