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
string s[4];
string t[4];
vector<int> ord={0,1,2,3};
inline int Hash(char a,char b)
{
	return (int)(a-'a')*26+(int)(b-'a');
}
int c2[707],c3[707];
ll solve()
{
	for(int i=0;i<4;i++) 
		t[i]=s[ord[i]];
	ll ret=0;
	for(int d=-(int)(t[0].length())+1;d<(int)t[1].length();d++)
	{
		for(int dis=2;dis<=min((int)t[2].length(),(int)t[3].length())-1;dis++)
		{
			memset(c2,0,sizeof(c2));
			memset(c3,0,sizeof(c3));
			ll tot=0;
			for(int i=0;i+dis<t[2].length();i++)
				c2[Hash(t[2][i],t[2][i+dis])]++;
			for(int i=0;i+dis<t[3].length();i++)
				c3[Hash(t[3][i],t[3][i+dis])]++;
			for(int i=0;i<t[0].length();i++)
			{
				int j=i+d;
				if(j<0||j>=t[1].length()) continue;
				tot+=c3[Hash(t[0][i],t[1][j])];
			}
				//dbg(d,dis,tot);
			if(d>=0&&d<t[1].length())
				tot-=c3[Hash(t[0][0],t[1][d])];
			for(int i=0;i<t[0].length();i++)
			{
				int j=i+d;
				if(i+1<t[0].length()&&j+1>=0&&j+1<t[1].length())
					tot-=c3[Hash(t[0][i+1],t[1][j+1])];
				if(j<0||j>=t[1].length()) continue;
			//if(cnt==8) dbg(i,j,tot);
				ret+=tot*c2[Hash(t[0][i],t[1][j])];
			}
			//if(cnt==8) dbg(ret);
		}
	}
	return ret;
}
int main()
{
	for(int i=0;i<4;i++) cin>>s[i];
	ll ans=0;
	sort(s,s+4);
	do{
		ans+=solve();
	}while(next_permutation(ord.begin(),ord.end()));
	printf("%lld\n",ans);
}
