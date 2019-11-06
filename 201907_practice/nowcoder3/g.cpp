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
const int maxn=3e5+7;
ll arr[maxn];
ll pre[maxn];
int fa[maxn];
int lc[maxn];
int rc[maxn];
ll solve(int L,int R,int root)
{
	if(L>=R) return 0;
	ll ret=0;
	if(root-L<R-root)
	{
		for(int i=L-1;i<=root-1;i++)
		{
			int l=root,r=R,ans=-1;
			while(l<=r)
			{
				int mid=l+r>>1;
				if((pre[mid]-pre[i])/2>=arr[root])
					r=mid-1,ans=mid;
				else l=mid+1;
			}
			if(ans!=-1)
			{
				if(ans-i>=2)
					ret+=R-ans+1;
				else ret+=(R-ans);
			}
		}
	}
	else{
		for(int i=root;i<=R;i++)
		{
			int l=L-1,r=root-1,ans=-1;
			while(l<=r)
			{
				int mid=l+r>>1;
				if((pre[i]-pre[mid])/2>=arr[root])
					l=mid+1,ans=mid;
				else r=mid-1;
			}
	//		dbg(i,ans);
			if(ans!=-1)
			{
				if(i-ans>=2)
					ret+=ans-L+2;
				else ret+=ans-L+1;
			}
		}
	}
	//dbg(L,R,root,ret);
	return ret+solve(L,root-1,lc[root])+solve(root+1,R,rc[root]);
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>arr[i];
		for(int i=1;i<=n;i++) fa[i]=0;
		for(int i=1;i<=n;i++) pre[i]=pre[i-1]+arr[i];
		stack<int> st;
		for (int i = 1; i <= n; i++)
		{
			int last = -1;
			while (!st.empty() && arr[i] > arr[st.top()])
				last = st.top(), st.pop();
			if (!st.empty())
				rc[st.top()] = i, fa[i] = st.top();
			lc[i] = last;
			if (~last)
				fa[last] = i;
			st.push(i);
		}
		int root = -1;
		for (int i = 1; i <= n; i++)
			if (!fa[i])
				root = i;
		cout<<solve(1,n,root)<<endl;
	}
}
