#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e3+7;
ll dp[maxn][maxn];
ll C[maxn][maxn];
ll fac[maxn];
ll inv[maxn][maxn];
ll ivv[maxn];
int n,a,b,c,d;
ll dfs(int cnt,int k)
{
	if(cnt==n) return 1;
	if(k>b) return cnt==n;
	ll &ret=dp[cnt][k];
	if(ret!=-1) return ret;
	ret=0;
	ret=dfs(cnt,k+1);
	for(int i=c;i*k+cnt<=n&&i<=d;i++)
	{
		ret=(ret+dfs(cnt+i*k,k+1)*C[n-cnt][i*k]%mod*fac[i*k]%mod*inv[k][i]%mod*ivv[i]%mod)%mod;
	}
	//dbg(cnt,k,ret);
	return ret;
}
ll invv(ll a,ll b=mod-2)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
int main()
{
	fac[0]=1;
	for(int i=0;i<maxn;i++)
	{
		if(i) fac[i]=fac[i-1]*i%mod;
		C[i][i]=C[i][0]=1;
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	for(int i=1;i<maxn;i++)
	{
		inv[i][0]=1;
		ll tmp=invv(fac[i]);
		ivv[i]=tmp;
		for(int j=1;j<maxn;j++)
			inv[i][j]=inv[i][j-1]*tmp%mod;
	}
	memset(dp,-1,sizeof(dp));
	cin>>n>>a>>b>>c>>d;
	cout<<dfs(0,a)<<endl;
}
