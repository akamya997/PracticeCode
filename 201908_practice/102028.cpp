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
int s[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn], rk[maxn], height[maxn];
//sa[],height[]下标从1开始，rk[]下标从0开始
void getsa(int m, int n)
{ //n为字符串的长度,字符集的值为0~m-1
    n++;
    int *x = t, *y = t2;
    //基数排序
    for (int i = 0; i < m; i++)
		c[i] = 0;
    for (int i = 0; i < n; i++)
		c[x[i] = s[i]]++;
    for (int i = 1; i < m; i++)
		c[i] += c[i - 1];
    for (int i = n - 1; ~i; i--)
		sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1)
    { //直接利用sa数组排序第二关键字
        int p = 0;
        for (int i = n - k; i < n; i++)
			y[p++] = i;
        for (int i = 0; i < n; i++)
            if (sa[i] >= k)
				y[p++] = sa[i] - k;
        //基数排序第一关键字
        for (int i = 0; i < m; i++)
			c[i] = 0;
        for (int i = 0; i < n; i++)
			c[x[y[i]]]++;
        for (int i = 1; i < m; i++)
			c[i] += c[i - 1];
        for (int i = n - 1; ~i; i--)
			sa[--c[x[y[i]]]] = y[i];
        //根据sa和y数组计算新的x数组
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
			break; //以后即使继续倍增，sa也不会改变，推出
        m = p;             //下次基数排序的最大值
    }
    n--;
    int k = 0;
    for (int i = 0; i <= n; i++)
		rk[sa[i]] = i;
    for (int i = 0; i < n; i++)
    {
        if (k) k--;
        int j = sa[rk[i] - 1];
        while (s[i + k] == s[j + k])
			k++;
        height[rk[i]] = k;
    }
}

int st[maxn];
int sss[maxn],ttt[maxn];
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
vector<int> Query[maxn];
int n;
ll sum[maxn<<2];
ll lz[maxn<<2];
void build(int L=0,int R=n-1,int o=1)
{
	lz[o]=sum[o]=0;
	if(L==R) return;
	int mid=L+R>>1;
	build(Lson);
	build(Rson);
}
inline void pushup(int o)
{
	sum[o]=sum[lson]+sum[rson];
}
inline void pushdown(int o,int len)
{
	if(lz[o])
	{
		lz[lson]=lz[o];
		lz[rson]=lz[o];
		sum[lson]=lz[o]*(len-len/2);
		sum[rson]=lz[o]*(len/2);
		lz[o]=0;
	}
}
void update(int l,int r,int val,int L=0,int R=n-1,int o=1)
{
	if(l<=L&&r>=R)
	{
		sum[o]=1LL*val*(R-L+1);
		lz[o]=val;
		return;
	}
	int mid=L+R>>1;
	pushdown(o,R-L+1);
	if(l<=mid)
		update(l,r,val,Lson);
	if(r>mid)
		update(l,r,val,Rson);
	pushup(o);
}
ll query(int l,int r,int L=0,int R=n-1,int o=1)
{
	if(l<=L&&r>=R)
		return sum[o];
	pushdown(o,R-L+1);
	int mid=L+R>>1;
	ll ret=0;
	if(l<=mid) ret+=query(l,r,Lson);
	if(r>mid) ret+=query(l,r,Rson);
	return ret;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int top=0;
		st[top]=-1;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&s[i]);
		s[n]=0;
		getsa(*max_element(s,s+n)+1,n);
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			Query[i].clear();
			while(top&&s[st[top]]<=s[i]) 
			{
				ttt[st[top]]=i-1;
				top--;
			}
			sss[i]=st[top]+1;
			st[++top]=i;
		}
		while(top)
		{
			ttt[st[top]]=n-1;
			top--;
		}
		for(int i=0;i<n;i++)
		{
			ans+=1LL*(i-sss[i]+1)*(ttt[i]-i+1)*s[i];
		}
		build();
		for(int i=1;i<=n;i++)
		{
			if(height[i])
			{
				int l=sa[i],r=sa[i]+height[i]-1;
				Query[l].push_back(r);
			}
		}
		top=0;
		st[top]=n;
		for(int i=n-1;i>=0;i--)
		{
			while(top&&s[st[top]]<=s[i])
				top--;
			sss[i]=st[top]-1;
			update(0,sss[i],s[i]);
			st[++top]=i;
			for(auto u:Query[i])
				ans-=query(i,u);
		}
		printf("%lld\n",ans);
	}
}
