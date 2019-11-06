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
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const int maxn=2e5+7;
ull a[maxn],b[maxn];
struct node{
	int ca,cb;
	bool operator<(const node& a)const{
		return ca+cb>a.ca+a.cb;
	}
};
unsigned long long k1, k2;
inline unsigned long long rng() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}
int mod;
vector<ull> all;
inline int getid(ull x)
{
    return lower_bound(all.begin(),all.end(),x)-all.begin();
}
int cnta[maxn],cntb[maxn];
int main()
{
    int T;
	scanf("%d",&T);
    while(T--)
    {
        all.clear();
        int n,m,p;
		scanf("%d%d%d",&n,&m,&p);
        if(p==1)
        {
            for(int i=0;i<n;i++)
            {
				scanf("%llu",&a[i]);
                all.push_back(a[i]);
            }
            for(int i=0;i<m;i++)
            {
				scanf("%llu",&b[i]);
                all.push_back(b[i]);
            }

        }
        else{
			scanf("%llu%llu%d",&k1,&k2,&mod);
            for (int i = 0; i < n; ++i)
            {
                a[i] = rng() % mod;
                all.push_back(a[i]);
            }
			scanf("%llu%llu%d",&k1,&k2,&mod);
            for (int i = 0; i < m; ++i)
            {
                b[i] = rng() % mod;
                all.push_back(b[i]);
            }
        }
        sort(all.begin(),all.end());
        all.erase(unique(all.begin(),all.end()),all.end());
        for(int i=0;i<=all.size();i++) cnta[i]=cntb[i]=0;
		for(int i=0;i<n;i++) 
		{
			a[i]=getid(a[i]);
			cnta[a[i]]++;
		}
		for(int i=0;i<m;i++) b[i]=getid(b[i]),cntb[b[i]]++;
		static vector<node> tot;
		tot.clear();
		int cangoa=0,cangob=0;
		for(int i=0;i<all.size();i++)
		{
			if(cnta[i]&&cntb[i])
				tot.push_back(node{cnta[i],cntb[i]});
			else if(cnta[i])
				cangoa+=cnta[i];
			else cangob+=cntb[i];
		}
		sort(tot.begin(),tot.end());
		int turn=0;
		for(auto& u:tot)
		{
			if(!turn)
				cangoa+=u.ca;
			else cangob+=u.cb;
			turn^=1;
		}
	//	if(turn) cangob--;
		if(cangoa>cangob) puts("Cuber QQ");
		else puts("Quber CC");

    }
}
