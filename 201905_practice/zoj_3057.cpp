#include <bits/stdc++.h>
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
bool sg[305][305][305];
void db()
{
	for(int i=0;i<=300;i++)
	{
		for(int j=0;j<=300;j++)
		{
			for(int k=0;k<=300;k++)
			{
				if(!sg[i][j][k])
				{
					for(int p=1;p+i<=300;p++)
						sg[i+p][j][k]=1;
					for(int p=1;p+j<=300;p++)
						sg[i][p+j][k]=1;
					for(int p=1;p+k<=300;p++)
						sg[i][j][p+k]=1;
					for(int p=1;p+i<=300&&p+j<=300;p++)
						sg[i+p][p+j][k]=1;
					for(int p=1;p+i<=300&&p+k<=300;p++)
						sg[i+p][j][p+k]=1;
					for(int p=1;p+j<=300&&p+k<=300;p++)
						sg[i][j+p][p+k]=1;
				}
			}
		}
	}
}
int main()
{
	memset(sg,0,sizeof(sg));
	db();
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		printf("%d\n",sg[a][b][c]);
	}
}
