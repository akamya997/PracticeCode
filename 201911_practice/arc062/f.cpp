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
const int maxn=507;
const int mod=1e9+7;
vi G[maxn];
int dfn[maxn], low[maxn];
int n, m;
int ti, scc; //时间戳与联通分量计数
set<int> nG[maxn];
stack<int> st;
void dfs(int u, int fa)
{
    dfn[u] = low[u] = ++ti;
    for (auto v:G[u])
    {
        if (v == fa)
            continue;
        if (!dfn[v])
        {
    		st.push(v);
            dfs(v, u);
            low[u] = min(low[u], low[v]);
			if(low[v]>=dfn[u])
			{
				scc++;
				while(1)
				{
					int t=st.top();
					st.pop();
					nG[scc].insert(t);
					if(t==v) break;
				}
				nG[scc].insert(u);
			}
        }
        else low[u] = min(low[u], dfn[v]);
    }
}
void DCC()
{
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
        {
			dfs(i, -1);
			st.push(i);
		}
}
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
ll fac[maxn];
int cnt[maxn];
ll C(int n,int m)
{
	return fac[n]*inv(fac[m])%mod*inv(fac[n-m])%mod;
}
struct Edge{
	int u,v;
}edges[maxn];
int k;
int fa[maxn];
void init()
{
	for(int i=0;i<=n;i++) fa[i]=i;
}
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	fa[y]=x;
}
bool solve(int x)
{
	init();
	int cc=0;
	for(auto u:nG[x])
	{
		for(auto v:G[u])
		{
			if(nG[x].count(v)&&v<u)
			{
				cnt[x]++;
				if(Find(u)==Find(v)) cc++;
				else Union(u,v);
			}
		}
	}
	return cc<=1;
}
int main()
{
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
	cin>>n>>m>>k;
	for(int i=0,u,v;i<m;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		edges[i]={u,v};
	}
	DCC();
	//for(int i=1;i<=n;i++) dbg(i,bel[i]);
	ll ans=1;
	for(int i=1;i<=scc;i++)
	{
		//dbg(nG[i]);
		int tp=solve(i);
		if(tp==1)
		{
			ll tmp=0;
			for(int j=0;j<cnt[i];j++)
			{
				int g=__gcd(j,cnt[i]);
				tmp=(quick(k,g)+tmp)%mod;
			}
			tmp=tmp*inv(cnt[i])%mod;
			ans=(ans*tmp)%mod;
		}
		else{
			ans=ans*C(cnt[i]+k-1,k-1)%mod;
		}
		//dbg(ans);
	}
	cout<<ans<<endl;
}
