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
struct node{
	int x,y,k,t;
}all[15];
int n,m;
ll exgcd(ll a, ll b, ll &x, ll &y) //返回gcd(a,b)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= x * (a / b);
    return d;
}
inline ll CRT(ll *m, ll *r, ll n,ll &k)
{
    if (!n)
        return 0;
    ll M = m[0], R = r[0], x, y, d;
    for (int i = 1; i < n; i++)
    {
        d = exgcd(M, m[i], x, y);
        if ((r[i] - R) % d)
            return -1;
        x = (r[i] - R) / d * x % (m[i] / d);
        R += x * M;
        M = M / d * m[i];
        R %= M;
    }
	k=M;
    return R >= 0 ? R : R + M;
}

ll dfs(int pos,int xe,int modx,int ye,int mody,int lx,int rx,int ly,int ry)
{
	if(rx<lx||ry<ly) return 0;
	if(pos==n)
	{
		ll xx=(modx+rx-xe)/modx-((lx-1)-xe+modx)/modx;
		ll yy=(mody+ry-ye)/mody-((ly-1)-ye+mody)/mody;
		return xx*yy;
	}
	ll ans=0;
	node &a=all[pos];
	for(int i=0;i<a.k;i++)
	{
		int rev=a.t-i;
		ll m[2],r[2];
		ll Mx,My;
		m[0]=modx,r[0]=xe;
		m[1]=a.k,r[1]=(i+a.x)%a.k;
		int rxe=CRT(m,r,2,Mx);
		m[0]=mody,r[0]=ye;
		m[1]=a.k,r[1]=(rev+a.y)%a.k;
		int rye=CRT(m,r,2,My);
		if(rxe!=-1&&rye!=-1)
			ans+=dfs(pos+1,rxe,Mx,rye,My,max(lx,a.x+1),rx,max(ly,a.y+1),ry);
		m[0]=modx,r[0]=xe;
		m[1]=a.k,r[1]=(a.x-i+a.k)%a.k;
		rxe=CRT(m,r,2,Mx);
		m[0]=mody,r[0]=ye;
		m[1]=a.k,r[1]=(rev+a.y)%a.k;
		rye=CRT(m,r,2,My);
		if(rxe!=-1&&rye!=-1)
			ans+=dfs(pos+1,rxe,Mx,rye,My,lx,min(rx,a.x),max(ly,a.y+1),ry);
		m[0]=modx,r[0]=xe;
		m[1]=a.k,r[1]=(i+a.x)%a.k;
		rxe=CRT(m,r,2,Mx);
		m[0]=mody,r[0]=ye;
		m[1]=a.k,r[1]=(a.y-rev+a.k)%a.k;
		rye=CRT(m,r,2,My);
		if(rxe!=-1&&rye!=-1)
			ans+=dfs(pos+1,rxe,Mx,rye,My,max(a.x+1,lx),rx,ly,min(ry,a.y));
		m[0]=modx,r[0]=xe;
		m[1]=a.k,r[1]=(a.x-i+a.k)%a.k;
		rxe=CRT(m,r,2,Mx);
		m[0]=mody,r[0]=ye;
		m[1]=a.k,r[1]=(a.y-rev+a.k)%a.k;
		rye=CRT(m,r,2,My);
		if(rxe!=-1&&rye!=-1)
			ans+=dfs(pos+1,rxe,Mx,rye,My,lx,min(rx,a.x),ly,min(ry,a.y));
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d%d%d%d",&all[i].x,&all[i].y,&all[i].k,&all[i].t);
		ll ans=0;
		node &a=all[0];
		for(int i=0;i<a.k;i++)
		{
			int rev=a.t-i;
			ans+=dfs(1,(i+a.x)%a.k,a.k,(a.y+rev)%a.k,a.k,a.x+1,m,a.y+1,m);
			ans+=dfs(1,(a.x-i+a.k)%a.k,a.k,(a.y+rev)%a.k,a.k,0,a.x,a.y+1,m);
			ans+=dfs(1,(i+a.x)%a.k,a.k,(a.y-rev+a.k)%a.k,a.k,a.x+1,m,0,a.y);
			ans+=dfs(1,(a.x-i+a.k)%a.k,a.k,(a.y-rev+a.k)%a.k,a.k,0,a.x,0,a.y);
		}
		printf("%lld\n",ans);
	}
}
