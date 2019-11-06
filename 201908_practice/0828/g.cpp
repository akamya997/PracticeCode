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
const ll INF=0x3f3f3f3f3f3f3f3f;
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
struct Edge{
	int to,w;
};
#define reads(n) FastIO::read(n)
namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], obuf[SIZE], str[60];
    int bi = SIZE, bn = SIZE, opt;
    int read(char *s) {
        while (bn) {
            for (; bi < bn && buf[bi] <= ' '; bi++);
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        int sn = 0;
        while (bn) {
            for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        s[sn] = 0;
        return sn;
    }
    template<typename T>
    bool read(T& x) {
        int n = read(str), bf;
        if (!n) return 0;
        int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
        for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
        if (bf < 0) x = -x;
        return 1;
    }
};
vector<Edge> G[maxn];
vector<ll> dp[maxn];
ll ans;
int n,k;
inline vector<ll> Merge(const vector<ll>& a,const vector<ll>& b,const ll w)
{
	vector<ll> ret(min((int)(a.size()+b.size()-1),k+1),INF);
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<b.size();j++)
		{
			if(i+j<=k)
			{
				ret[i+j]=min(ret[i+j],a[i]+b[j]+w*j*(k-j));
			}
		}
	}
	return ret;
}
void dfs(int u,int fa=-1)
{
	dp[u]={0};
	if(G[u].size()==1)
	{
		dp[u].push_back(0);
		return;
	}
	for(auto& e:G[u])
	{
		if(e.to==fa) continue;
		int v=e.to;
		dfs(v,u);
		dp[u]=Merge(dp[u],dp[v],e.w);
	}
	if(dp[u].size()==k+1)
		ans=min(ans,dp[u][k]);
}
int main()
{
	int T;
	int kas=0;
	scanf("%d",&T);
	while(T--)
	{
		ans=INF;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) 
			G[i].clear();
		int val=0;
		for(int i=1,u,v,w;i<n;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			val=w;
			G[u].push_back({v,w});
			G[v].push_back({u,w});
		}
		int rt=-1;
		for(int i=1;i<=n;i++)
		{
			if(G[i].size()!=1)
			{
				rt=i;
				break;
			}
		}
		printf("Case #%d: ",++kas);
		if(rt==-1)
		{
			if(k==1)
				printf("%d\n",0);
			else printf("%d\n",val);
			continue;
		}
		dfs(rt);
		printf("%lld\n",ans);
	}
}
