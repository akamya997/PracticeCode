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
const int maxn=1005;
struct seg{
	int l,r,tp;
	bool operator<(const seg a)const{
		if(l==a.l) return r<a.r;
		return l<a.l;
	}
};
vector<seg> t[2],tot;
int ans[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int tp,l,r;
		scanf("%d%d%d",&tp,&l,&r);
		t[tp].push_back(seg{l,r,tp});
		if(!tp)
			tot.push_back(seg{l,r,0});
	}
	sort(t[0].begin(),t[0].end());
	sort(t[1].begin(),t[1].end());
	bool ok=1;
	int L=0,R=0;
	int cur=10000000;
	for(int i=0;i<t[1].size();i++)
	{
		if(t[1][i].l<=R)
			R=max(R,t[1][i].r);
		else {
			if(L) tot.push_back(seg{L,R,1});
			L=t[1][i].l;
			R=t[1][i].r;
		}
		if(t[1].size()-1==i)
		{
	//		dbg(233,L,R);
			seg cur={L,R,1};
			if(!tot.size()||(tot.size()&&(cur.l!=tot[tot.size()-1].l||cur.r!=tot[tot.size()-1].r)))
				tot.push_back(cur);
		}
	}
	sort(tot.begin(),tot.end());
	L=0,R=0;
	for(int i=0;i<tot.size();i++)
	{
	//	dbg(tot[i].l,tot[i].r,tot[i].tp);
		if(tot[i].tp)
		{
			L=tot[i].l,R=tot[i].r;
			int tmp=cur;
			for(int j=L;j<=R;j++)
				ans[j]=++tmp;
		}
		else{
			if(tot[i].r<=R) 
			{
				ok=0;
				break;
			}
			int st=max(tot[i].l,R+1);
			for(int j=st;j<=tot[i].r;j++)
				ans[j]=--cur;
		}
		cur-=1000;
	}
	if(ok)
	{
		puts("YES");
		for(int i=1;i<=n;i++)
			printf("%d%c",ans[i],i==n?'\n':' ');
	}
	else{
		puts("NO");
	}

	


}
