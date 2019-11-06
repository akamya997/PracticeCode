#include <iostream>
#include <map>
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
map<ll,int> sg;
const ll maxn=4294967295LL;

ll n;
bool dfs(ll cur)
{
	if(cur>=n) return 0;
	if(sg.count(cur)) return sg[cur];
	bool win=0;
	for(int i=2;i<=9;i++)
		if(dfs(cur*i)==0) {win=1;break;}
	return sg[cur]=win;
}
int main()
{
	while(cin>>n)
	{
		sg.clear();
		if(dfs(1))
			cout<<"Stan wins."<<endl;
		else cout<<"Ollie wins."<<endl;
	}

}
