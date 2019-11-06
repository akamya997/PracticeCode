#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll dp[1005][1005];
int main()
{
	int T;
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		int n,c;
		cin>>n>>c;
		dp[0][0]=c;
		for(int i=1;i<=n;i++)
		{
			ll A,B,C;
			cin>>A>>B>>C;
			for(int j=0;j<=i;j++)
			{
				if(!dp[i-1][j]) continue;
				ll ac=min(dp[i-1][j],B)-A+C;
				if(min(dp[i-1][j],B)-A<=0) ac=0;
				dp[i][j]=max(dp[i-1][j]+C,dp[i][j]);
				if(ac>0)
					dp[i][j+1]=ac;
			}
		}
		int ans=0;
		for(int i=0;i<=n;i++) if(dp[n][i]) ans=i;
		cout<<ans<<endl;
	}
}
