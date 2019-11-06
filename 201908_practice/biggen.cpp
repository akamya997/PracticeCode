#include <bits/stdc++.h>
#include "testlib.h"
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
bool vis[1005][1005];
int main(int argc,char* argv[])
{
	registerGen(argc,argv,1);
	int n,m;
	int point=1000;
	int kase=atoi(argv[1]);
	int T=10;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		startTest(kase++);
		n=rnd.next(2,point);
		int t = 0;
		printf("%d\n",n);
		int bianshu=n-1;
    	vector<int> p(n);
    	for(int i=0;i<n;i++)
        	if (i > 0)
            	p[i] = rnd.wnext(i, t);
    	vector<int> perm(n);
    	for(int i=0;i<n;i++)
        	perm[i] = i;
    	shuffle(perm.begin() + 1, perm.end());
    	vector<pair<int,int> > edges;
		vector<pair<int,int> > can;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				can.push_back(make_pair(i,j));
		}
		shuffle(can.begin(),can.end());
    	for (int i = 1; i < n; i++)
		{
			if (rnd.next(2))
            	edges.push_back(make_pair(perm[i], perm[p[i]]));
        	else
            	edges.push_back(make_pair(perm[p[i]], perm[i]));
			vis[perm[i]][perm[p[i]]]=1;
			vis[perm[p[i]]][perm[i]]=1;
		}
		int cur=0;

    	shuffle(edges.begin(), edges.end());

    	for (int i = 0; i <bianshu; i++)
        	printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
	}
}



