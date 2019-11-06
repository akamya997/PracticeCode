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
    bool read(int& x) {
        int n = read(str), bf;
        if (!n) return 0;
        int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
        for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
        if (bf < 0) x = -x;
        return 1;
    }
};
const int maxn=1e5+7;
int arr[maxn],brr[maxn];
int main()
{
	int T;
	reads(T);
	while(T--)
	{
		int n,m;
		reads(n);reads(m);
		for(int i=1;i<=n;i++)
			reads(arr[i]);
		while(m--)
		{
			int op,l,r;
			reads(op);reads(l);reads(r);
			if(!op)
				arr[l]=r;
			else{
				bool ok=1;
				int T=10;
				while(T--)
				{
					int a,b,c,len=r-l+1;
					a=rand()%len;
					b=rand()%len;
					c=rand()%len;
					while(b==a)
						b=rand()%len;
					while(c==b||c==a)
						c=rand()%len;
					int aa=min({a,b,c})+l;
					int cc=max({a,b,c})+l;
					a=INF;
					int bb=min({a,b,c})+l;
					aa=arr[aa];
					bb=arr[bb];
					cc=arr[cc];
					if(aa+bb<=cc)
					{
						ok=0;break;
					}
				}
				if(!ok)
				{
					puts("llsml!");
					continue;
				}
				int mi1=INF,mi2=INF,mx=0;
				int cur=0;
				for(int i=l;i<=r;i++)
					brr[cur++]=arr[i];
				sort(brr,brr+cur);
				mi1=brr[0];mi2=brr[1];mx=brr[cur-1];
				if(mi1+mi2>mx) puts("llsnb!");
				else puts("llsml!");
			}
		}

	}
}
