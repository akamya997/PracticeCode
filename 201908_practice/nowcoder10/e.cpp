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
const int maxn=1e6+7;
struct node{
	int x,y,val;
	bool operator<(const node& a)const{
		return val<a.val;
	}
}p[maxn];
void rot(int n, int *x, int *y, int rx, int ry) {
    if (ry == 0) {
        if (rx == 1) {
            *x = n-1 - *x;
            *y = n-1 - *y;
        }
        //Swap x and y
        int t  = *x;
        *x = *y;
        *y = t;
    }
}
int xy2d (int n, int x, int y) {
    int rx, ry, s, d=0;
    for (s=n/2; s>0; s/=2) {
        rx = (x & s) > 0;
        ry = (y & s) > 0;
        d += s * s * ((3 * rx) ^ ry);
        rot(n, &x, &y, rx, ry);
    }
    return d;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	ll cnt=1;
	for(int i=0;i<k;i++) cnt=cnt*2;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].val=xy2d(cnt,p[i].y-1,p[i].x-1);
	}
	sort(p,p+n);
	for(int i=0;i<n;i++)
		printf("%d %d\n",p[i].x,p[i].y);
}
