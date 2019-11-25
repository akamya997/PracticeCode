#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
typedef pair<int,int> PII;
int a[305],b[305];
int main()
{
	int T,kas=0;
	set<PII> ans;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&a[i],&b[i]);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				int cura=a[i]-a[j],curb=b[i]-b[j];
				if(1LL*cura*curb<0)
				{
					cura=abs(cura),curb=abs(curb);
					int gcd=__gcd(cura,curb);
					cura/=gcd,curb/=gcd;
					ans.insert(make_pair(cura,curb));
				}
			}
		}
		printf("Case #%d: %d\n",++kas,(int)ans.size()+1);
	}
}
