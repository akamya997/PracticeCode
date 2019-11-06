#include<bits/stdc++.h>
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
const int maxn=1e5+7;
namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], str[64];
    int l = SIZE, r = SIZE;
    int read(char *s) {
        while (r) {
            for (; l < r && buf[l] <= ' '; l++);
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        int cur = 0;
        while (r) {
            for (; l < r && buf[l] > ' '; l++) s[cur++] = buf[l];
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        s[cur] = '\0';
        return cur;
    }
    template<typename type>
    bool read(type &x, int len = 0, int cur = 0, bool flag = false) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        if (flag) x = -x;
        return true;
    }
    template <typename type>
    type read(int len = 0, int cur = 0, bool flag = false, type x = 0) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        return flag ? -x : x;
    }
} using FastIO::read;
typedef long long ll;
ll arr[maxn];
ll deq[maxn];
ll getup(int i,int k)
{
	return arr[i]-arr[k];
}
int getdown(int i,int k){return i-k;}
int main()
{
	int n,k;
	while(read(n)&&read(k))
	{
		for(int i=1;i<=n;i++)
		{
			read(arr[i]);
			arr[i]+=arr[i-1];
		}
		double ans=0;
		int head=0,tail=0;
		for(int i=k;i<=n;i++)
		{
			int j=i-k;
			while(head+1<tail&&getup(j,deq[tail])*getdown(deq[tail],deq[tail-1])<getup(deq[tail],deq[tail-1])*getdown(j,deq[tail])) tail--;
			deq[++tail]=j;
			int l=head+1,r=tail,pos=l;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(getup(deq[mid+1],deq[mid])*getdown(i,deq[mid])>getup(i,deq[mid])*getdown(deq[mid+1],deq[mid])) r=mid-1,pos=mid;
				else l=mid+1;
			}
			ans=max(ans,(double)(arr[i]-arr[deq[pos]])/(double)(i-deq[pos]));
		}
		printf("%.2f\n",ans);
	}
	return 0;
}
