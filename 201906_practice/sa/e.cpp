#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
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
const int maxn=2e5+7;
char s[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn], rk[maxn], height[maxn];
void build_sa(int m, int n)
{ //n为字符串的长度,字符集的值为0~m-1
    n++;
    int *x = t, *y = t2;
    //基数排序
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; ~i; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1)
    { //直接利用sa数组排序第二关键字
        int p = 0;
        for (int i = n - k; i < n; i++) y[p++] = i;
        for (int i = 0; i < n; i++)
            if (sa[i] >= k) y[p++] = sa[i] - k;
        //基数排序第一关键字
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 1; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; ~i; i--) sa[--c[x[y[i]]]] = y[i];
        //根据sa和y数组计算新的x数组
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n) break; //以后即使继续倍增，sa也不会改变，推出
        m = p;             //下次基数排序的最大值
    }
    n--;
    int k = 0;
    for (int i = 0; i <= n; i++) rk[sa[i]] = i;
    for (int i = 0; i < n; i++)
    {
        if (k) k--;
        int j = sa[rk[i] - 1];
        while (s[i + k] == s[j + k]) k++;
        height[rk[i]] = k;
    }
}
int k;
int st[maxn],cnt[maxn];
int main()
{
	while(~scanf("%d",&k)&&k)
	{
		scanf("%s",s);
		int len=strlen(s);
		s[len]='$';
		int pos=len;
		scanf("%s",s+len+1);
		len=strlen(s);
		build_sa(128,len);
		ll ans=0;
		int l=1,r=1;
		while(l<=len)
		{
			while(l<=len&&height[l]<k) l++;
			r=l;
			int head=0;
			ll tot=0;
			while(r<=len&&height[r]>=k) 
			{
				int tmp=0;
				if(sa[r-1]>pos) tmp++;
				while(head&&height[r]<=st[head])
				{
					tot-=1LL*cnt[head]*(st[head]-k+1);
					tmp+=cnt[head];
					head--;
				}
				st[++head]=height[r];
				tot+=1LL*tmp*(height[r]-k+1);
				cnt[head]=tmp;
				if(sa[r]<pos)
					ans+=tot;
				r++;
	//			dbg(l,r,tot,ans);
			}
			l=r;
		}
		l=1,r=1;
		while(l<=len)
		{
			while(l<=len&&height[l]<k) l++;
			r=l;
			int head=0;
			ll tot=0;
			while(r<=len&&height[r]>=k) 
			{
				int tmp=0;
				if(sa[r-1]<pos) tmp++;
				while(head&&height[r]<=st[head])
				{
					tot-=1LL*cnt[head]*(st[head]-k+1);
					tmp+=cnt[head];
					head--;
				}
				st[++head]=height[r];
				tot+=1LL*tmp*(height[r]-k+1);
				cnt[head]=tmp;
				if(sa[r]>pos)
					ans+=tot;
				r++;
			}
			l=r;
		}
		printf("%lld\n",ans);
	}
}
