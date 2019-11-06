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
bool ans[maxn];
int main()
{
	int delta=32768,mx=delta+32767;
	string s;
	while(getline(cin,s))
	{
		stringstream ss(s);
		string t1,t;
		if(ss>>t1);
		else break;
		ss>>t;
		int x;
		ss>>x;
		x+=delta;
		string tmp;
		if(ss>>tmp&&tmp[0]!='|')
		{
			ss>>t;
			ss>>t;
			int r;
			ss>>r;
			r+=delta;
			for(int i=x;i<=r;i++)
				ans[i]=1;
		}
		else{
			if(t[0]=='>')
			{
				for(int i=x;i<=mx;i++)
					ans[i]=1;
			}
			else{
				for(int i=x;i>=0;i--)
					ans[i]=1;
			}
		}
	}
	bool ok=1;
	for(int i=0;i<=mx;i++)
		if(ans[i]) ok=0;
	if(ok)
		cout<<"false"<<endl;
	else{
		bool sss=1;
		for(int i=0;i<=mx;i++)
			if(!ans[i]) sss=0;
		if(sss) cout<<"true"<<endl;
		else{
			vector<PII> ou;
			int pre=0;
			for(int i=0;i<=mx+1;i++)
			{
				if(!ans[i])
				{
					if(pre!=i)
						ou.push_back(make_pair(pre,i-1));
					pre=i+1;
				}
			}
			for(int i=0;i<ou.size();i++)
			{
				auto u=ou[i];
				if(u.first==0)
					cout<<"x <= "<<u.second-delta;
				else if(u.second==mx)
					cout<<"x >= "<<u.first-delta;
				else{
					cout<<"x >= "<<u.first-delta<<" && x <= "<<u.second-delta;
				}
				if(i==ou.size()-1) cout<<endl;
				else cout<<" ||"<<endl;
			}
		}
	}
}
