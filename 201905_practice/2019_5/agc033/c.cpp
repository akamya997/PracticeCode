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
const int maxn=2e5+7;
vector<int> G[maxn];
typedef pair<int,int> PII;
PII dfs(int u,int fa=-1)
{
	PII ret={u,0};
	for(auto v:G[u])
	{
		if(v==fa) continue;
		PII tmp=dfs(v,u);
		tmp.second++;
		if(tmp.second>ret.second) ret=tmp;
	}
	return ret;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	auto v=dfs(1);
	auto ans=dfs(v.first);
	if(ans.second%3==1) cout<<"Second"<<endl;
	else cout<<"First"<<endl;
}
