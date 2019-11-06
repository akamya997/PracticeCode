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
#define P pair<int,int>
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
const int maxn = 4e3 + 7;
const int MAXN_ = maxn;
struct edge{ int to,cap,cost,rev;};
int res,h[maxn],flow;
std::vector<edge> G[maxn];
int dist[MAXN_],prevv[MAXN_],preve[MAXN_]; // 前驱节点和对应边
inline void addedge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
} // 在vector 之中找到边的位置所在!
inline int read()
{
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9'){if(c=='-')flag=1;    c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?-x:x;
}
inline int min_cost_flow(int s,int t,int f)
{
	flow=0;
	res=0;
    fill(h+1,h+1+t,0);
    while(f > 0)
    {
        priority_queue<P,vector<P>, greater<P> > D;
        memset(dist,INF,sizeof dist);
        dist[s] = 0; D.push(P(0,s));
        while(!D.empty())
        {
            P now = D.top(); D.pop();
            if(dist[now.second] < now.first) continue;
            int v = now.second;
            for(int i=0;i<(int)G[v].size();++i)
            {
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])
                {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    D.push(P(dist[e.to],e.to));
                }
            }
        }
        // 无法增广 ， 就是找到了答案了！
        if(dist[t] == INF) break;
        for(int i=1;i<=t;++i) h[i] += dist[i];
        int d = f;
        for(int v = t; v != s; v = prevv[v])
            d = min(d,G[prevv[v]][preve[v]].cap);
        f -= d; flow += d;
        res += d * h[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
	return res;
}
int arr[maxn];
int n,k;
inline int getin(int x)
{
	return x;
}
inline int getout(int x)
{
	return x+n;
}
int main()
{
	int T;
	T=read();
	while(T--)
	{
		n=read();
		k=read();
		//scanf("%d%d",&n,&k);
		int s=2*n+1,S=s+1,t=S+1;
		for(int i=0;i<=t;i++) G[i].clear();
		addedge(S,s,k,0);
		for(int i=1;i<=n;i++)
		{
			arr[i]=read();
			//scanf("%d",&arr[i]);
			addedge(s,getin(i),1,0);
			addedge(getout(i),t,1,0);
			addedge(getin(i),getout(i),1,-arr[i]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(arr[i]<=arr[j])
					addedge(getout(i),getin(j),1,0);
			}
		}
		int f=0;
		printf("%d\n",-min_cost_flow(S,t,INF));
	}
}
