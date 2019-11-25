#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
typedef long long ll;
template <typename T>
bool scan_d(T &num)
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
const int maxn=4e5+7;
ll arr[maxn];
ll pre[maxn];
ll dp[maxn];
int deq[maxn];
ll getup(int k,int j)
{
	return dp[k]-pre[k]+k*arr[k+1]-dp[j]+pre[j]-j*arr[j+1];
}
ll getdown(int k,int j){return arr[k+1]-arr[j+1];}
int main()
{
	int n,T;
	while(~scanf("%d%d",&n,&T))
	{
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=n;i++) 
			scan_d(arr[i]);
		sort(arr+1,arr+1+n);
		for(int i=1;i<=n;i++)
			pre[i]=pre[i-1]+arr[i];
		int head=0,tail=0;
		deq[++tail]=0;
		dp[0]=0;
		for(int i=T;i<=n;i++)
		{
			int j=i-T;
			if(dp[j]!=-1)
			{
				while(head+1<tail&&getup(j,deq[tail])*getdown(deq[tail],deq[tail-1])<=getup(deq[tail],deq[tail-1])*getdown(j,deq[tail])) tail--;
				deq[++tail]=j;
			}
			while(head+1<tail&&getup(deq[head+2],deq[head+1])<=i*getdown(deq[head+2],deq[head+1])) head++;
			int pos=deq[head+1];
			dp[i]=dp[pos]+pre[i]-pre[pos]-(i-pos)*arr[pos+1];
			dbg(i);
			dbg(dp[i]);
		}
		printf("%lld\n",dp[n]);
	}
}
