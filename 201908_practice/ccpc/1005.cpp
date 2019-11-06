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
int n,m;
int lson[maxn<<7],rson[maxn<<7];
int rt[maxn],tot,cnt[maxn<<7];
inline void pushup(int o)
{
	cnt[o]=cnt[lson[o]]+cnt[rson[o]];
}
#define Lson lson[o],L,mid
#define Rson rson[o],mid+1,R
void update(int p,int val,int& o,int L=1,int R=n)
{
	if(!o)
	{
		o=++tot;
		cnt[o]=0;
		lson[o]=0;
		rson[o]=0;
	}
	if(L==R) 
	{
		cnt[o]+=val;
		return;
	}
	int mid=L+R>>1;
	if(p<=mid) update(p,val,Lson);
	else update(p,val,Rson);
	pushup(o);
}
int sgtquery(int l,int r,int o,int L=1,int R=n)
{
	if(!o) return 0;
	if(l<=L&&r>=R)
		return cnt[o];
	int mid=L+R>>1;
	int ret=0;
	if(l<=mid) ret+=sgtquery(l,r,Lson);
	if(r>mid) ret+=sgtquery(l,r,Rson);
	return ret;
}
bool vis[maxn];
inline void add(int x,int val,int flag)
{
	while(x<=n)
	{
		update(val,flag,rt[x]);
		x+=x&-x;
	}
}
inline int query(int x,int l,int k)//[l,k]
{
	int ret=0;
	while(x>0)
	{
		ret+=sgtquery(l,k,rt[x]);
		x-=x&-x;
	}
	return ret;
}
inline void init()
{
	tot=0;
	for(int i=0;i<=n;i++)
	{
		vis[i]=0;
		rt[i]=0;
	}
}
int arr[maxn];
int main()
{
	int T;
	reads(T);
	while(T--)
	{
		int lastans=0;
		reads(n);reads(m);
		init();
		for(int i=1,tmp;i<=n;i++)
		{
			reads(tmp);
			arr[i]=tmp;
			add(i,tmp,1);
		}
		while(m--)
		{
			int op;
			reads(op);
			if(op==1)
			{
				int t1;
				reads(t1);
				int pos=(t1^lastans);
				if(!vis[pos])
				{
					vis[pos]=1;
					add(pos,arr[pos],-1);
				}
			}
			else{
				int t2,t3;
				reads(t2);reads(t3);
				int r=(t2^lastans),k=(t3^lastans);
				int ans=n+1,L=k,R=n;
				while(L<=R)
				{
					int mid=L+R>>1;
					int len=mid-k+1;
					int cnt=query(r,k,mid);
					if(cnt>=len) L=mid+1;
					else R=mid-1,ans=mid;
				}
				lastans=ans;
				printf("%d\n",ans);
			}
		}
	}
}
