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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a==c&&b==d)
		{
			cout<<"Yes\n\n";
			continue;
		}
		bool flag=0;
		if(a>b)
		{
			swap(a,b);
			swap(c,d);
			flag=1;
		}
		ll dl=a-c,dr=d-b,dd=b-a;
		if(dl<0||dr<0||dd==0||dl%dd!=0||dr%dd!=0)
			cout<<"No\n";
		else{
			ll lb=dl/dd,rb=dr/dd;
			ll tot=(lb|rb)+1;
			if(__builtin_popcountll(tot)==1&&__builtin_popcountll(lb)+__builtin_popcountll(rb)==__builtin_popcountll(lb|rb))
			{
				cout<<"Yes\n";
				string ans="";
				for(int i=0;;i++)
				{
					if(lb>>i&1) ans+='B';
					else if(rb>>i&1) ans+='A';
					else break;
				}
				if(flag)
				for(int i=0;i<ans.length();i++)
				{
					if(ans[i]=='A') ans[i]='B';
					else ans[i]='A';
				}
				cout<<ans<<"\n";
			}
			else{
				cout<<"No\n";
			}
		}
	}
}
