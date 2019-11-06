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
struct Point{
	int x,y;
};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	Point A,B;
	scanf("%d%d%d%d",&A.x,&A.y,&B.x,&B.y);
	int dis=abs(B.x-A.x)+abs(B.y-A.y);
	if(dis%2==0) puts("Win");
	else puts("Lose");
}
