#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=1e4+7;
int arr[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	if(n==1) puts("1");
	else if(n==2)
		puts("2");
	else if(n==3) puts("6");
	else{
		if(n%4==0) puts("4");
		else if(n%4==1){
			printf("%d\n",2*n);
		}
		else if(n%4==2)
		{
			printf("%d\n",n);
		}
		else puts("12");
	}
}
