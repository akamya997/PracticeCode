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
int cnt[4][15];
int dp[15][15][15][4][2];
bool dfs(int pos,int p,int pp,int type,bool qt=0)
{
	if(p<0||pp<0||pp<p) return false;
	if(pos==8&&type==3) return qt==1;
	else if(pos==10) return p==0&&pp==0&&dfs(1,0,0,type+1,qt);
	if(dp[pos][p][pp][type][qt]!=-1) return dp[pos][p][pp][type][qt];
	int ret=0;
	if(type==3)
	{
		if(cnt[type][pos]==4) ret=0;
		else if(cnt[type][pos]==3) ret|=dfs(pos+1,p,pp,type,qt);
		else if(cnt[type][pos]==2) 
		{
			if(qt) ret=0;
			else ret|=dfs(pos+1,p,pp,type,1);
		}
		else if(cnt[type][pos]==1){
			ret=0;
		}
		else ret|=dfs(pos+1,p,pp,type,qt);
	}
	else{
		for(int i=p;i<=cnt[type][pos];i++)
		{
			if((cnt[type][pos]-i)%3==0||((cnt[type][pos]-i)==2)&&!qt)
			{
				if(cnt[type][pos]-i==2)
					ret|=dfs(pos+1,pp-p,i-p,type,1);
				else ret|=dfs(pos+1,pp-p,i-p,type,qt);
			}
		}
	}
	return dp[pos][p][pp][type][qt]=ret;
}
bool judge()
{
	memset(dp,-1,sizeof(dp));
	return dfs(1,0,0,0);
}
struct ANS{
	int tp,num;
};
int main()
{
	string s;
	while(getline(cin,s))
	{
		memset(cnt,0,sizeof(cnt));
		stringstream ss(s);
		for(int i=0;i<13;i++)
		{
			string tmp;
			ss>>tmp;
			int tp;
			if(tmp[1]=='m') tp=0;
			else if(tmp[1]=='s') tp=1;
			else if(tmp[1]=='p') tp=2;
			else tp=3;
			cnt[tp][tmp[0]-'0']++;
	//		dbg(tmp[0]-'0');
		}
		vector<ANS> ans;
		for(int k=0;k<4;k++)
		{
			for(int j=1;j<=9;j++)
			{
				if(k==4&&j>=8) break;
				if(cnt[k][j]==4) continue;
				cnt[k][j]++;
				if(judge())
					ans.push_back(ANS{k,j});
				cnt[k][j]--;
			}
		}
	//	dbg(ans.size());
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i].num;
			if(ans[i].tp==0) cout<<'m';
			else if(ans[i].tp==1) cout<<'s';
			else if(ans[i].tp==2) cout<<'p';
			else cout<<'z';
			cout<<endl;
		}
	}
}
