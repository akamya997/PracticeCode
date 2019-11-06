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
const int maxn=505;
int maze[maxn][maxn];
int qmax[maxn],qmin[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>maze[i][j];
		int ans=0;
		int amax[maxn],amin[maxn];
		for(int l=0;l<n;l++)
		{
			for(int r=l;r<n;r++)
			{
				for(int i=0;i<n;i++)
				{
					if(l==r) amax[i]=maze[l][i],amin[i]=maze[l][i];
					else amax[i]=max(amax[i],maze[r][i]),amin[i]=min(amin[i],maze[r][i]);
				}
				int mxhead=0,mxtail=0;
				int mihead=0,mitail=0;
				int j=0,k=0;
				while(k<n)
				{
					while(mxhead!=mxtail&&amax[qmax[mxtail]]<=amax[k])
						mxtail--;
					qmax[++mxtail]=k;
					while(mihead!=mitail&&amin[qmin[mitail]]>=amin[k])
						mitail--;
					qmin[++mitail]=k;
					k++;
					while(j<k&&amax[qmax[mxhead+1]]-amin[qmin[mihead+1]]>m)
					{
						if(qmax[mxhead+1]==j) mxhead++;
						if(qmin[mihead+1]==j) mihead++;
						j++;
					}
	//				dbg(l,r,j,k,qmax[mxhead+1],qmin[mihead+1]);
					ans=max(ans,(r-l+1)*(k-j));
				}
			}
		}
		cout<<ans<<endl;
	}

}
