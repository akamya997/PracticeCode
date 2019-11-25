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
int n;
int ans[20][20];
int arr[500];
int cnt[1005];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n*n;i++)
	{
		scanf("%d",&arr[i]);
		cnt[arr[i]]++;
	}
	vector<int> four,two,single;
	sort(arr,arr+n*n);
	for(int i=0;i<1001;i++)
	{
		if(cnt[i]%2) single.push_back(i);
		if(cnt[i]%4==0&&cnt[i]) four.push_back(i);
		if(cnt[i]%4==2) two.push_back(i);
	}
	if((n%2==0&&two.size())||single.size()>1||(single.size()&&n%2==0)||(n%2==1&&two.size()>2*(n-1))) puts("NO");
	else{
		puts("YES");
			if(n%2==1)
			{
				if(single[0]%4==1) four.push_back(single[0]);
				else two.push_back(single[0]);
				ans[n/2][n/2]=single[0];
				cnt[single[0]]--;
			}
			if(n>1)
			{
				if(four.size())
				{
					ans[0][0]=ans[0][n-1]=ans[n-1][0]=ans[n-1][n-1]=four[0];
					cnt[four[0]]-=4;
				}
				else{
					ans[0][0]=ans[0][n-1]=ans[n-1][0]=ans[n-1][n-1]=two[0];
					cnt[two[0]]-=4;
				}
			}
		if(n%2==1)
		{
			dbg(cnt[1]);dbg(cnt[2]);dbg(cnt[3]);
			dbg(two);dbg(four);
			int pos=0;
			for(int i=0;i<four.size();i++)
			{
				if(i==0&&!cnt[four[i]]) continue;
				two.push_back(four[i]);
			}
			dbg(two);
			for(int i=0;i<n/2;i++)
			{
				ans[i][n/2]=ans[n-i-1][n/2]=two[pos];
				cnt[two[pos]]-=2;
				if(!cnt[two[pos]]) pos++;
			}
			for(int i=0;i<n/2;i++)
			{
				ans[n/2][i]=ans[n/2][n-i-1]=two[pos];
				cnt[two[pos]]-=2;
				if(!cnt[two[pos]]) pos++;
			}
			for(int i=1;i<n/2;i++)
			{
				ans[0][i]=ans[0][n-i-1]=ans[n-1][i]=ans[n-1][n-1-i]=two[pos];
				cnt[two[pos]]-=4;
				if(!cnt[two[pos]]) pos++;
			}
			for(int i=1;i<n/2;i++)
			{
				ans[i][0]=ans[i][n-1]=ans[n-i-1][0]=ans[n-i-1][n-1]=two[pos];
				cnt[two[pos]]-=4;
				if(!cnt[two[pos]]) pos++;
			}
			for(int i=1;i<n/2;i++)
			{
				for(int j=1;j<n/2;j++)
				{
					ans[i][j]=ans[i][n-1-j]=ans[n-1-i][j]=ans[n-1-i][n-1-j]=two[pos];
					cnt[two[pos]]-=4;
					if(!cnt[four[pos]]) pos++;
				}
			}
			
		}
		else{
			int pos=0;
			if(!cnt[four[pos]]) pos++;
			for(int i=1;i<n/2;i++)
			{
				ans[0][i]=ans[0][n-i-1]=ans[n-1][i]=ans[n-1][n-i-1]=four[pos];
				cnt[four[pos]]-=4;
				if(!cnt[four[pos]]) pos++;
			}
			for(int i=1;i<n/2;i++)
			{
				for(int j=0;j<n/2;j++)
				{
					ans[i][j]=ans[i][n-1-j]=ans[n-1-i][j]=ans[n-1-i][n-1-j]=four[pos];
					cnt[four[pos]]-=4;
					if(!cnt[four[pos]]) pos++;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d ",ans[i][j]);
			}
			puts("");
		}
	}
}
