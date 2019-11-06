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
const int maxn=4e5+7;
ll A[maxn<<1],B[maxn<<1];
template<typename T>
void fwt(ll a[], int n, T f) {
    for (int d = 1; d < n; d *= 2)
        for (int i = 0, t = d * 2; i < n; i += t)
            for(int j = 0; j < d; j++)
                f(a[i + j], a[i + j + d]);
}

void OR(ll& a, ll& b) { b += a; }
void rOR(ll& a, ll& b) { b -= a; }

struct node{
	ll l,r;mutable int val;
	bool operator<(const node& a)const{
		return r<a.r;
	}
};
set<node> st;
set<node>::iterator split(ll p)
{
	auto it=st.lower_bound({p,p,0});
	if(it->l==p) return it;
	int l=it->l,r=it->r,val=it->val;
	st.erase(it);
	st.insert({l,p-1,val});
	return st.insert({p,r,val}).first;
}
int query(ll p)
{
	auto it=st.lower_bound({p,p,0});
	return it->val;
}
void update(ll l,ll r)
{
	auto L=split(l),R=split(r+1);
	bool ok=1;
	int pre=-1;
	while(L!=R)
	{
		L->val = sqrt(L->val);
		if(pre!=-1&&L->val!=pre) ok=0; 
		pre=L->val;
		L++;
	}
	if(ok)
	{
		L=split(l);
		st.erase(L,R);
		st.insert({l,r,pre});
	}
}
int len;
void solve()
{
	ll cur=0;
	for(int i=0;i<len;i++)
	{
		if(!A[i]) continue;
		st.insert({cur+1,cur+A[i],i});
		cur+=A[i];
	}
	int m;
	scanf("%d",&m);
	while(m--)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		if(!l) printf("%d\n",query(r));
		else{
			update(l,r);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1,tmp;i<=n;i++)
	{
		scanf("%d",&tmp);
		A[tmp]++;
	}
	for(int i=1,tmp;i<=n;i++)
	{
		scanf("%d",&tmp);
		B[tmp]++;
	}
	len=1;
	while(len<=100000) len<<=1;
	fwt(A,len,OR);
	fwt(B,len,OR);
	for(int i=0;i<len;i++) A[i]=A[i]*B[i];
	fwt(A,len,rOR);
	solve();
}
