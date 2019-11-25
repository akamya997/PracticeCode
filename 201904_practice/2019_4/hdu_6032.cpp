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
const int INF=0x3f3f3f3f;
struct SG{
	int flag;
	int mys,ops;
	bool operator<(const SG &a)const{
		if(flag==a.flag)
		{
			if(ops==a.ops)
				return mys<a.mys;
			return ops>a.ops;
		}
		return flag<a.flag;
	}
};

map<string,int> cnt;
map<string,int> ext;
map<string,set<int> > mst;
map<string,SG> dp;
int n;
char str[50];
int calc(string s)
{
	int cur=0,ma=0;
	for(int i=0;i<s.length();i++)
	{
		int c=s[i]-'a'+1;
		cur+=c;
		ma=max(ma,c);
	}
	return cur*ma+mst[s].size();
}
SG dfs(string s="")
{
	if(dp.count(s)) return dp[s];
	SG ret={1,INF,0};
	for(int i=0;i<26;i++)
	{
		char c=i+'a';
		string nxt=s+c;
		if(ext.count(nxt))
		{
			SG tmp=dfs(nxt);
			ret=min(ret,tmp);
		}
		string nxt2=c+s;
		if(ext.count(nxt2))
		{
			SG tmp=dfs(nxt2);
			ret=min(ret,tmp);
		}
	}
	if(ret.mys==INF) return (SG {0,0,calc(s)});
	return dp[s]=SG{ret.flag^1,ret.ops,ret.mys+calc(s)};
}
int main()
{
	while(~scanf("%d",&n))
	{
		dp.clear();
		cnt.clear();
		ext.clear();
		mst.clear();
		for(int i=0;i<n;i++) 
		{
			scanf("%s",str);
			int len=strlen(str);
			for(int j=0;j<len;j++)
			{
				string cur="";
				for(int k=j;k<len;k++)
				{
					cur+=str[k];
					ext[cur]=1;
					cnt[cur]++;
					mst[cur].insert(i);
				}
			}
		}
		SG ans=dfs();
		if(ans.flag) puts("Alice");
		else{
			puts("Bob");
		}
		printf("%d %d\n",ans.mys,ans.ops);
	}
}
