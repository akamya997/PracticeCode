#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstdio>
using namespace std;
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
const int maxn=1e6+7;
inline bool scan_d(int &num)
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}
template <typename T>
void o(T p) {
    static int stk[70], tp;
    if (p == 0) { putchar('0'); return; }
    if (p < 0) { p = -p; putchar('-'); }
    while (p) stk[++tp] = p % 10, p /= 10;
    while (tp) putchar(stk[tp--] + '0');
}
int arr[maxn];
int ans1[maxn],ans2[maxn];
int minq[maxn],maxq[maxn];
int main()
{
	int n,k;
	scan_d(n);
	scan_d(k);
	int headmin=0,tailmin=0,headmax=0,tailmax=0;
	for(int i=0;i<n;i++)
	{
		scan_d(arr[i]);
		while(headmin<tailmin&&arr[minq[tailmin]]>=arr[i]) tailmin--;
		minq[++tailmin]=i;
		while(headmax<tailmax&&arr[maxq[tailmax]]<=arr[i]) tailmax--;
		maxq[++tailmax]=i;
		if(i-minq[headmin+1]>=k) headmin++;
		if(i-maxq[headmax+1]>=k) headmax++;
		if(i>=k-1)
		{
			ans1[i]=arr[minq[headmin+1]];
			ans2[i]=arr[maxq[headmax+1]];
		}
	}

	for(int i=k-1;i<n;i++) 
	{
		o(ans1[i]);
		putchar(' ');
	}
	puts("");
	for(int i=k-1;i<n;i++) 
	{
		o(ans2[i]);
		putchar(' ');
	}
	puts("");

}
