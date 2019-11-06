#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
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
const int maxn=1e5+105;
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
int dp[maxn][30];
void initrmq(int n)
{
    for (int i = 1; i <= n; i++)
        dp[i][0] = height[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}
int rmq(int l, int r)
{
	int k = 31 - __builtin_clz(r - l + 1);
    return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}
int lcp(int a, int b)
{ // 求两个后缀的最长公共前缀
    a = rk[a], b = rk[b];
    if (a > b) swap(a, b);
    return rmq(a + 1, b);
}
int main()
{
	int kas=0;
	while(~scanf("%s",s)&&s[0]!='#')
	{
		char mi=127;
		int len=strlen(s);
		for(int i=0;i<len;i++)
			mi=min(mi,s[i]);
		build_sa(128,len);
		initrmq(len);
		int st=-1,ma=0;
		vector<int> ans;
		for(int i=1;i<=len;i++)
		{
			for(int j=0;j+i<len;j+=i)
			{
				int cur=lcp(j+i,j);
				int curlen=cur/i+1;
				int pre=j-(i-cur%i);
				if(pre>=0&&lcp(pre,pre+i)>=i)
					curlen++;
				if(ma<curlen)
				{
					ma=curlen;
					ans.clear();
					ans.push_back(i);
				}
				else if(ma==curlen&&i!=ans.back())
					ans.push_back(i);
			}
		}
	//	dbg(ans);
	//	dbg(ma);
		for(int i=1;i<=len;i++)
		{
			for(int j=0;j<ans.size();j++)
			{
				int u=ans[j];
				if(lcp(sa[i],sa[i]+u)>=u*(ma-1))
				{
					st=sa[i];
					ma=ma*u;
					break;
				}
			}
			if(st!=-1) break;
		}
		printf("Case %d: ",++kas);
		for(int i=st;i<st+ma;i++)
			printf("%c",s[i]);
		puts("");
	}
}
