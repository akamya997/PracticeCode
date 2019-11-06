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
unordered_map<string,int> mp;
const int maxn=5e5+7;
int val[maxn],w[maxn],rev[maxn*3];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		memset(w,0,sizeof(w));
		mp.clear();
		int cur=1;
		int q,m;
		int num=1;
		cin>>q>>m;
		set<int> cache;
		while(q--)
		{
			int op;string s;int v;
			cin>>op>>s>>v;
			if(!mp.count(s)) mp[s]=++num;
			int tt=mp[s];
			if(op==0)
			{
				if(cache.find(w[tt])!=cache.end())
				{
					cache.erase(w[tt]);
					w[tt]=cur++;
					cache.insert(w[tt]);
					rev[w[tt]]=tt;
				}
				else{
					w[tt]=cur++;
					val[tt]=v;
					cache.insert(w[tt]);
					rev[w[tt]]=tt;
					while(cache.size()>m) 
					{
						w[rev[*cache.begin()]]=0;
						cache.erase(cache.begin());
					}
				}
				cout<<val[tt]<<'\n';
			}
			else{
				int ans=INF;
				if(cache.find(w[tt])!=cache.end())
				{
					auto it=cache.find(w[tt]);
					if(v==-1)
					{
						if(it!=cache.begin())
						{
							--it;
							ans=val[rev[*it]];
						}
					}
					else if(v==1)
					{
						++it;
						if(it!=cache.end()){
							ans=val[rev[*it]];
						}
					}
					else ans=val[rev[*it]];
				}
				if(ans==INF) cout<<"Invalid\n";
				else cout<<ans<<'\n';
			}
	//		flush(cout);
	//		for(auto a:cache) dbg(a.t,w[a.t]);
		}
	}
}
