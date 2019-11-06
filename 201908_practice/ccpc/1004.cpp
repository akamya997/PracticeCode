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
const int maxn=5e4+7;
struct Edge{
	int to,w;
};
vector<Edge> G[maxn];
struct node{
	ll dis;int id;
	bool operator<(const node &a)const{
		return dis<a.dis;
	}
};
int query[maxn];
ll ans[maxn];
int main()
{
	int t;
	reads(t);
	while(t--)
	{
		int var=0;
		int n,m,qq;
		reads(n);reads(m);reads(qq);
		for(int i=0;i<=n;i++) G[i].clear();
		static multiset<node> q;
		q.clear();
		int cur=0;
		for(int i=0,u,v,w;i<m;i++)
		{
			reads(u);reads(v);reads(w);
			G[u].push_back(Edge{v,w});
			q.insert(node{w,v});
		}
		for(int i=1;i<=qq;i++) 
		{
			reads(query[i]);var=max(query[i],var);
		}
		while(q.size())
		{
			while(q.size()>var-cur+1) q.erase(--q.end());
			node u=*q.begin();
			q.erase(q.begin());
			if(u.dis!=0)
				ans[cur++]=u.dis;
			if(cur==var) break;
			ll mx=0;
			if(q.size())
				mx=(*(--q.end())).dis;
			for(auto &e:G[u.id])
			{
				if(q.size()+cur>var&&u.dis+e.w>=mx) continue;
				q.insert(node{u.dis+e.w,e.to});
				mx=max(mx,1LL*u.dis+e.w);
			}
		}
		for(int i=1;i<=qq;i++) printf("%lld\n",ans[query[i]-1]);
	}
}
