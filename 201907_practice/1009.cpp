#include <bits/stdc++.h>
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
const int maxn=1e5+7;
int las[maxn][27];
int nxt[maxn][27];
int cnt[27];
int l[27],r[27];
string s;
int tot;
string ans;
bool check(int pos)
{
	if(pos==-1) return false;
	int ret=1;
	if(cnt[s[pos]-'a']==r[s[pos]-'a']) return false;
	cnt[s[pos]-'a']++;
	int res=0;
	for(int i=0;i<26;i++)
	{
		if(l[i]>cnt[i]) res+=l[i]-cnt[i];
		if(las[pos][i]-(s[pos]==(i+'a'))<l[i]-cnt[i])
		{
			ret=0;
			break;
		}
	}
	if(res>tot-(ans.length()+1)) ret=0;
	cnt[s[pos]-'a']--;
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	while(cin>>s>>k)
	{
		tot=k;
		ans="";
		for(int i=0;i<=s.length();i++)
			for(int j=0;j<26;j++) las[i][j]=0;
		int cur[27];
		memset(cur,-1,sizeof(cur));
		memset(cnt,0,sizeof(cnt));
		for(int i=s.length()-1;i>=0;i--)
		{
			for(int j=0;j<26;j++)
				nxt[i][j]=cur[j];
			cur[s[i]-'a']=i;
		}
		for(int i=s.length()-1;i>=0;i--)
		{
			for(int j=0;j<26;j++)
				las[i][j]=las[i+1][j];
			las[i][s[i]-'a']++;
		}
		int al=0;
		for(int i=0;i<26;i++)
		{
			cin>>l[i]>>r[i];
			al+=r[i];
		}
		int pos=-1;
		for(int i=0;i<26;i++)
		{
			if(check(cur[i]))
			{
				ans+=(i+'a');
				cnt[i]++;
				k--;
				pos=cur[i];
				break;
			}
		}
		if(pos==-1||al<k)
			cout<<-1<<endl;
		else 
		{
			while(k--)
			{
				for(int i=0;i<26;i++)
				{
					if(cnt[i]==r[i])
						continue;
					if(check(nxt[pos][i]))
					{
						cnt[i]++;
						ans+=(i+'a');
						pos=nxt[pos][i];
						break;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
}
