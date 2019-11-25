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
const int maxn=1e5+7;
int arr[maxn];
int dpmax[maxn][21],dpmin[maxn][21];
int n,m,k;
void RMQ()
{
	memset(dpmax,0,sizeof(dpmax));
	memset(dpmin,0,sizeof(dpmin));
	for(int i=0;i<n;i++) dpmax[i][0]=dpmin[i][0]=i;
	for(int j=1;j<21;j++)
	{
		for(int i=0;i+(1<<j)-1<n;i++)
		{
			if(arr[dpmax[i][j-1]]>arr[dpmax[i+(1<<(j-1))][j-1]]) dpmax[i][j]=dpmax[i][j-1]; 
			else dpmax[i][j]=dpmax[i+(1<<(j-1))][j-1];
			if(arr[dpmin[i][j-1]]<arr[dpmin[i+(1<<(j-1))][j-1]]) dpmin[i][j]=dpmin[i][j-1]; 
			else dpmin[i][j]=dpmin[i+(1<<(j-1))][j-1];
		}
	}
}
int query(int l,int r,int type)
{
	int k=(int)(log((double)(r - l + 1)) / log(2.0));
	if(type==1)
	{
		if(arr[dpmax[l][k]]>arr[dpmax[r-(1<<k)+1][k]]) return dpmax[l][k];
		return dpmax[r-(1<<k)+1][k];
	}
	else{
		if(arr[dpmin[l][k]]<arr[dpmin[r-(1<<k)+1][k]]) return dpmin[l][k];
		return dpmin[r-(1<<k)+1][k];
	}
}
int main()
{
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(int i=0;i<n;i++) scanf("%d",&arr[i]);
		RMQ();
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(i!=n-1)
			{
				int sufmax=query(i+1,n-1,1);
				int sufmin=query(i+1,n-1,0);
				int diff=abs(arr[i]-arr[sufmax]);
				if(diff>=m&&diff<=k) ans=max(ans,sufmax-i+1);
				diff=abs(arr[i]-arr[sufmin]);
				if(diff>=m&&diff<=k) ans=max(ans,sufmin-i+1);
			}
			if(i)
			{
				int premax=query(0,i-1,1);
				int premin=query(0,i-1,0);
				int diff=abs(arr[i]-arr[premax]);
				if(diff>=m&&diff<=k) ans=max(ans,i-premax+1);
				diff=abs(arr[i]-arr[premin]);
				if(diff>=m&&diff<=k) ans=max(ans,i-premin+1);
			}
		}
		printf("%d\n",ans);
	}
}
