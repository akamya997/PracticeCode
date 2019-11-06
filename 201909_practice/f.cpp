#include <iostream>
#include<string>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
string s[55];
int dp[2150][26];
int pre[2150][26];
void print(int i,int j)
{
	if(dp[i][j]==-1) return;
	int cur=dp[i][j];
	print(i-s[cur].length(),pre[i][s[cur][s[cur].length()-1]-'a']);
	cout<<s[dp[i][j]];
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,l;
	while(cin>>n>>l)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) cin>>s[i];
		sort(s+1,s+1+n);
		for(int i=0;i<26;i++) dp[0][i]=-1;
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<26;j++)
			{
				if(dp[i][j])
				{
					for(int k=1;k<=n;k++)
					{
						if(s[k][0]=='a'+j)
						{
							if(dp[i+s[k].length()][s[k][s[k].length()-1]-'a']==0)
							{
								dp[i+s[k].length()][s[k][s[k].length()-1]-'a']=k;
								pre[i+s[k].length()][s[k][s[k].length()-1]-'a']=j;
							}
						}
					}
				}
			}
		}
		int tar=-1,ed;
		for(int i=l;i<=l+100;i++)
		{
			for(int j=0;j<26;j++)
			{
				if(dp[i][j])
				{
					tar=i;
					ed=j;
					break;
				}
			}
			if(tar!=-1) break;
		}
		if(tar==-1)
			cout<<tar<<endl;
		else{
			print(tar,ed);
			cout<<endl;
		}
	}

}
