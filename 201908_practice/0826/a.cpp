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
const int maxn=2e5+7;
vector<int> G[maxn];
int fa[maxn], dep[maxn], maxson[maxn], son[maxn]; //dfs数组
int top[maxn], dfn[maxn], tot;                    //link数组
int dfs(int u)
{
    int ret = 0;
    for (auto &v:G[u])
    {
        if (v == fa[u])
            continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        int sz = dfs(v);
        ret += sz;
        if (sz > maxson[u])
        {
            maxson[u] = sz;
            son[u] = v;
        }
    }
    return ret + 1;
}
void link(int u, int t)
{
    dfn[u] = ++tot;
    top[u] = t;
    if (son[u])
        link(son[u], t);
    for (auto& v:G[u])
    {
        if (v == fa[u] || v == son[u])
            continue;
        link(v, v);
    }
}
void hld()
{
    dfs(1);
    link(1, 1);
}
struct Seg{
	int l,r,c;
	bool operator<(const Seg& a)const{
		return r<a.r;
	}
};
set<Seg> st;
void split(int p)
{
	if(p==1) return;
	auto it=st.lower_bound({p,p});
	assert(it!=st.end());
	if(p==it->r) return;
	int L=it->l,R=it->r,C=it->c;
	st.erase(it);st.insert({L,p,C});st.insert({p+1,R,C});
}
int cnt[maxn];
int ans[maxn];
void update(int L,int R,int C)
{
	if(L>R) return;
	split(L-1);split(R);
	while(true)
	{
		auto it=st.lower_bound({L,L});
		if(it==st.end()||(it->l)>R) break;
		if(it->c)
		{
			--ans[cnt[it->c]];
			cnt[it->c]-= it->r -it->l +1;
			++ans[cnt[it->c]];
		}
		st.erase(it);
	}
	--ans[cnt[C]];
	cnt[C]+=R-L+1;
	++ans[cnt[C]];
	st.insert({L,R,C});
}
void solve(int u,int c)
{
	while(u>1)
	{
		int L=max(dfn[top[u]],2),R=dfn[u];
		update(L,R,c);
		u=fa[top[u]];
	}
}
int main()
{
	int n,c,q;
	scanf("%d%d%d",&n,&c,&q);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	hld();
	ans[0]=c;
	st.insert({2,n,0});
	while(q--)
	{
		int u,col,m;
		scanf("%d%d%d",&u,&col,&m);
		solve(u,col);
		printf("%d\n",ans[m]);
	}
}
