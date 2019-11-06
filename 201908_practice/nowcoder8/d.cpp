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
const int inf=0x3f3f3f3f;
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
int n,root,ans,cur;
struct P
{
    int d[3],mx[3],mn[3],lch,rch;
    int& operator[](int x) {return d[x];}
    //friend bool operator<(P x,P y) {return x[cur]<y[cur];}
    inline friend int dis(P x,P y) {return fabs(x[0]-y[0])+fabs(x[1]-y[1])+fabs(x[2]-y[2]);}
}p[maxn];


struct kdtree
{
    P t[maxn],T;
    int ans;
    void update(int k)
    {
        int l=t[k].lch,r=t[k].rch;
        for (int i=0;i<3;i++)
        {
            t[k].mn[i]=t[k].mx[i]=t[k][i];
            if (l) t[k].mn[i]=min(t[k].mn[i],t[l].mn[i]);
            if (r) t[k].mn[i]=min(t[k].mn[i],t[r].mn[i]);
            if (l) t[k].mx[i]=max(t[k].mx[i],t[l].mx[i]);
            if (r) t[k].mx[i]=max(t[k].mx[i],t[r].mx[i]);
        }
    }
    inline int getmn(P x)
    {
        int tmp=0;
        for (int i=0;i<3;i++)
        {
            tmp+=max(T[i]-x.mx[i],0);
            tmp+=max(x.mn[i]-T[i],0);
        }
        return tmp;
    }
    inline void querymn(int k)
    {
        ans=min(ans,dis(t[k],T));
        int l=t[k].lch,r=t[k].rch,dl=inf,dr=inf;
        if (l) dl=getmn(t[l]);
        if (r) dr=getmn(t[r]);
        if (dl<dr)
        {
            if (dl<ans) querymn(l);
            if (dr<ans) querymn(r);
        }
        else
        {
            if (dr<ans) querymn(r);
            if (dl<ans) querymn(l);
        }
    }
    void insert(int k,int now)
    {
		now%=3;
        if (T[now]>=t[k][now])
        {
            if (t[k].rch) insert(t[k].rch,now+1);
            else
            {
                t[k].rch=++n;t[n]=T;
                for (int i=0;i<2;i++) t[n].mx[i]=t[n].mn[i]=t[n][i];
            }
        }
        else
        {
            if (t[k].lch) insert(t[k].lch,now+1);
            else
            {
                t[k].lch=++n;t[n]=T;
                for (int i=0;i<2;i++) t[n].mx[i]=t[n].mn[i]=t[n][i];
            }
        }
        update(k);
    }
    inline int query(int x,int y,int z)
    {
        ans=inf;
        T[0]=x;T[1]=y;T[2]=z;T.lch=0;T.rch=0;
        querymn(root);
        return ans;
    }
    inline void insert1(int x,int y,int z)
    {
        T[0]=x;T[1]=y;T[2]=z;T.lch=0;T.rch=0;insert(root,0);
    }
}kdtree;
int main()
{
	int n,m,h,q;
	reads(n);reads(m);reads(h);reads(q);
	while(q--)
	{
		int op,x,y,z;
		reads(op);reads(x);reads(y);reads(z);
		if(op==1)
			kdtree.insert1(x,y,z);
		else{
			printf("%d\n",kdtree.query(x,y,z));
		}
	}
}
