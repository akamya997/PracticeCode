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
typedef pair<int,int> PII;
int cnt[15];
int dp[15][15][15][2];
bool dfs(int pos,int p,int pp,bool qt=0)
{
	if(p<0||pp<0||pp<p) return false;
	if(pos==10) return p==0&&pp==0&&qt==1;
	if(dp[pos][p][pp][qt]!=-1) return dp[pos][p][pp][qt];
	int ret=0;
	for(int i=p;i<=cnt[pos];i++)
	{
		if((cnt[pos]-i)%3==0||((cnt[pos]-i)==2)&&!qt)
		{
			if(cnt[pos]-i==2)
				ret|=dfs(pos+1,pp-p,i-p,1);
			else ret|=dfs(pos+1,pp-p,i-p,qt);
		}
	}
	return dp[pos][p][pp][qt]=ret;
}
bool judge()
{
	bool qidui=1;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=9;i++) if(cnt[i]&&cnt[i]!=2) qidui=0;
	return qidui||dfs(1,0,0);
}
int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		memset(cnt,0,sizeof(cnt));
		vector<int> hand;
		for(int i=0,tmp;i<13;i++)
		{
			scanf("%d",&tmp);
			cnt[tmp]++;
			hand.push_back(tmp);
		}
		cnt[n]++;
		hand.push_back(n);
		if(judge())
			puts("tsumo");
		else{
			set<int> ans[15];
			for(int i=0;i<14;i++)
			{
				for(int j=1;j<=9;j++)
				{
					if(cnt[j]==4) continue;
					cnt[hand[i]]--;
					cnt[j]++;
					if(judge())
						ans[hand[i]].insert(j);
					cnt[j]--;
					cnt[hand[i]]++;
				}
			}
			bool ok=0;
			for(int i=0;i<15;i++) if(ans[i].size()) ok=1;
			if(!ok) puts("noten");
			else{
				puts("tenpai");
				for(int i=0;i<15;i++)
				{
					if(ans[i].size())
					{
						printf("%d:",i);
						for(auto j:ans[i])
							printf(" %d",j);
						puts("");
					}
				}
			}
		}
	}
}
