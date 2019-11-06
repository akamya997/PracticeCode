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
const int maxn=5e5+7;
const int maxbase=20;
int pre[maxn][maxbase+1];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1,temp;i<=n;i++)
	{
		scanf("%d",&temp);
		for(int j=0;j<=maxbase;j++) pre[i][j]=pre[i-1][j];
		for(int j=maxbase;j>=0;j--)
		{
			if(temp>>j&1)
			{
				if(pre[i][j]) temp^=pre[i][j];
				else{
					pre[i][j]=temp;
					for(int k=j-1;k>=0;k--) if(pre[i][k]&&(pre[i][j]>>k&1)) pre[i][j]^=pre[i][k];
					for(int k=j+1;k<=maxbase;k++) if(pre[i][k]>>j&1) pre[i][k]^=pre[i][j];
					break;
				}
			}
		}
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int ans=0;
		for(int j=maxbase;j>=0;j--) if(pre[r][j]>=l&&(ans^pre[r][j])>ans) ans^=pre[r][j];
		printf("%d\n",ans);
	}
}
