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
    inline bool read(ll& x) {
        int n = read(str), bf;
        if (!n) return 0;
        int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
        for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
        if (bf < 0) x = -x;
        return 1;
    }
};
const int INF=0x3f3f3f3f;
inline ll quick(ll a,ll b,ll mod)
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
inline ll inv(ll a,ll mod){return quick(a,mod-2,mod);}
const int maxn=2e6+7;
struct Hash{
	const static int magic=524287;
	int head[magic+1],cnt;
	struct edge{
		int key,val,nxt;
	}edge[maxn];
	void init()
	{
		memset(head,-1,sizeof(head));
		cnt=0;
	}
	void Insert(int key,int val)
	{
		int v=key&magic;
		edge[cnt]={key,val,head[v]};
		head[v]=cnt++;
	}
	int query(int key)
	{
		int v=key&magic;
		for(int i=head[v];~i;i=edge[i].nxt)
			if(edge[i].key==key) return edge[i].val;
		return -1;
	}
}mp;
int main()
{
    ll T;
	reads(T);
    while(T--)
    {
		mp.init();
        ll n,x0,a,b,p;
		reads(n);reads(x0);reads(a);reads(b);reads(p);
        ll q;
		reads(q);
        int var=min((ll)sqrt(p*q),n);
        if(a==0)
        {
            while(q--)
            {
                ll v;
				reads(v);
                if(v==x0) cout<<"0\n";
                else if(v==b) cout<<"1\n";
                else cout<<"-1\n";
            }
            continue;
        }
        ll val=x0;
        for(int i=0;i<var;i++)
        {
			if(mp.query(val)==-1)
				mp.Insert(val,i);
            val=(val*a+b)%p;
        }
        ll inva=inv(a,p);
        ll invb=(p-b)*inva%p;
        ll A=1,B=0;
        for(int i=0;i<var;i++)
        {
            A=A*inva%p;
            B=(B*inva+invb)%p;
        }
        int up=p/var;
        while(q--)
        {
            ll v;
			reads(v);
            ll ans=-1;
            for(int i=0;i<=up;i++)
            {
				int tar=mp.query(v);
                if(tar!=-1)
                {
                    ans=i*var+tar;
                    break;
                }
                v=(A*v+B)%p;
            }
            if(ans>=n||ans==-1) cout<<"-1\n";
            else cout<<ans<<'\n';
        }
    }
}

