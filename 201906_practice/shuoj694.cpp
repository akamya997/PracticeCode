#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=37;
const int mod=998244353;
struct Mat{
	ll a[maxn][maxn];
	void init()
	{
		memset(a,0,sizeof(a));
	}
	void one()
	{
		init();
		for(int i=0;i<maxn;i++)
			a[i][i]=1;
	}
	Mat operator+(const Mat b)const{
		Mat ret;
		ret.init();
		for(int i=0;i<maxn;i++)
		{
			for(int j=0;j<maxn;j++)
				ret.a[i][j]=(a[i][j]+b.a[i][j])%mod;
		}
		return ret;
	}
	Mat operator-(const Mat b)const{
		Mat ret;
		ret.init();
		for(int i=0;i<maxn;i++)
		{
			for(int j=0;j<maxn;j++)
				ret.a[i][j]=(a[i][j]-b.a[i][j]+mod)%mod;
		}
		return ret;
	}
	Mat operator*(const Mat b)const{
		Mat ret;
		ret.init();
		for(int i=0;i<maxn;i++)
		{
			for(int j=0;j<maxn;j++)
			{
				for(int k=0;k<maxn;k++)
				{
					ret.a[i][j]=(ret.a[i][j]+a[i][k]*b.a[k][j]%mod)%mod;
				}
			}
		}
		return ret;
	}
};
template<typename T>
void fwt(Mat a[], int n, T f) {
    for (int d = 1; d < n; d *= 2)
        for (int i = 0, t = d * 2; i < n; i += t)
            for(int j=0;j<d;j++)
                f(a[i + j], a[i + j + d]);
}

void OR(Mat& a, Mat& b) { b = b + a; }
void rOR(Mat& a, Mat& b) { b = b - a; }
Mat base;
Mat dp[1<<9];
struct Trie
{
    int ch[maxn][26], f[maxn], val[maxn];
    int sz, rt;
    int newnode() { memset(ch[sz], -1, sizeof(ch[sz])), val[sz] = 0; return sz++; }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(char c) { return c - 'a'; };
    void insert(int cnt,const char* s)
    {
        int u = 0;
        for (int i = 0; s[i]; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u]=1<<cnt;
    }
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 26; c++)
        {
            if (~ch[rt][c])
				f[ch[rt][c]] = rt, q.push(ch[rt][c]);
            else
                ch[rt][c] = rt;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            val[u] |= val[f[u]];
            for (int c = 0; c < 26; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
		for(int i=0;i<sz;i++)
		{
			for(int c=0;c<26;c++)
			{
				dp[val[ch[i][c]]].a[i][ch[i][c]]++;
			}
		}
    }
};
int l,n;
void mul(Mat a[],Mat b[])
{
	fwt(a,1<<n,OR);
	fwt(b,1<<n,OR);
	for(int i=0;i<(1<<n);i++)
		a[i]=a[i]*b[i];
	fwt(a,1<<n,rOR);
	fwt(b,1<<n,rOR);
}
ll solve()
{
	l--;
	if(l<0) return 0;
	Mat ret[1<<7];
	for(int i=0;i<(1<<n);i++) ret[i]=dp[i];
	while(l)
	{
		if(l&1) mul(ret,dp);
		mul(dp,dp);
		l>>=1;
	}
	ll res=0;
	for(int i=0;i<maxn;i++)
		res=(res+ret[(1<<n)-1].a[0][i])%mod;
	return res;
}
int main()
{
	Trie ac;
	ac.init();
	scanf("%d%d",&l,&n);
	char s[20];
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		ac.insert(i,s);
	}
	ac.build();
	ll ans=solve();
	printf("%lld\n",ans);
}
