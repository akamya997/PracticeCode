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

long long d;
long long x,y;
void mysearch()
{
	bool fi=1;
    y=1;
    while(1){
        x=(ll)sqrt(d*y*y+1);
        if(x*x-d*y*y==1){
            if(!fi) break;
			fi=0;
        }
        y++;
    }
}

int main()
{
	for(int i=2;i<30;i++)
	{
		if(sqrt(i)*sqrt(i)==i) continue;
		d=i;
		mysearch();
		printf("%d-- x:%d y:%d\n",d,x,y);
		
	}
}
