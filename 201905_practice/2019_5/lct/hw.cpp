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
int ans[10];
int Hash(int x)
{
	return x%7;
}
int main()
{
	vector<int> a={9,1,23,14,55,20,84,27};
	vector<int> d;
	for(int i=1;i<10000;i++) d.push_back(i*i);
	for(auto p:a)
	{
		if(!ans[Hash(p)]) ans[Hash(p)]=p;
		else{
			for(int i=0;i<d.size();i++)
			{
				if(!ans[(Hash(p)+d[i])%10]) {ans[(Hash(p)+d[i])%10]=p;dbg(p,i);break;}
			}
		}
	}
	for(int i=0;i<10;i++) cout<<ans[i]<<" ";
	cout<<endl;

}
