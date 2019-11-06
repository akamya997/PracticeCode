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
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b,ll mod)
{
	assert(b>=0);
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
ll inv(ll a,ll mod){return quick(a,mod-2,mod);}
ll seed;
ll rnd()
{
	ll ret=seed;
	seed=(seed*7+13)%1000000007;
	return ret;
}
const int maxn=1e5+7;
ll a[maxn];
int n,m,vmax;
struct node{
	int l,r;
	mutable ll val;
	bool operator<(const node &a)const{
		return l<a.l;
	}
};
set<node> st;
set<node>::iterator split(int p)
{
	auto it=st.lower_bound({p,p,0});
	if(it!=st.end()&&it->l==p) return it;
	--it;
	int l=it->l,r=it->r;ll val=it->val;
	st.erase(it);
	st.insert({l,p-1,val});
	return st.insert({p,r,val}).first;
}
struct C{
	ll val,cnt;
	bool operator<(const C &a)const{
		return val<a.val;
	}
};
int main()
{
	scanf("%d%d%lld%d",&n,&m,&seed,&vmax);
	for(int i=1;i<=n;i++)
	{
		a[i]=(rnd()%vmax)+1;
		st.insert({i,i,a[i]});
	}
	st.insert({n+1,n+1,0});
	for(int i=1;i<=m;i++)
	{
		int op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1;
		if(l>r) swap(l,r);
		ll x,y;
		if(op==3)
		{
			x=rnd()%(r-l+1)+1;
		}
		else x=rnd()%vmax+1;
		if(op==4)
			y=rnd()%vmax+1;
		auto L=split(l),R=split(r+1);
		if(op==1)
		{
			while(L!=R)
			{
				L->val+=x;
				L++;
			}
		}
		else if(op==2)
		{
			st.erase(L,R);
			st.insert({l,r,x});
		}
		else if(op==3)
		{
			static vector<C> all;
			all.clear();
			while(L!=R)
			{
				all.push_back({L->val,L->r - L->l + 1});
				L++;
			}
			sort(all.begin(),all.end());
			for(int i=0;i<all.size();i++)
			{
				x-=all[i].cnt;
				if(x<=0)
				{
					printf("%lld\n",all[i].val);
					break;
				}
			}
		}
		else{
			ll ans=0;
			while(L!=R)
			{
				ans=(ans+quick(L->val,x,y)*(L->r-L->l+1)%y)%y;
				L++;
			}
			printf("%lld\n",ans);
		}

	}
	
}
