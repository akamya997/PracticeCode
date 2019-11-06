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
const int maxn=1e5+7;
struct node{
	int id;
	ll num;
	bool operator<(const node &a)const{
		return num>a.num;
	}
};
ll sum[maxn];
vector<int> ans[maxn];
ll inv(ll a){return quick(a,mod-2);}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		ll tot=1LL*n*(n+1)/2;
		if(k==n)
		{
			if(n==1)
			{
				puts("yes");
				puts("1 1");
			}
			else puts("no");
		}
		else{
			if(tot%k!=0)
			{
				puts("no");
				continue;
			}
			puts("yes");
			for(int i=0;i<=k;i++) sum[i]=0;
			priority_queue<node> q;
			for(int i=1;i<=k;i++)
			{
				q.push(node{i,0});
				ans[i].clear();
			}
			for(int i=1;i<=n;i++)
			{
				auto u=q.top();q.pop();
				ans[u.id].push_back(i);
				sum[u.id]+=i;
				q.push(node{u.id,sum[u.id]});
			}
			for(int i=1;i<=k;i++)
			{
				for(auto u:ans[i])
					printf("%d ",u);
				puts("");
			}
			ll tar=tot/k;
			for(int i=1;i<=k;i++)
			{
				cout<<i<<":"<<sum[i]<<endl;
			}

		}
	}
}
