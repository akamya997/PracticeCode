#include <iostream>
#include <cstdio>
#include <cstring>
#include<cmath>
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
const int maxn = 2e5+7;
int len;
char s[maxn];
int c[maxn], x[maxn], sa[maxn], y[maxn];
//c[i]桶，x[i]第i個元素關鍵字
void getsa()
//y[i]第二關鍵字排名爲i的數，第一關鍵字的位置
{
    int m = 130;
    for (int i = 0; i <= m; ++i)
        c[i] = 0;
    for (int i = 1; i <= len; ++i) //裝桶
        ++c[x[i] = s[i]];
    for (int i = 2; i <= m; ++i) //前綴和把桶變排名
        c[i] += c[i - 1];
    for (int i = len; i > 0; --i) //基數排序數組填充
        sa[c[x[i]]--] = i;
    for (int k = 1; k <= len; k <<= 1) //倍增
    {
        int num = 0;
        for (int i = len - k + 1; i <= len; ++i) //這些第i個沒有第二關鍵字，靠前排
            y[++num] = i;
        for (int i = 1; i <= len; ++i)
            if (sa[i] > k) //表示可以做別人的第二關鍵字
                y[++num] = sa[i] - k;
        for (int i = 1; i <= m; ++i)
            c[i] = 0;                  //初始化桶
        for (int i = 1; i <= len; ++i) //基數排序
            ++c[x[i]];
        for (int i = 2; i <= m; ++i)
            c[i] += c[i - 1];
        for (int i = len; i > 0; --i)
        {
            sa[c[x[y[i]]]--] = y[i]; //第二關鍵字靠後的，同一個桶裏靠後
            y[i] = 0;
        }
        swap(x, y); //保存第一關鍵字到y，備用
        x[sa[1]] = 1;
        num = 1;
        for (int i = 2; i <= len; ++i) //構建下一次的第一關鍵字
            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++num;
        if (num == len)
            break;
        m = num;
    }
}

int rk[maxn], height[maxn];

void geth()
{
    int k = 0;
    for (int i = 0; i <= len; ++i)
        height[i] = 0;
    for (int i = 1; i <= len; ++i)
        rk[sa[i]] = i;
    for (int i = 1; i <= len; ++i)
    {
        if (rk[i] == 1) //height[1]=0
            continue;
        if (k)
            --k;
        int j = sa[rk[i] - 1];
        while (j + k <= len && i + k <= len && s[i + k] == s[j + k])
            ++k;
        height[rk[i]] = k;
    }
}

int minm[maxn][18];

int pos;
int solve()
{
	int ret=0;
	for(int i=2;i<=len;i++)
	{
		if((sa[i-1]<pos)^(sa[i]<pos))
			ret=max(ret,height[i]);
	}
	return ret;
}
int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	s[len+1]='$';
	pos=len;
	scanf("%s",s+len+2);
	len=strlen(s+1);
	getsa();
	geth();
	printf("%d\n",solve());
}
