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
int absday;
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
map<char,int> val;
int n;
const int maxn=1e5+7;
string s[maxn];
int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline bool isrn(int year)
{
	if(year%100!=0)
	{
		if(year%4==0) return true;
		return false;
	}
	return year%400==0;
}
inline int DateToInt (int m, int d, int y){
  return
    1461 * (y + 4800 + (m - 14) / 12) / 4 +
    367 * (m - 2 - (m - 14) / 12 * 12) / 12 -
    3 * ((y + 4900 + (m - 14) / 12) / 100) / 4 +
    d - 32075;
}
bool ban[14][14];
inline int getval(int k)
{
	int year=0;
	for(int i=0;i<4;i++)
	{
		year=year*10+val[s[k][i]];
	}
	if(year<1600) return -1;
	int mon=0;
	for(int i=5;i<7;i++)
		mon=mon*10+val[s[k][i]];
	int day=0;
	for(int i=8;i<10;i++)
		day=day*10+val[s[k][i]];
	if(mon>12||mon==0||day==0) return -1;
	if(day>month[mon]+((mon==2&&isrn(year)))) return -1;
	return DateToInt(mon,day,year);
}
bool check(vector<int> &cur)
{
	for(int i=0;i<10;i++)
		val[i+'A']=cur[i];
	for(int i=1;i<=n;i++)
	{
		int cur=getval(i);
		if(cur==-1) return false;
		if((cur-absday)%7!=0) return false;
	}
	return true;
}
int main()
{
	std::ios::sync_with_stdio(false);
	absday=DateToInt(8,2,2019);
	cin.tie(NULL);
	int T;
	cin>>T;
	int kas=0;
	while(T--)
	{
		memset(ban,0,sizeof(ban));
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			cin>>s[i];
			ban[s[i][0]-'A'][0]=1;
			for(int j=2;j<=9;j++)
				ban[s[i][5]-'A'][j]=1;
			for(int j=4;j<=9;j++)
				ban[s[i][8]-'A'][j]=1;
		}
		sort(s+1,s+1+n);
		int newn=2;
		for(int i=2;i<=n;i++)
		{
			if(s[i]!=s[i-1])
				s[newn++]=s[i];
		}
		n=newn-1;
		vector<int> all;
		for(int i=0;i<10;i++)
			all.push_back(i);
		bool ok=0;
		do{
			bool sk=0;
			for(int i=0;i<10;i++)
			{
				if(ban[i][all[i]]) 
				{
					sk=1;
					break;
				}
			}
			if(sk) continue;
			if(check(all))
			{
				ok=1;
				break;
			}
		}while(next_permutation(all.begin(),all.end()));
		cout<<"Case #"<<++kas<<": ";
		if(ok)
		{
			for(auto u:all) cout<<u;
			cout<<endl;
		}
		else cout<<"Impossible"<<endl;
	}
}
