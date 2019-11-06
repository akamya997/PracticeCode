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
int val[105];
struct cost{
	int c10,c20,c50,c100;
	cost operator-(const cost a)const{
		return {c10-a.c10,c20-a.c20,c50-a,c50,c100-a.c100};
	}
};
inline cost getcost(int x)
{
	cost ret={0,0,0,0};
	ret.c100+=x/100;
	x%=100;
	ret.c50+=x/50;
	x%=50;
	ret.c20+=x/20;
	x%=20;
	ret.c10+=x/10;
	return ret;
}
int main()
{
	int T;
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		bool ok=1;
		for(int i=0;i<n;i++)
		{
			cin>>val[i];
			if(val[i]%10!=0)
				ok=0;
		}
		if(!ok)
			cout<<-1<<endl;
		else{
			sort(val,val+n,greater<int>());
			cost cnt=getcost(val[0]);
			for(int i=1;i<n;i++)
			{
				cost cur=getcost(val[i]);
				cost need=cur-cnt;
				if(need.c50>0)
				{
					cnt.c100-=(need.c50+1)/2;
					cnt.c50+=(need.c50+1)/2*2;
				}
				if(need.c20>0)
				{
					int tar=(need.c20+1)/2;
					if(cnt.c50>=tar)
					{
						cnt.c50-=tar;
						cnt.c20+=tar*2;
						cnt.c10+=tar;
						need.c10-=tar;
					}
					else{
						cnt.c20+=cnt.c50*2;
						cnt.c10+=cnt.c50;
						need.c20-=cnt.c50*2;
						need.c10-=cnt.c50;
						cnt.c50=0;
						int nxtar=(need.c20+3)/4;
						cnt.c100-=nxtar;
						cnt.c20+=nxtar*4;
					}
				}
				if(need.c10>0)
				{
					int tar=
				}
			}
			int ans=cnt.c100+cnt.c50+cnt.c20+cnt.c10;
			cout<<ans<<endl;
		}
	}
}
