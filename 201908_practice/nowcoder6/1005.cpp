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
const int maxn=40500;
struct node{
	vector<int> cf;
	vector<int> pre;
	bool operator<(const node &a)const{
		return cf<a.cf;
	}
};
vector<node> ans[10];
inline void db()
{
	vector<int> tot;
	for(int i=2;i<=9;i++)
	{
		vector<int> cur;
		for(int j=1;j<=i;j++)
			cur.push_back(j);
		do{
			static vector<int> cf;
			cf.clear();
			for(int j=1;j<cur.size();j++)
				cf.push_back(cur[j]-cur[j-1]);
			ans[i].push_back({cf,cur});
		}while(next_permutation(cur.begin(),cur.end()));
		sort(ans[i].begin(),ans[i].end());
	}
}
int main()
{
	db();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        static vector<int> all;
		all.clear();
        int cnt=0;
		if(n<=9)
			all=ans[n][k-1].pre;
		else{
			vector<node> cur;
			vector<int> u;
			for(int i=n-9;i<n;i++)
				u.push_back(i);
			static vector<int> cf;
			do{
				cf.clear();
				if(u[0]!=n-9) break;
				for(int i=1;i<u.size();i++)
					cf.push_back(u[i]-u[i-1]);
				cur.push_back({cf,u});
			}while(next_permutation(u.begin(),u.end()));
			sort(cur.begin(),cur.end());
			all.push_back(n);
			for(int i=1;i<n-9;i++)
				all.push_back(i);
			for(auto v:cur[k-1].pre)
				all.push_back(v);
		}
		for(int i=0;i<n;i++)
        	printf("%d%c",all[i],i==n-1?'\n':' ');
    }
}
